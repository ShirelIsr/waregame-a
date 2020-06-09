#include "ParamedicCommander.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

using namespace std;

void ParamedicCommander::action(vector<vector<Soldier*>> &board, pair<int,int> source)
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
                    if(Paramedic *p=dynamic_cast<Paramedic*>(temp))
                    {
                        ParamedicCommander *pc=dynamic_cast<ParamedicCommander*>(temp);
                        
                            if((pc==nullptr) ||((i != source.first) && (j != source.second)))
                            {
                                if(attack->getPlayerNum()==p->getPlayerNum ())
                                {
                                     dest.first=i;
                                    dest.second=j;
                                     p->action(board,dest);
                                }
                            }
                           
                    }
                }
           }   }     
}
}
