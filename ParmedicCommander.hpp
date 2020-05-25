#include "Soldier.hpp"



class ParamedicCommander: public Soldier{
public:
  ParamedicCommander(const int &name, int hp=200, int power=100) :  Soldier(name, hp, power) {}
    void specialMove(Soldier& other) ;
};