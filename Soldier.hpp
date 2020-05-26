#pragma once
/*#include <iostream>

//using std::cout, std::endl, std::string;

class Soldier {
protected:
    int name;
    int hp;
    int power;
protected:
    void applyDamageTo(Soldier &target, int damage) const {}

public:
    Soldier(const int &name, int hp, int power) : name(name), hp(hp), power(power) {}

    int getName();

    bool isAlive();

    void attack(Soldier &other);

    virtual void specialMove(Soldier &other) const { std::cout << "Soldier special move\n"; }
};

*/


#ifndef WARGAME_A_SOLDIER_HPP
#define WARGAME_A_SOLDIER_HPP

#include "iostream"

class Soldier{
public:
    int initial_health_points;
    int player;

    virtual void action() = 0;
    Soldier(int player,int hp) : player(player) , initial_health_points(hp){};
};

#endif //WARGAME_A_SOLDIER_HPP