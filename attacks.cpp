#include <iostream>
#include "attacks.h"
#include <ctime>

using namespace std;

bool Attacks::crit() {
    //calculeaza sansa ca orice atacc sa fie dea damage dublu
    int chance;
    srand(time(NULL));
    chance = rand() % 100;
    if (chance <= 5)
    {
        cout << "CRITICAL HIT!" << endl;
        return 1;
    }
    else
        return 0;
}

bool Attacks::status(Monster x) {
    //verifica statusul unui monstru
    string status;
    int chance;
    status = x.getStatus();
    if (status != "None")
        return true;
    else
        return false;
}

bool Attacks::sansaHit(int chance)
{
    //calculeaza sansa ca un atac sa aplice damage-ul
    int randnr;
    srand(time(NULL));
    randnr = rand()%100;
    if (chance >= randnr)
        return true;
    else{
        cout << "MISS!" << endl;
        return false;
    }
}

void Attacks::statusEffect(Monster &x)
{
    //aplica statusul
    if (x.getStatus() == "None")
    {
        x.setStatus("True");
    }
}

int Attacks::calculDamage(Monster x, int multiplier)
{
    //aplica sansa de a rata daca un monstru are un status + sansa ca un atac sa aplice daune duble
    int chance;
    bool _status = status(x);
    int _attack = x.getAttack();
    if (_status){
        srand(time(NULL));
        chance = rand() % 100;
        if (chance <= 25)
            _attack = 0;
    }
    bool _crit = crit();
    _attack = _attack * multiplier;
    if (_crit)
        _attack = _attack * 2;
    return _attack;
}

int Attacks::damage(Monster x, Attacks y, unsigned int atk) {
    //returneaza daunele finale
    double finalattack = 0;
    int chanceHit;
    if (atk == 1)
    {
        chanceHit = y.getChance1();
        if (sansaHit(chanceHit) == 1)
            finalattack = calculDamage(x, 1);
    }
    if (atk == 2)
    {
        chanceHit = y.getChance2();
        if (sansaHit(chanceHit) == 1)
        finalattack = calculDamage(x, 2);
    }
    if (atk == 3)
    {
        chanceHit = y.getChance3();
        if (sansaHit(chanceHit) == 1)
        {
            finalattack = -1;
            statusEffect(x);
        }

    }
    return finalattack;
}

void Attacks::applyDamage(int damage, Monster &x) {
    //scade hp-ul in functie de damage-ul atacului
    int hp = x.getHp();
    x.setHp(hp - damage);
}

string Attacks::getAtk1() {
    return numeAtk1;
}

string Attacks::getAtk2() {
    return numeAtk2;
}

string Attacks::getAtk3() {
    return numeAtk3;
}

unsigned int Attacks::getChance1() {
    return chanceAtk1;
}

unsigned int Attacks::getChance2() {
    return chanceAtk2;
}

unsigned int Attacks::getChance3() {
    return chanceAtk3;
}