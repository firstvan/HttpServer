#pragma once

#include <string>
#include "htmlparser.h"
#include "dog.h"

class HtmlServe
{
public:
    HtmlServe();

    static std::string index();
    static std::string second();
    static std::string dogs();
};

