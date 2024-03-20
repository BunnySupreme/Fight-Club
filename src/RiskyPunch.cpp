#include "RiskyPunch.h"

RiskyPunch::RiskyPunch(int value) : Ability("risky punch", value)
{
    //ctor
}

void RiskyPunch::useAbility(Character* user, Character* other)
{
    user->gainHp(getValue());
    other->loseHp(getValue());
}

RiskyPunch::~RiskyPunch()
{
    //dtor
}
