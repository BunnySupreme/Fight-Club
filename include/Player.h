#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Config.h"

class Player : public Character
{
    public:
        Player(std::string name, int hp, Ability* abilities[MAX_ABILITIES]);
        void chooseAbility(Character* other) override;
        virtual ~Player();

    protected:

    private:
};

#endif // PLAYER_H
