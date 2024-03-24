#include <iostream>
#include "entity.h"
#include <vector>
#include "monster.h"
#pragma once

using namespace std;

class Player : public Entity{
private:
    unsigned int nrPotions;
    vector<Monster> playerMonsters;
public:
    Player();
    ~Player();
    Player(string _nume, unsigned int _nrMonsters, int _nrPotions);
    int getNrPotions();
    void setNrPotions(int PlayerNrPotions);
    void setMonsterName(Monster x);
    vector<Monster> &getVector();
    void createMonsters();
};