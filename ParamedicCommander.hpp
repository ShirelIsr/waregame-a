#pragma once
#ifndef WARGAME_A_PARAMEDICCOMMANDER_HPP
#define WARGAME_A_PARAMEDICCOMMANDER_HPP

#include "Soldier.hpp"

namespace WarGame {
    class Board;
    class ParamedicCommander : public Soldier {
    public:
        int damage_per_activity = 0;
        ParamedicCommander  Paramedic(int player) : Soldier(player, 200) {};
        ~ParamedicCommander();
        void action(vector<vector<Soldier*>> &board, pair<int,int> source);
    };
}

#endif //WARGAME_A_PARAMEDIC_HPP