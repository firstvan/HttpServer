#pragma once
#include <string>
#include <QFile>
#include <fstream>
#include <sstream>
#include <QImage>
#include <QBuffer>
#include <vector>
#include <QUrl>
#include <QTextStream>

#include "template.h"

class Parser
{
public:
    Parser();

    static std::string parseHtml(std::string filename);

    static std::string parseJavaScript(std::string filename);

    static std::string parseCSS(std::string filename);

    static std::string parseStringFiles(std::string filename);

    static bool parseImage(std::string &filename, QByteArray &image);

    static std::string OK(std::string filename, Template* t);
};

