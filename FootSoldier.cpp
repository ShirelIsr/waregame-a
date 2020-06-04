#include "FootSoldier.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

using namespace std;

void FootSoldier::action(vector<vector<Soldier*>> &board, pair<int,int> source)
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
           { dis=sqrt(pow(i-source.first,2)+pow(j-source.second,2));
            if(dis<=minDis)
            {
                minDis=dis;
                dest.first=i;
                dest.second=j;
                target=board[i][j];

            }
            }
            }
        }
    }

    if(target-> getHP()-board[source.first][source.second]->getHP() >0)
    {
        target->setHP(target-> getHP()-board[source.first][source.second]->getHP());
    }
    else{
        target=nullptr;
        board[dest.first][dest.second]=nullptr;
    }
}