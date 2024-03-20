#include "Punch.h"
#include <iostream>

Punch::Punch(int value):Ability("punch", value)
{
    //ctor
}

void Punch::useAbility(Character* user, Character* other)
{
    std::cout << "\nPunch!\n";
    other->loseHp(getValue());
}

Punch::~Punch()
{
    //dtor
}
