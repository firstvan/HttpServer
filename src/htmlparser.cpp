#include "htmlparser.h"

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
