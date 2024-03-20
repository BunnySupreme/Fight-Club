#include "Player.h"
#include <iostream>

Player::Player(std::string name, int hp, Ability* abilities[MAX_ABILITIES]) : Character(name, hp, abilities)
{
    //ctor
}

void Player::chooseAbility(Character* other)
{
    int input = 0;
    std::cout << "\nChoose your ability: \n";

    int i = 0;
    for (const Ability* tmp : abilities_)
    {
        std::cout << tmp->getName() << "[" << i <<"]" << std::endl;
        i++;
    }
    do
    {
        std::cin >> input;
        if (input > HIGHEST_INPUT_OPTION || input < LOWEST_INPUT_OPTION)
        {
            std::cout << "\nTry again\n";
        }

    }while (input > HIGHEST_INPUT_OPTION || input < LOWEST_INPUT_OPTION);
    abilities_[input]->useAbility(this, other);

}

Player::~Player()
{
    //dtor
}
