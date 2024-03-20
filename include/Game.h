#ifndef GAME_H
#define GAME_H

#include "Ability.h"
#include "Character.h"
#include "Config.h"


class Game
{
    public:
        Game();
        void runGame();
        ~Game();

    protected:

    private:
        void chooseCharacter();
        void gainLoss();
        void gainWin();
        Ability* available_abilities_[MAX_AVAILABLE_ABILITIES];
        //Character* premade_characters_[MAX_PREMADE_CHARACTERS];
        Character* chosen_characters_[MAX_CHOSEN_CHARACTERS];
        void printStats();
        int wins = 0;
        int losses = 0;
        //functions
        void executeFight();

};

#endif // GAME_H
