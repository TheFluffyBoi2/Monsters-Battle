#include <iostream>
#include "monster.h"

using namespace std;

class Attacks{
private:
    const string numeAtk1 = "Soft attack (100%)", numeAtk2 = "Hard attack (75%)", numeAtk3 = "Status attack (50%)";
    const unsigned int chanceAtk1 = 100, chanceAtk2 = 75, chanceAtk3 = 50;
public:
    bool crit();
    bool status(Monster x);
    int damage(Monster x, Attacks y, unsigned int atk);
    int calculDamage(Monster x, int multiplier);
    bool sansaHit(int chance);
    void statusEffect(Monster &x);
    void applyDamage(int damage, Monster &x);

    string getAtk1();
    string getAtk2();
    string getAtk3();

    unsigned int getChance1();
    unsigned int getChance2();
    unsigned int getChance3();
};