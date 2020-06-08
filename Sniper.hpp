#pragma once
//#ifndef WARGAME_A_SNIPER_HPP
//#define WARGAME_A_SNIPER_HPP

#include "Soldier.hpp"
using namespace std;

const int damge_s = 50;
const int max_hp_s =100;
 
    class Sniper : public Soldier {
    public:
        Sniper(int player) : Soldier(player,max_hp_s,damge_s) {}
        Sniper(int player,int max_hp,int damge) : Soldier(player,max_hp,damge) {}
        ~Sniper(){ std::cout << "Destructing base \n"; };
        void action(vector<vector<Soldier*>> &board, pair<int,int> source);
    };


//#endif //WARGAME_A_SNIPER_HPP