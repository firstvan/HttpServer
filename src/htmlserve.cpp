#include "../include/htmlserve.h"

HtmlServe::HtmlServe()
{

}

std::string HtmlServe::index()
{
   return Parser::parseHtml("index.html");
}

std::string HtmlServe::second()
{
   return Parser::parseHtml("second.html");
}

std::string HtmlServe::dogs()
{
    Dog* dog = new Dog("Bodri", 5);
    return Parser::OK("dogs.html", dog);
}
