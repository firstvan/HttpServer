#include "../include/htmlroute.h"

HtmlRoute::HtmlRoute()
{
}

bool HtmlRoute::Register(std::string path, ServeFunction function)
{
    this->_wayToMethod.insert(std::make_pair(path, (ServeFunction) function));

    return true;
}

ServeFunction HtmlRoute::GetFunction(std::string path)
{
    return this->_wayToMethod[path];
}
