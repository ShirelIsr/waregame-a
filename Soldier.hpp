#pragma once
#include <iostream>
#include <vector>

namespace std{
    class Soldier {
    private:
        uint max_health_points;
        uint cur_health_points;
        uint player;
        uint action_damge;

        public:
        Soldier(int player, int max_hp,int demge) : player(player), max_health_points(max_hp),cur_health_points(max_hp), action_damge(demge){};
        virtual ~Soldier() { std::cout << "Destructing base \n"; };
        virtual void action(vector<vector<Soldier*>> &board, pair<int,int> source);
        int getHP(){ return cur_health_points; }
        void setHP(int hp) {cur_health_points=hp;}
        int getDamge(){return action_damge;}
        int getPlayerNum(){return player;}
        int getMaxHP(){return max_health_points;}

    };
}

