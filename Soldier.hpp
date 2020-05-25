
#include <iostream>
using std::cout, std::endl, std::string;

class Soldier{
protected:
    int name;
    int hp;
    int power;
protected:
    void applyDamageTo(Soldier& target, int damage) const {}
public:
    Soldier(const int &name, int hp, int power) : name(name), hp(hp), power(power) {}
   int getName() ;
    bool isAlive() ;
    void attack(Soldier& other) ;
    virtual void specialMove(Soldier& other) const { cout << "Soldier special move\n"; }
};

