#include "Character.h"
#include <iostream>


Character::Character(std::string name, int hp, Ability* abilities[MAX_ABILITIES]) : name_(name), hp_(hp)
{

    for (int i = 0; i < MAX_ABILITIES; i++)
    {
        abilities_[i] = abilities[i];
    }
    //ctor
}

std::string Character::getName() const
{
    return name_;
}

int Character::getHp() const
{
    return hp_;
}

void Character::loseHp(int value)
{
    if (!valueOk(value))
    {
        return;
    }
    hp_-=value;
    if (hp_ < 0)
    {
        hp_ = 0;
    }
}

void Character::gainHp(int value)
{
    hp_+=value;
}

Character::~Character()
{
    //dtor
}

bool Character::valueOk(int value)
{
    if (value > 0)
    {
        return true;
    }
    else
    {
        std::cout << "\nIssue in Character function! Given Value below/at 0";
        return false;
    }
}
