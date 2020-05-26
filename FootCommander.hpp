#include "Soldier.hpp"


#ifndef WARGAME_A_FOOTCOMMANDER_HPP
#define WARGAME_A_FOOTCOMMANDER_HPP

class FootCommander : public Soldier{
public:

    int damage_per_activity = 20 ;
    virtual void action();
    FootCommander(int player) : Soldier(player,150) {} ;

};

#endif //WARGAME_A_FOOTCOMMANDER_HPP