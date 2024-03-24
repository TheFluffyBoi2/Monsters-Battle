#include <iostream>
#include "entity.h"
#include "monster.h"
#include <vector>
#pragma once

class Enemy : public Entity {
private:
    vector<Monster> enemyMonsters;
public:
    Enemy();
    ~Enemy();
    Enemy(string _nume, unsigned int _nrMonsters);
    vector<Monster>& getVector();
    void createMonsters();
};