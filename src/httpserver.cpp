#include "httpserver.h"

HttpServer::HttpServer(HtmlRoute &route)
{
    this->_address = QHostAddress::LocalHost;
    this->_port = 1111;
    this->init();
    this->route = route;
}

HttpServer::HttpServer(std::string address, int port, HtmlRoute &route)
{
    this->_address = QHostAddress(address.c_str());
    this->_port = port;
    this->init();
    this->route = route;
}

void HttpServer::init()
{
    _tcpServer = std::shared_ptr<QTcpServer>(new QTcpServer());

    connect(_tcpServer.get(), SIGNAL(newConnection()), this, SLOT(newConnection()));

    _tcpServer->listen(this->_address, (quint16) this->_port);
}

bool HttpServer::isListening()
{
    return _tcpServer->isListening();
}

void HttpServer::newConnection()
{
    auto socket =_tcpServer->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void HttpServer::readyRead()
{
    auto socket = static_cast<QTcpSocket*>(sender());

    std::string income = socket->readLine().toStdString();

    std::vector<std::string> lineparams;

    this->split(income, ' ', lineparams);

    std::stringstream resp;

    if(lineparams.at(1).find(".ico") != std::string::npos ||
            lineparams.at(1).find(".jpeg") != std::string::npos)
    {
        QByteArray img;
        Parser::parseImage(lineparams.at(1), img);
        resp = this->getHeader(HTTP_OK, IMAGE_JPEG, img.size());
        this->sendRespWithData(socket, resp.str(), img);
    }
    else if(lineparams.at(1).find(".js") != std::string::npos)
    {
        auto content = Parser::parseJavaScript(lineparams.at(1));
        resp = this->getHeader(HTTP_OK, TEXT_JAVASCRIPT, content.size());
        resp << content;
        this->sendResp(socket, resp.str());
    }
    else if(lineparams.at(1).find("css") != std::string::npos)
    {
        auto content = Parser::parseCSS(lineparams.at(1));
        resp = this->getHeader(HTTP_OK, TEXT_CSS, content.size());
        resp << content;
        this->sendResp(socket, resp.str());
    }
    else
    {
        std::string name = lineparams.at(1);

        auto content = route.GetFunction(name)();

        resp = this->getHeader(HTTP_OK, TEXT_HTML, content.size());
        resp << content;
        this->sendResp(socket, resp.str());
    }


}

std::stringstream HttpServer::getHeader(std::string statusCode, std::string type, int length)
{
    std::stringstream header;
    header << "HTTP/1.1 " << statusCode << "\r\n";
    header << "Content-Type: " << type << "; charset=UTF-8\r\n";
    header << "Content-Length: " << length << "\r\n";
    header << "Connection: Keep-Alive\r\n";
    header << "\r\n";

    return header;
}

void HttpServer::sendResp(QTcpSocket* socket, const std::string &resp)
{
    socket->write(resp.c_str());
    socket->flush();
    socket->waitForBytesWritten(resp.size());
    socket->close();
}

void HttpServer::sendRespWithData(QTcpSocket* socket, const std::string &resp, const QByteArray &data)
{
    socket->write(resp.c_str());
    socket->write(data);
    socket->flush();
    socket->waitForBytesWritten(resp.size() + data.size());
    socket->close();
}

std::vector<std::string>& HttpServer::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
