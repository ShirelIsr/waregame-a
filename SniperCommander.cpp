#include "SniperCommander.hpp"
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
    Soldier *attack=board[source.first][source.second];

    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            if(board[i][j]!=nullptr)
            {
             if (board[i][j]->getPlayerNum()!=attack->getPlayerNum())
           { 
            if(board[i][j]->getHP() >= maxHP)
            {
                maxHP=board[i][j]->getHP();
                dest.first=i;
                dest.second=j;
                target=board[i][j];

            }
            }
            }
        }
    }

    if(target->getHP()-attack->getDamge()>0)
    {
        target->setHP(target->getHP()-attack->getDamge ());
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
           if((board[i][j]!=nullptr)&&((i != source.first) &&(j!=source.second)))
           {
               Soldier* temp=board[i][j];
               if((temp->getPlayerNum()==temp->getPlayerNum())&&(dynamic_cast<Sniper*>(temp)))
              { 
              sol.first=i;
              sol.second=j;
              temp->action(board,sol);
           }
        }
    }
}
}