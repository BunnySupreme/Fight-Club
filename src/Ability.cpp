#include "Ability.h"

Ability::Ability(std::string name, int value) : name_(name), value_(value)
{
    //ctor
}

int Ability::getValue() const{
    return value_;
}

std::string Ability::getName() const
{
    return name_;
}

Ability::~Ability()
{
    //dtor
}
