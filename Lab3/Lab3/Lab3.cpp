#define _CRT_SECURE_NO_WARNINGS
#include "Character.h"
#include <vector>
#include <ctime>
#include <iostream>

static const int PLAYERS_COUNT = 5;

int main()
{
    std::srand(std::time(0));

    //Динамический объект
    std::string name = Character::read();
    Character* player = new Character(name, "Human", 3, new Equipment(1, "Sword"), new Equipment(10, "Dagger"));
    player->display();
    ++(*player);
    player->display();
    (*player)++;
    player->display();
    reset_level(*player);
    player->display();
    player->get_left_hand()->set_damage(1000);
    player->get_right_hand().set_damage(-25);
    Character::display(player);
    std::cout << "Copy cZonstructor" << std::endl;
    Character* new_player = new Character(*player);
    
    Character::display(new_player);

    std::cout << "Player3" << std::endl;
    Character player3;
    player3 = *new_player;
    Character::display(&player3);

    //Массив объектов
    Character* players = new Character[PLAYERS_COUNT];
    for (int i = 0; i < PLAYERS_COUNT; i++)
    {
        players[i].display();
    }
    delete[] players;
    players = nullptr;

    // массив Динамических объектов
    Character* playersList[PLAYERS_COUNT];
    for (int i = 0; i < PLAYERS_COUNT; i++)
    {
        playersList[i] = new Character("Ivan " + std::to_string(i + 1));
        playersList[i]->display();
    }
    for (int i = 0; i < PLAYERS_COUNT; i++)
    {
       delete playersList[i];
    }

    //Динамический массив Динамических объектов
    std::vector<Character*> playersList2;
    for (int i = 0; i < 3; i++)
    {
        playersList2.push_back(new Character());
        playersList2[i]->display();
    }

    for (int i = 0; i < playersList2.size(); i++)
    {
        delete playersList2[i];
    }
    playersList2.clear();

    std::cout << "Characters created count: " << Character::get_counter();
}