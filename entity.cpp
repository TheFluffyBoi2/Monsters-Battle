#include <iostream>
#include "entity.h"

using namespace std;

Entity::Entity():
    name("None"),
    nrMonsters(3)
{
//    cout << "Entitate vida creata";
}

Entity::Entity(string entityName, unsigned int entityNrMonsters):
    name(entityName),
    nrMonsters(entityNrMonsters)
{
//    cout << "Entitate cu numele " << name << " creata";
}

Entity::~Entity()
{
    // cout << "deconstructor";
}

void Entity::setName(string entityName) {
    name = entityName;
}

string Entity::getName() {
    return name;
}

int Entity::getNrMonsters() {
    return nrMonsters;
}

void Entity::setNrMonsters(unsigned int EntityNrMonsters) {
    nrMonsters = EntityNrMonsters;
}