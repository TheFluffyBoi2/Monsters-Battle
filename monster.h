#include <iostream>
#pragma once
using namespace std;

class Monster{
private:
    string name, type, status;
    unsigned int attack;
    int hp;
public:
    Monster();
    ~Monster();
    Monster(string monsterName, string monsterType, string monsterStatus, unsigned int monsterAttack, int monsterHp);
    Monster(const Monster &m);
    void setName(string monsterName);
    string getName();
    void setType(string monsterType);
    string getType();
    string getStatus();
    void setStatus(string monsterStatus);
    unsigned int getAttack();
    void setAttack(int monsterAttack);
    int getHp();
    void setHp(int monsterHp);

    friend ostream& operator<<(ostream &os, Monster &x);
    Monster& operator=(const Monster& m);
};