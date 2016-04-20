#include "htmlserve.h"

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
