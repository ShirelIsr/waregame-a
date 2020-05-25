#include "Soldier.hpp"

class SniperComander: public Soldier{
public:
   SniperComander(const int &name, int hp=120, int power=100) :  Soldier(name, hp, power) {}
    void specialMove(Soldier& other);
};