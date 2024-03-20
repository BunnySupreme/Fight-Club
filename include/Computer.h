#ifndef COMPUTER_H
#define COMPUTER_H
#include "Config.h"
#include "Character.h"

class Computer : public Character
{
    public:
        Computer(std::string name, int hp, Ability* abilities[MAX_ABILITIES]);
        void chooseAbility(Character* other) override;
        virtual ~Computer();

    protected:

    private:
};

#endif // COMPUTER_H
