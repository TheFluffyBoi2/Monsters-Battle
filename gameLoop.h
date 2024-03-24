#include <iostream>
#include "monster.h"
#include "player.h"
#include "enemy.h"
#pragma once
using namespace std;

class gameLoop{
private:
    bool UI(Monster &x, Monster &y, Player &z);
    bool playerMonsterDied(Player &player1);
    bool enemyMonsterDied(Enemy &enemy1);
    bool battle(int monstruAdvers, int monstruPlayer, Player &player1, Enemy &enemy1);
    int alegeMonstru(Player player1);
public:
    int start();
};