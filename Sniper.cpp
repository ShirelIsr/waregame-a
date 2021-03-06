#include "Sniper.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

using namespace std;

void Sniper::action(vector<vector<Soldier*>> &board, pair<int,int> source)
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
}