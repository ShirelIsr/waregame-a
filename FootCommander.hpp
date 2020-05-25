#include "Soldier.hpp"

class FootCommander: public Soldier{
public:
    FootCommander(const int &name, int hp=150, int power=20) :  Soldier(name, hp, power) {}
    void specialMove(Soldier& other) ;
};