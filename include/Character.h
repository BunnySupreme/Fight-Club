#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "Ability.h"
//#include "Punch.h"
#include "Config.h"

//Forward declaration due to circular dependency


class Character
{
    public:
        Character(std::string name, int hp, Ability* abilities[MAX_ABILITIES]);
        std::string getName() const;
        int getHp() const;
        void loseHp(int value);
        void gainHp(int value);
        virtual void chooseAbility(Character* other) = 0;
        virtual ~Character();

    protected:
        Ability* abilities_[max_abilities];
    private:
        std::string name_;
        int hp_;
        const int max_abilities = 2;
        bool valueOk(int value);
};

#endif // CHARACTER_H
