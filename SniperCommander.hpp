#pragma once
#ifndef WARGAME_A_SNIPERCOMMANDER_HPP
#define WARGAME_A_SNIPERCOMMANDER_HPP

#include "Sniper.hpp"

using namespace std;

const int damage_sc =100;
const int max_hp_sc =120;
  
    class SniperCommander : public Sniper {
    public:
        SniperCommander(int player) : Sniper(player,max_hp_sc,damage_sc){}
         SniperCommander(int player,int max_hp,int damge) : Sniper(player,max_hp,damge) {}
        ~SniperCommander(){ std::cout << "Destructing base \n"; };
        void action(vector<vector<Soldier*>> &board, pair<int,int> source);
    };

#endif //WARGAME_A_SNIPERCOMMANDER_HPP