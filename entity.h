#include <iostream>
#pragma once

using namespace std;

class Entity{
protected:
    string name;
    unsigned int nrMonsters;
public:
    Entity();
    ~Entity();
    Entity(string entityName, unsigned int entityNrMonsters);
    string getName();
    void setName(string entityName);
    int getNrMonsters();
    void setNrMonsters(unsigned int EntityNrMonsters);
};