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
    Character* player = new Character();
    std::string name = player->read();
    player->init(name);
    player->display();
    delete player;

    //Массив объектов
    Character* players = new Character[PLAYERS_COUNT];
    for (int i = 0; i < PLAYERS_COUNT; i++)
    {
        players[i].init();
    }
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
        playersList[i] = new Character();
        playersList[i]->init();
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
        playersList2[i]->init();
        playersList2[i]->display();
    }

    for (int i = 0; i < playersList2.size(); i++)
    {
        delete playersList2[i];
    }
    playersList2.clear();

}