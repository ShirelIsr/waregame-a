#pragma once
#ifndef WARGAME_A_SNIPER_HPP
#define WARGAME_A_SNIPER_HPP

#include "Soldier.hpp"

namespace WarGame {
    class Board;
    class Sniper : public Soldier {
    public:
        int damage_per_activity = 50;
        Sniper(int player) : Soldier(player, 100) {};
        ~Sniper();
        void action(vector<vector<Soldier*>> &board, pair<int,int> source);
    };
}

#endif //WARGAME_A_SNIPER_HPP