#ifndef ABILITY_H
#define ABILITY_H

#include <string>
//#include "Character.h"

//Forward declaration due to circular dependency
class Character;

class Ability
{
    public:
        Ability(std::string name, int value);
        int getValue() const;
        std::string getName() const;
        virtual ~Ability();
        virtual void useAbility(Character* user, Character* other) = 0;

    protected:

    private:
        std::string name_;
        int value_;
};

#endif // ABILITY_H
