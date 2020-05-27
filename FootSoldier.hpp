#ifndef WARGAME_A_FOOTSOLDIER_HPP
#define WARGAME_A_FOOTSOLDIER_HPP
#include "Soldier.hpp"




class FootSoldier : public Soldier{
public:
    int damage_per_activity = 10 ;
    virtual void action();
    FootSoldier(int player) : Soldier(player,100) {

    };
};

#endif //WARGAME_A_FOOTSOLDIER_HPP