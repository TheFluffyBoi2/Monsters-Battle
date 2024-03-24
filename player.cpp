#include <iostream>
#include "player.h"

using namespace std;

Player::Player():
    Entity("None", 3),
    nrPotions(0)
{
//    cout << "Player vid creat" << endl;
}

Player::~Player()
{
    // cout << "destructor";
}

Player::Player(string _nume, unsigned int _nrMonsters, int _nrPotions):
    Entity(_nume, _nrMonsters),
    nrPotions(_nrPotions)
        {
//                cout << "Player cu numele " << name << " creat" << endl;
        }


int Player::getNrPotions(){
    return nrPotions;
}

void Player::setNrPotions(int PlayerNrPotions){
    nrPotions = PlayerNrPotions;
    if (nrPotions == 0)
        cout << "Dificultate aleasa: Hard " << endl;
    if (nrPotions >= 1 && nrPotions <= 2)
        cout << "Dificultate aleasa: Medium " << endl;
    if (nrPotions >= 3)
        cout << "Dificultate aleasa: Easy " << endl;
}

void Player::createMonsters() {
    playerMonsters.emplace_back("Flamekey", "Attack", "None", 50, 100);
    playerMonsters.emplace_back("Terroron", "Defense", "None", 10, 350);
    playerMonsters.emplace_back("Cottonic", "Balanced", "None", 25, 200);
}

void Player::setMonsterName(Monster x) {
    string type = x.getType();
    int choice;
    string nume;
    cout << "Vreti sa schimbati numele monstrului de " << type <<  " (1) sau sa il pastrati pe cel default (2)?: ";
    cin >> choice;
    if (choice == 1) {
        cout << endl << "Noul nume: ";
        cin >> nume;
        x.setName(nume);
    }
}

vector<Monster>& Player::getVector() {
    return playerMonsters;
}