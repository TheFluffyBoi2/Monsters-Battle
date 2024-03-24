cmake_minimum_required(VERSION 3.27)
project(MonstersBattle)

set(CMAKE_CXX_STANDARD 17)

add_executable(MonstersBattle main.cpp
        monster.h
        enemy.cpp
        enemy.h
        player.cpp
        monster.cpp
        entity.cpp
        attacks.cpp
        attacks.h)
