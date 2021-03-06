#include "FootSoldier.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

//using namespace std;

void FootSoldier::action(vector<vector<Soldier *>> &board, pair<int, int> source)
{
    Soldier *target;
    double minDis = board.size() * board.at(0).size();
    pair<int, int> dest;
  
    double dis;

    Soldier *attack = board[source.first][source.second];

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if ((board[i][j] != nullptr) && (board[i][j]->getPlayerNum() != attack->getPlayerNum()))
            {
                dis = sqrt(pow(i - source.first, 2) + pow(j - source.second, 2));
                if (dis <= minDis)
                {
                    minDis = dis;
                    dest.first = i;
                    dest.second = j;
                    target = board[i][j];
                }
            }
        }
    }
    if (target == nullptr) return;
    int hp = target->getHP() - attack->getDamge();
    if (hp > 0)
    {
        target->setHP(hp);
    }
    else
    {
        board[dest.first][dest.second] = nullptr;
        target=nullptr;
    }
}