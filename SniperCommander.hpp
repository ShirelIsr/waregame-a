#pragma once
#ifndef WARGAME_A_SNIPERCOMMANDER_HPP
#define WARGAME_A_SNIPERCOMMANDER_HPP

#include "Soldier.hpp"

namespace WarGame {
    class Board;
    class SniperCommander : public Soldier {
    public:
        int damage_per_activity = 100;
        SniperCommander(int player) : Soldier(player, 120) {};
        ~SniperCommander();
        void action(vector<vector<Soldier*>> &board, pair<int,int> source);
    };
}

#endif //WARGAME_A_SNIPERCOMMANDER_HPP