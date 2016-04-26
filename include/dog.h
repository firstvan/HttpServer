#pragma once
#include "template.h"

class Dog : public Template
{
public:
    Dog();

    Dog(std::string name, int age);

    std::string GetName();

    std::map<std::string, std::string>& GetTags();

    std::string name;

    int age;
private:
    std::map<std::string, std::string> _tags;
};

