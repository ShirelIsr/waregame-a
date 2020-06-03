#include "FootCommander.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

using namespace std;

void FootCommander::action(vector<vector<Soldier*>> &board, pair<int,int> source)
{
    Soldier* target;
    int minDis=INT8_MAX;
    pair <int,int> dest;
    int dis;

    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            if(board[i][j]!=nullptr)
            {
              if (board[i][j]->getPlayerNum()!=board[source.first][source.second]->getPlayerNum())
           { dis=sqrt(pow(i-source.first,2)+pow(j-sourc.second,2));
            if(dis<=minDis)
            {
                minDis=dis;
                dest.first=i;
                dest.second=j;
                target=board[i][j;

            }
            }
            }
        }
    }
    if(target->getHealthPoint()-board[source.first][source.second] >0)
    {
        target->setHealthPoint(target->getHealthPoint()-board[source.first][source.second]->getHealthPoint());
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
               if((temp->getPlayerNum()==board[source.first][source.second]->getPlayerNum())&&(dynamic_cast<FootSoldier*>(temp)))
              { sol.first=i;
              sol.second=j;
              temp->action(board,sol);
           }
        }
    }
}