#pragma once
#ifndef WARGAME_A_PARAMEDIC_HPP
#define WARGAME_A_PARAMEDIC_HPP

#include "Soldier.hpp"

namespace WarGame {
    class Board;
    class Paramedic : public Soldier {
    public:
        int damage_per_activity = 50;
        Paramedic(int player) : Soldier(player, 100) {};
        ~Paramedic();
        void action(vector<vector<Soldier*>> &board, pair<int,int> source);
    };
}

#endif //WARGAME_A_PARAMEDIC_HPP