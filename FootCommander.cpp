#include "FootCommander.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

using namespace std;

void FootCommander::action(vector<vector<Soldier *>> &board, pair<int, int> source)
{


    Soldier *attack=board[source.first][source.second];

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != nullptr) 
            {

                Soldier *temp = board[i][j];
                if (temp!=nullptr)
                {
                    if(FootSoldier *fs=dynamic_cast<FootSoldier *>(temp))
                    {
                        FootCommander *fc=dynamic_cast<FootCommander*>(temp);
                        
                            if((fc==nullptr) ||((i != source.first) && (j != source.second)))
                            {
                                if(attack->getPlayerNum()==fs->getPlayerNum ())
                                {
                                     fs->action(board,make_pair(i,j));
                                }
                            }
                           
                    }
                }
           }   }     
}
}