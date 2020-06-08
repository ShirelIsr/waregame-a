#ifndef WARGAME_A_FOOTCOMMANDER_HPP
#define WARGAME_A_FOOTCOMMANDER_HPP
#include "FootSoldier.hpp"

using namespace std;

const int damage_fc =20;
const int max_hp_fc =150;
  
    class FootCommander : public FootSoldier {
    public:
       FootCommander(int player) : FootSoldier(player,max_hp_fc,damage_fc){}
        ~ FootCommander(){ std::cout << "Destructing base \n"; };
        void action(vector<vector<Soldier*>> &board, pair<int,int> source);
    };


#endif //WARGAME_A_FOOTCOMMANDER_HPP