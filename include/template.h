#pragma once

#include <string>
#include <map>

class Template{
public:
    Template(){}
    virtual ~Template(){}
    virtual std::string GetName()=0;

    virtual std::map<std::string, std::string>& GetTags()=0;
};
