#include <iostream>
#include "monster.h"

using namespace std;

Monster::Monster():
    name("None"),
    type("None"),
    status("None"),
    attack(0),
    hp(0)
{
//    cout << "Monstru void creat" << endl;
}

Monster::Monster(std::string monsterName, std::string monsterType, std::string monsterStatus,
                 unsigned int monsterAttack, int monsterHp):
                    name(monsterName),
                    type(monsterType),
                    status(monsterStatus),
                    attack(monsterAttack),
                    hp(monsterHp)
                 {
//                    cout << "Monstru cu numele " << name << " creat" << endl;
                 }
Monster::Monster(const Monster &m):
    name(m.name),
    type(m.type),
    status(m.status),
    attack(m.attack),
    hp(m.hp)
{
// cout << "copy constructor";
}

void Monster::setName(string monsterName) {
    name = monsterName;
}

string Monster::getName() {
    return name;
}

string Monster::getStatus() {
    return status;
}

void Monster::setStatus(string monsterStatus) {
    status = monsterStatus;
}

int Monster::getHp() {
    return hp;
}

void Monster::setHp(int monsterHp) {
    hp = monsterHp;
}

void Monster::setType(string monsterType) {
    type = monsterType;
}

string Monster::getType() {
    return type;
}

unsigned int Monster::getAttack() {
    return attack;
}

void Monster::setAttack(int monsterAttack) {
    attack = monsterAttack;
}

ostream& operator<<(std::ostream &os, Monster &x) {
    os << "Hp: " << x.getHp() << "Attack: " << x.getAttack();
}

Monster& Monster::operator=(const Monster& m)
{
    name = m.name;
    type = m.type;
    status = m.status;
    attack = m.attack;
    hp = m.hp;
    return *this;
}

Monster::~Monster(){
//    cout << "Destructor";
}