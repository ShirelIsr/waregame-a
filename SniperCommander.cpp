#include "SniperCommander.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

using namespace std;

void SniperCommander::action(vector<vector<Soldier*>> &board, pair<int,int> source)
{
 Soldier *attack=board[source.first][source.second];
pair <int,int> dest;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != nullptr) 
            {

                Soldier *temp = board[i][j];
                if (temp!=nullptr)
                {
                    if(Sniper *s=dynamic_cast<Sniper *>(temp))
                    {
                        SniperCommander *sp=dynamic_cast<SniperCommander*>(temp);
                        
                            if((sp==nullptr) ||((i != source.first) && (j != source.second)))
                            {
                                if(attack->getPlayerNum()==s->getPlayerNum ())
                                {
                                     dest.first=i;
                                    dest.second=j;
                                     s->action(board,dest);
                                }
                            }
                           
                    }
                }
           }   }     
}
}