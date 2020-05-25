#include "Soldier.hpp"

class Paramedic: public Soldier{
public:
  Paramedic(const int &name, int hp=100, int power=100) :  Soldier(name, hp, power) {}
    void specialMove(Soldier& other) ;
};