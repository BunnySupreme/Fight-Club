#include "Game.h"
#include "Punch.h"
#include "Heal.h"
#include "RiskyPunch.h"
#include "Player.h"
#include "Computer.h"
#include <iostream>
#include <limits>


Game::Game()
{
    //ctor
    available_abilities_[PUNCH] = new Punch(PUNCH_DAMAGE);
    available_abilities_[HEAL] = new Heal(HEAL_VALUE);
    available_abilities_[RISKY_PUNCH] = new RiskyPunch(RISKY_PUNCH_VALUE);
}

void Game::runGame()
{
    while(1)
    {
        chooseCharacter();
        executeFight();
        printStats();
    }
}

void Game::chooseCharacter()
{

    int input = 0;
    int roundOfChoosing = ROUND_TO_CHOOSE_YOUR_CHARACTER;
    do
    {
        while (1)
        {
            if (roundOfChoosing == ROUND_TO_CHOOSE_YOUR_CHARACTER)
            {
                std::cout << "Choose your character: \n";
            }
            else
            {
                std::cout << "Choose the Computer's character: \n";
            }
            std::cout << "NormalGuy[0] or RiskyGuy[1] or make own Character[2]\n";
            std::cin >> input;
            if (input > CHOOSING_CHARACTER_HIGHEST_INPUT_OPTION || input < CHOOSING_CHARACTER_LOWEST_INPUT_OPTION)
            {
                std::cout << "Invalid input! Try again \n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                break;
            }
        }

        Ability* pre_made_abilities[MAX_ABILITIES];
        switch(input)
        {
        case(INPUT_ZERO):
            pre_made_abilities[0] = available_abilities_[PUNCH];
            pre_made_abilities[1] = available_abilities_[HEAL];
            if (roundOfChoosing == ROUND_TO_CHOOSE_YOUR_CHARACTER)
            {
                chosen_characters_[YOUR_CHARACTER_INDEX] = new Player("NormalGuy", 3, pre_made_abilities);
            }
            else
            {
                chosen_characters_[COMPUTER_CHARACTER_INDEX] = new Computer("NormalGuy", 3, pre_made_abilities);
            }
            break;
        case(INPUT_ONE):
            pre_made_abilities[0] = available_abilities_[PUNCH];
            pre_made_abilities[1] = available_abilities_[RISKY_PUNCH];
            if (roundOfChoosing == ROUND_TO_CHOOSE_YOUR_CHARACTER)
            {
                chosen_characters_[YOUR_CHARACTER_INDEX] = new Player("RiskyGuy", 5, pre_made_abilities);
            }
            else
            {
                chosen_characters_[COMPUTER_CHARACTER_INDEX] = new Computer("RiskyGuy", 5, pre_made_abilities);
            }
            break;
        case(INPUT_TWO):
            std::cout << "Choose name: \n";
            std::string name;
            std::cin >> name;
            std::cout << "Choose health: \n";
            int health = 0;
            std::cin >> health;
            int i = 0;
            std::cout <<"Choose abilities: \n";
            for (Ability* tmp : available_abilities_)
            {
                std::cout << tmp->getName() << "[" << i <<"]" << std::endl;
                i++;
            }
            i = 0;
            int input = 0;
            std::cout << "Input your choices\n";
            for (int j = 0; j < MAX_ABILITIES; j++)
            {
                while(1)
                {
                    std::cin >> input;
                    if (input < CHOOSING_CHARACTER_LOWEST_INPUT_OPTION || input > CHOOSING_CHARACTER_HIGHEST_INPUT_OPTION)
                    {
                        std::cout << "\nInvalid input! Try again\n";
                    }
                    else
                    {
                        std::cout << "\nInput ok!\n";
                        break;
                    }
                }
                pre_made_abilities[j] = available_abilities_[input];
            }
            if (roundOfChoosing == ROUND_TO_CHOOSE_YOUR_CHARACTER)
            {
                chosen_characters_[YOUR_CHARACTER_INDEX] = new Player(name, health, pre_made_abilities);
            }
            else
            {
                chosen_characters_[COMPUTER_CHARACTER_INDEX] = new Computer(name, health, pre_made_abilities);
            }


        }

        roundOfChoosing++;
    }while (roundOfChoosing < CHOOSING_OVER);
}

void Game::executeFight()
{
    int round = PLAYER;
    int waiting_its_turn = COMPUTER;
    while(1)
    {
        std::cout << "Player health: " << chosen_characters_[PLAYER]->getHp() << std::endl;
        std::cout << "Computer health: " << chosen_characters_[COMPUTER]->getHp() << std::endl;
        Character* other = chosen_characters_[waiting_its_turn];
        chosen_characters_[round]->chooseAbility(other);
        if (chosen_characters_[PLAYER]->getHp() <= 0)
        {
           gainLoss();
            std::cout << "\nFight over!\n";
            break;
        }
        if (chosen_characters_[COMPUTER]->getHp() <= 0)
        {
            gainWin();
            std::cout << "\nFight over!\n";
            break;

        }
        if (round == PLAYER)
        {
            round = COMPUTER;
            waiting_its_turn = PLAYER;
        }
        else
        {
            round = PLAYER;
            waiting_its_turn = COMPUTER;
        }
    }
}

void Game::gainWin()
{
    wins++;
}

void Game::gainLoss()
{
    losses++;
}
void Game::printStats()
{
    std::cout << "\nWins: " << wins << std::endl;
    std::cout << "\nLosses: " << losses << std::endl;
}

Game::~Game()
{
    for (const Ability* tmp : available_abilities_)
    {
        delete tmp;
    }


    for (const Character* tmp : chosen_characters_)
    {
        delete tmp;
    }



    //dtor
}
