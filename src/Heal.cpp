#include "Heal.h"
#include <iostream>

Heal::Heal(int value) : Ability("heal", value)
{
    //ctor
}

void Heal::useAbility(Character* user, Character* other)
{
    std::cout << "\nHeal!\n";
    user->gainHp(getValue());
}

Heal::~Heal()
{
    //dtor
}
