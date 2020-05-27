#include "Board.hpp"
#include <math.h>
#include <iostream>

using namespace std;

namespace WarGame{



    Soldier*& operator[](std::pair<int,int> location)
    {
        return board[location.first][location.second];
    }

     Soldier* operator[](std::pair<int,int> location) const
     {
         return board[location.first][location.second];
     }

       void move(uint player_number, std::pair<int,int> source, MoveDIR direction)
       {

       }

        bool has_soldiers(uint player_number) const
        {
            return true;
        }




}