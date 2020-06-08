#pragma once
#ifndef WARGAME_A_PARAMEDIC_HPP
#define WARGAME_A_PARAMEDIC_HPP


#include "Soldier.hpp"
using namespace std;

const int damge_p = 0;
const int max_hp_p =100;
 
    class Paramedic : public Soldier {
    public:
        Paramedic(int player) : Soldier(player,max_hp_p,damge_p) {}
        Paramedic(int player,int max_hp,int damge) : Soldier(player,max_hp,damge) {}
        ~Paramedic(){ std::cout << "Destructing base \n"; };
        void action(vector<vector<Soldier*>> &board, pair<int,int> source);
    };

#endif //WARGAME_A_PARAMEDIC_HPP