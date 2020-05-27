/*#include "Soldier.hpp"

#include <iostream>


using namespace std;
using namespace WarGame;

//Soldier(const int &name, int hp, int power) : name(name), hp(hp), power(power) {}

int getName() {
    return this->name;
}

bool isAlive() {
    return true;
}

void attack(Soldier &other);

void specialMove(Soldier &other) { cout << "Soldier special move\n"; }*/

#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include <iostream>

void FootSoldier::action() {
    std::cout<<"footSoldier action"<<std::endl;
}
void FootCommander::action(){
    std::cout<<"footCommander action"<<std::endl;
}
