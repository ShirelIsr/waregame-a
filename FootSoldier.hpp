#include "Soldier.hpp"

class FootSoldier: public Soldier{
public:
    FootSoldier(const int &name, int hp=100, int power=10) :  Soldier(name, hp, power) {}
    void specialMove(Soldier& other)  {  cout << "FootSoldier special move\n"; }
};