#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <sstream>
#include <iostream>
#include <memory>
#include <vector>

#include "httpdefine.h"
#include "htmlparser.h"
#include "htmlroute.h"

class HttpServer : public QObject
{
    Q_OBJECT

public:
    HttpServer(HtmlRoute &route);

    HttpServer(std::string address, int port, HtmlRoute &route);

    bool isListening();

private:
    std::shared_ptr<QTcpServer> _tcpServer;
    QHostAddress _address;
    int _port;

    void init();

    std::stringstream getHeader(std::string statusCode, std::string type, int length);

    void sendResp(QTcpSocket* socket, const std::string &resp);
    void sendRespWithData(QTcpSocket* socket, const std::string &resp, const QByteArray& data);

    std::vector<std::string>& split(const std::string& s, char delim, std::vector<std::string> &elems);

    HtmlRoute route;

public slots:
    void newConnection();
    void readyRead();
};

