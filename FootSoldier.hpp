#pragma once
#ifndef WARGAME_A_FOOTSOLDIER_HPP
#define WARGAME_A_FOOTSOLDIER_HPP

#include "Soldier.hpp"
using namespace std;

const int damge_f = 10;
const int max_hp_f =100;
 
    class FootSoldier : public Soldier {
    public:
        FootSoldier(int player) : Soldier(player,max_hp_f,damge_f) {};
        FootSoldier(int player,int max_hp,int damge) : Soldier(player,max_hp,damge) {};
        void action(vector<vector<Soldier*>> &board, pair<int,int> source);
    };


#endif //WARGAME_A_FOOTSOLDIER_HPP