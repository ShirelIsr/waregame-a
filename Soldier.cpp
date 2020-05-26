#include "Soldier.hpp"

#include <iostream>


using namespace std;

using namespace WarGame;

    Soldier(const int &name, int hp, int power) : name(name), hp(hp), power(power) {}
   int getName() 
   {
       return this->name;
   }
    bool isAlive() 
    {
        return true;
    }
    void attack(Soldier& other) ;
    virtual void specialMove(Soldier& other) const { cout << "Soldier special move\n"; }
