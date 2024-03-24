#include <iostream>
#include "gameLoop.h"
#include <ctime>
#include "player.h"
#include <vector>
#include "monster.h"
#include "entity.h"
#include "enemy.h"
#include "attacks.h"

using namespace std;

int gameLoop::alegeMonstru(Player player1)
{
    cout << endl;
    cout << "Alegeti un mosntru: ";
    cout << endl;
    //parcurgem vectorul pentru a afisa monstrii disponibili
    for (int i = 0; i < player1.getVector().size(); i++)
    {
        cout << player1.getVector()[i].getName() << "(Type: " << player1.getVector()[i].getType() << ", " << "Attack: " << player1.getVector()[i].getAttack() << ", " << "HP: " <<  player1.getVector()[i].getHp() << ')' << '(' << i << ')';
        cout << endl;
    }
    //returnam decizia
    cout << "Decizie: ";
    unsigned int decizie;
    cin >> decizie;
    return decizie;
}

bool gameLoop::enemyMonsterDied(Enemy &enemy1) {
    int hp;
    //parcurgem vectorul si eliminam monstrii cu hp-ul mai mic sau egal cu 0
    for (auto it = enemy1.getVector().begin(); it != enemy1.getVector().end(); it++)
    {
        hp = (*it).getHp();
        if (hp <= 0)
        {
            enemy1.getVector().erase(it);
            break;
        }
    }
    //in caz ca vectorul devine gol, incheiam meciul
    if (enemy1.getVector().empty())
    {
        cout << endl << "YOU WON!";
        return true;
    }
    return 0;
}

bool gameLoop::playerMonsterDied(Player &player1) {
    //acelasi lucru, doar ca pentru vectorul asociat jucatorului
    int hp;
    for (auto it = player1.getVector().begin(); it != player1.getVector().end(); it++)
    {
        hp = (*it).getHp();
        if (hp <= 0)
        {
            player1.getVector().erase(it);
            break;
        }
    }
    if (player1.getVector().empty())
    {
        cout << endl << "YOU LOST!";
        return true;
    }
    return 0;
}

bool gameLoop::battle(int monstruAdvers, int monstruPlayer, Player &player1, Enemy &enemy1) {
    //verificam care dintre monstrii activi ajunge primul la hp <= 0
    int outcome;
    outcome = UI(player1.getVector()[monstruPlayer], enemy1.getVector()[monstruAdvers], player1);
    cout << "-------------------------------------" << endl;
    if (outcome == true) //outcome-ul in care monstrul inamic moare
    {
        if (enemyMonsterDied(enemy1) == true) //elinimam monstrul din lista
            return 0;
        battle(0, monstruPlayer, player1, enemy1);
    }
    if (outcome == false) //outcome-ul in care monstrul jucatorului moare
    {
        if (playerMonsterDied(player1) == true) //eliminam monstrul din lista
            return 0;
        int s = alegeMonstru(player1); //functie pentru a-i da jucatorului posibilitatea de a alege un monstru inlocuitor
        battle(monstruAdvers, s, player1, enemy1);
    }
}

bool gameLoop::UI(Monster &x, Monster &y, Player &z) {
    Attacks player;
    Attacks enemy;
    cout << endl;
    while (true)
    {
        cout << "Player " << z.getName() << ": " << x.getName() << " " << "(Type: " << x.getType() << ", " << "Attack: " << x.getAttack() << ", " << "HP: " <<  x.getHp() << " " << "Status: " << x.getStatus() << ')' << endl;
        cout << "Enemy: " << y.getName() << " " << "(Type: " << y.getType() << ", " << "Attack: " << y.getAttack() << ", " << "HP: " <<  y.getHp() << " " << "Status: " << y.getStatus() << ')' << endl;
        cout << "Optiuni: " << endl;
        cout << "(1) " << player.getAtk1() << endl;
        cout << "(2) " << player.getAtk2() << endl;
        cout << "(3) " << player.getAtk3() << endl;
        cout << "(4) Potiune (potiuni ramase: " << z.getNrPotions() << ")" << endl;
        cout << "(5) Switch" << endl;
        cout << "Decizie: ";
        unsigned int decizie;
        cin >> decizie;
        int dmg;
        //atac care ii scade hp-ul inamicului cu un numar egal cu cel al atacului monstrului player-ului
        if (decizie == 1)
        {
            dmg = player.damage(x, player, decizie);
            player.applyDamage(dmg, y);
        }
        //atac care multiplica cu 2 atacul monstrului player-ului
        if (decizie == 2)
        {
            dmg = player.damage(x, player, decizie);
            player.applyDamage(dmg, y);
        }
        //atac care poate seta status-ul monstrului inamic la True
        if (decizie == 3)
            player.statusEffect(y);
        //potiune care adauga 50 hp la hp-ul curent
        if (decizie == 4 && z.getNrPotions() != 0)
        {
            int hp = x.getHp();
            x.setHp(hp + 50);
        }
        else
            if (decizie == 4 && z.getNrPotions() == 0)
                cout << "No more potions!" << endl;
        //optiune pentru a schimba monstrul curent
        if (decizie == 5)
        {
            alegeMonstru(z);
        }

        int hp;
        hp = y.getHp();
        if (hp <= 0)
        {
            cout << "Enemy's " << y.getName() << " fainted";
            cout << endl;
            return true;
        }
        //un fel de ai pentru ca adversarul sa decida ce atac alege
        hp = x.getHp();
        unsigned int enemyAttack = y.getAttack();
        if (hp <= enemyAttack * 2 && hp > enemyAttack) //daca monstrul player-ului este in killrange-ul atacului heavy, inamicul va alege aceasta optiune
        {
            dmg = enemy.damage(y, enemy, 2);
            enemy.applyDamage(dmg, x);
        }
        else //daca nu, acesta va opta pentru atacul cu sansa de 100%
        {
            dmg = enemy.damage(y, enemy, 1);
            enemy.applyDamage(dmg, x);
        }

        hp = x.getHp();

        if (hp <= 0)
        {
            cout << z.getName() << "'s " << x.getName() << " fainted";
            cout << endl;
            return false;
        }
        cout << "-------------------------------------" << endl;
    }
}

int gameLoop::start() {

    Player player1;
    Enemy enemy1;

    player1.createMonsters();
    enemy1.createMonsters();

    cout << "Introduceti numele: ";
    string numeJucator;
    cin >> numeJucator;
    player1.setName(numeJucator);
    cout << endl;

    cout << "Numarul de potiuni (potiunile recupereaza 25hp)" << endl;
    cout << "Recomandat: 0 (hard), 1-2 (medium), 3+ (easy): ";
    int nrpotiuni;
    cin >> nrpotiuni;
    player1.setNrPotions(nrpotiuni);
    cout << endl;

    unsigned int decizie;
    decizie = alegeMonstru(player1);

    srand(time(NULL));
    int monstruAdvers;
    monstruAdvers = rand()%10;
    if (monstruAdvers == 0 || monstruAdvers == 3 || monstruAdvers == 4 || monstruAdvers == 7)
        monstruAdvers = 0;
    else if (monstruAdvers % 2 == 0)
        monstruAdvers = 2;
    else if (monstruAdvers % 2 != 0)
        monstruAdvers = 1;

    if (decizie == 0)
    {
        int end = battle(monstruAdvers, 0, player1, enemy1);
        if (end == 0)
            return 0;
    }
    if (decizie == 1)
    {
        int end = battle(monstruAdvers, 1, player1, enemy1);
        if (end == 0)
            return 0;
    }
    if (decizie == 2)
    {
        int end = battle(monstruAdvers, 2, player1, enemy1);
        if (end == 0)
            return 0;
    }
    return 0;
}

