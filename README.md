# Monsters Battle


## Table of Contents:
- [Introduction](#introduction)
- [Installation](#installation)
- [Features](#features)
- [Classes](#classes)


## Introduction
Monsters Battle is a terminal turn-base game made in C++ for my OOP course.
It is heavily inspired by the [combat system of Pokemon games](https://pokemon.fandom.com/wiki/Pok%C3%A9mon_battle).

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/TheFluffyBoi2/Monsters-Battle.git
   ```
2. Run CMake
   ```bash
   cmake -G "Unix Makefiles" .
   ```
3. Create the executable using Make
   ```bash
   make
   ```
4. Run the game
   ```bash
   ./MonstersBattle
   ```
   

## Features
- Selectia Dificultatii: Ai posibilitatea de a alege dintre 3 dificultati (Hard, Medium, Easy)
```bash
Numarul de potiuni (potiunile recupereaza 25hp)
Recomandat: 0 (hard), 1-2 (medium), 3+ (easy): 0
Dificultate aleasa: Hard
```
- Monstrii Diversi: Iti poti alege unul dintre cei 3 monstrii cu statistici diferite
```bash
Alegeti un mosntru: 
Flamekey(Type: Attack, Attack: 50, HP: 100)(0)
Terroron(Type: Defense, Attack: 10, HP: 350)(1)
Cottonic(Type: Balanced, Attack: 25, HP: 200)(2)
```
- Batalii Dinamice: Ai la dispozitie diferite abilitati si actiuni pentru a-ti infrange oponentul
```bash
Player Dumitru: Flamekey (Type: Attack, Attack: 50, HP: 100 Status: None)
Enemy: Hypoceros (Type: Attack, Attack: 50, HP: 100 Status: None)
Optiuni: 
(1) Soft attack (100%)
(2) Hard attack (75%)
(3) Status attack (50%)
(4) Potiune (potiuni ramase: 0)
(5) Switch
```

## Classes
- gameLoop: Is the main class of the game.
- entity: An abstract class that outlines the caractheristics that a duelist should have.
- player, enemy: Classes that inherits from the entity class. Each one of them have a different set of monsters.
- attacks: Its the class that is used to calculate the outcome of every single attack along with the chance of said attack to inflict a status effect.
