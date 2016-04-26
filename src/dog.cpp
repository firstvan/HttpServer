#include "../include/dog.h"

Dog::Dog()
{
    this->name = "";
    this->age = 0;
    _tags.insert(std::make_pair("name", this->name));
    _tags.insert(std::make_pair("age", std::to_string(this->age)));
}

Dog::Dog(std::string name, int age)
{
    this->name = name;
    this->age = age;
    _tags.insert(std::make_pair("name", this->name));
    _tags.insert(std::make_pair("age", std::to_string(this->age)));
}

std::string Dog::GetName()
{
    return "Dog";
}

std::map<std::string, std::string>& Dog::GetTags()
{
    return _tags;
}
