#include "Computer.h"
#include <iostream>

Computer::Computer(std::string name, int hp, Ability* abilities[MAX_ABILITIES]) : Character(name, hp, abilities)
{
    //ctor
}

void Computer::chooseAbility(Character* other)
{
    abilities_[0]->useAbility(this, other);
    std::cout << "Computer uses " << abilities_[0]->getName() << std::endl;
}

Computer::~Computer()
{
    //dtor
}
