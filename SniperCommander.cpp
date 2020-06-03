#include "SniperCommander.hpp"
#include "sniper.hpp"

#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

using namespace std;

void SniperCommander::action(vector<vector<Soldier*>> &board, pair<int,int> source)
{
    Soldier* target;
    int maxHP=INT8_MIN;
    pair <int,int> dest;

    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            if(board[i][j]!=nullptr)
            {
             if (board[i][j]->getPlayerNum()!=board[source.first][source.second]->getPlayerNum())
           { 
            if(board[i][j]->getHP>maxHP)
            {
                maxHP=board[i][j]->getHP;
                dest.first=i;
                dest.second=j;
                target=board[i][j;

            }
            }
            }
        }
    }

    if(target->getHP()-board[source.first][source.second]->getHP() >0)
    {
        target->setHealthPoint(target->getHealthPoint()-board[source.first][source.second]->getHP());
    }
    else{
        target=nullptr;
        board[dest.first][dest.second]=nullptr;
    }

        pair <int,int> sol;
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
           if(board[i][j]!=nullptr)
           {
               Soldier* temp=board[i][j];
               if((temp->getPlayerNum()==board[source.first][source.second]->getPlayerNum())&&(dynamic_cast<Sniper*>(temp)))
              { 
                  sol.first=i;
              sol.second=j;
              temp->action(board,sol);
           }
        }
    }
}