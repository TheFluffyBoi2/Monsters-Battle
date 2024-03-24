#include <iostream>
#include "enemy.h"
#include <vector>

using namespace std;

Enemy::Enemy():
    Entity("None", 3)
{
//    cout << "Inamic vid creat" << endl;
}

Enemy::Enemy(string _nume, unsigned int _nrMonsters):
    Entity(_nume, _nrMonsters)
{
//    cout << "Inamic cu numele " << name << " creat" << endl;
}

Enemy::~Enemy()
{
    // cout << "deconstructor";
}

vector<Monster>& Enemy::getVector() {
    return enemyMonsters;
}

void Enemy::createMonsters() {
    enemyMonsters.emplace_back("Hypoceros", "Attack", "None", 50, 100);
    enemyMonsters.emplace_back("Porcunite", "Defense", "None", 10, 350);
    enemyMonsters.emplace_back("Donkeon", "Balanced", "None", 25, 200);
}