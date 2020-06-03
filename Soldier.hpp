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

#pragma once

#include <iostream>

namespace WarGame {
    class Board;

    class Soldier {
    public:
        int initial_health_points;
   //int hp;
        int player;
        int damge;
        Soldier(int player, int hp,int dm) : player(player), initial_health_points(hp), damge(dm){};
        virtual ~Soldier() { std::cout << "Destructing base \n"; };
        virtual void action() = 0;
         
        int getHP(){ return initial_health_points; }
        int setHP(int h) {hp=p;}
        int getDamge(){return damge;}
        int getPlayerNum(){return player;}



    


    };

}