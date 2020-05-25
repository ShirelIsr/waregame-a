#include "Soldier.hpp"

class Sniper: public Soldier{
public:
   Sniper(const int &name, int hp=100, int power=50) :  Soldier(name, hp, power) {}
    void specialMove(Soldier& other) ;
};