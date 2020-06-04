#pragma once
#ifndef WARGAME_A_PARAMEDICCOMMANDER_HPP
#define WARGAME_A_PARAMEDICCOMMANDER_HPP

#include "Paramedic.hpp"

using namespace std;

const int damage_pc =0;
const int max_hp_pc =200;
  
    class ParamedicCommander : public Paramedic {
    public:
        int damage_per_activity = 100;
        ParamedicCommander(int player) : Paramedic(player,max_hp_pc,damage_pc){};
        ~ParamedicCommander();
        void action(vector<vector<Soldier*>> &board, pair<int,int> source);
    };


#endif //WARGAME_A_PARAMEDIC_HPP