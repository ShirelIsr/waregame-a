#include <iostream>

class Soldier{
protected:
    string name;
    int hp;
    int power;
protected:
    void applyDamageTo(Fighter& target, int damage) const {}
public:
    Soldier(const string &name, int hp, int power) : name(name), hp(hp), power(power) {}
    const string& getName() const {}
    bool isAlive() const {}
    void attack(Fighter& other) const {}
};

class FootSoldier: public Soldier{
public:
    FootSoldier(const string &name, int hp=100, int power=10) :  Soldier(name, hp, power) {}
    void specialMove(Fighter& other) {  cout << "FootSoldier special move\n"; }
};

class FootCommander: public Soldier{
public:
    FootCommander(const string &name, int hp=150, int power=20) :  Soldier(name, hp, power) {}
    void specialMove(Fighter& other) {  cout << "FootCommander special move\n"; }
};

class Sniper: public Soldier{
public:
   Sniper(const string &name, int hp=100, int power=50) :  Soldier(name, hp, power) {}
    void specialMove(Fighter& other) {  cout << "Sniper special move\n"; }
};

class SniperCommander: public Soldier{
public:
   SniperCommander(const string &name, int hp=120, int power=100) :  Soldier(name, hp, power) {}
    void specialMove(Fighter& other) {  cout << "SniperCommander special move\n"; }
};

class Paramedic: public Soldier{
public:
  Paramedic(const string &name, int hp=100, int power=FULL) :  Soldier(name, hp, power) {}
    void specialMove(Fighter& other) {  cout << "Paramedic special move\n"; }
};

class ParamedicCommander: public Soldier{
public:
  ParamedicCommander(const string &name, int hp=200, int power=FULL) :  Soldier(name, hp, power) {}
    void specialMove(Fighter& other) {  cout << "ParamedicCommander special move\n"; }
};