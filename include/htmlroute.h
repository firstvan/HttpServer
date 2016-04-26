#pragma once

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <QFile>
#include <exception>

#include <iostream>
#include "dog.h"

typedef std::string (*ServeFunction)(void);

class HtmlRoute
{
public:
    HtmlRoute();

    bool Register(std::string path, ServeFunction function);


    ServeFunction GetFunction(std::string path);

private:
    std::map<std::string, ServeFunction> _wayToMethod;

};

