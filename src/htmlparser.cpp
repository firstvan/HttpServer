#include "../include/htmlparser.h"

Parser::Parser()
{
}

/**
 * Parse a static html file.
 * @brief HtmlParser::parseHtml
 * @param filename name of html file
 * @return string representation of file
 */
std::string Parser::parseHtml(std::string filename)
{
    return Parser::parseStringFiles(":/view/" + filename);
}

/**
 * Parse JavaScript files.
 * @brief Parser::parseJavaScript
 * @param filename
 * @return
 */
std::string Parser::parseJavaScript(std::string filename)
{
    return Parser::parseStringFiles(":/Resources/javascript" + filename);
}

/**
 * Parse css files.
 * @brief Parser::parseCSS
 * @param filename
 * @return
 */
std::string Parser::parseCSS(std::string filename)
{
    return Parser::parseStringFiles(":/Resources/css" + filename);
}

/**
 *
 * @brief Parser::parseStringFiles
 * @param filename
 * @return
 */
std::string Parser::parseStringFiles(std::string filename)
{
    QFile file(QString::fromStdString(filename));
    if(!file.open(QIODevice::ReadOnly))
        return "";

    auto data = file.readAll();

    file.close();

    std::string content(data.constData(), data.length());

    return content;

}

/**
 * Process image
 * @brief Parser::parseImage
 * @param filename
 * @return String representation of image
 */
bool Parser::parseImage(std::string &filename, QByteArray &image)
{
    QImage img;
    img.load((":/Resources/images" + filename).c_str());

    QBuffer buffer(&image);
    img.save(&buffer, "JPG");

    return true;
}

std::string Parser::OK(std::string filename, Template* t)
{
    auto name = ":/view/" + filename;
    QFile file(QString::fromStdString(name));
    if(!file.open(QIODevice::ReadOnly))
        return "";

    std::stringstream ss;

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        int item = line.indexOf("@{");

        while( item != -1)
        {
            ss << line.left(item - 1).toStdString();
            line = line.remove(0, item - 1);
            auto brace = line.indexOf("}");

            auto variable = line.mid(3, brace - 3);

            line = line.remove(0, brace + 1);

            QStringList ls = variable.split('.');

            if(t->GetName() == ls.at(0).toStdString())
            {
                ss << t->GetTags()[ls.at(1).toStdString()];
            }

            item = line.indexOf("@{");
        }

        ss << line.toStdString();
    }

    file.close();

    return ss.str();
}
