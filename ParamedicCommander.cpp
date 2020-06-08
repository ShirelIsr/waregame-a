#include "ParamedicCommander.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

using namespace std;

void ParamedicCommander::action(vector<vector<Soldier*>> &board, pair<int,int> source)
{
    int i=source.first;
    int j=source.second;
    if((i<0)||(i>board.size())||(j<0)||(j>board.size()))  __throw_out_of_range("err");
    Soldier* temp;

    //i-1,j 
    if((i-1)>=0)
    {
        temp=board[i-1][j];
        if((temp!=nullptr)&&(temp->getPlayerNum()==board[i][j]->getPlayerNum()))
        {
            temp->setHP(temp->getMaxHP());
        }
    }
    //i+1,j
     if((i+1)<=board.size()-1)
    {
        temp=board[i+1][j];
        if((temp!=nullptr)&&(temp->getPlayerNum()==board[i][j]->getPlayerNum()))
        {
            temp->setHP(temp->getMaxHP());
        }
    }
    //i,j-1
    if((j-1)>=0)
    {
        temp=board[i][j-1];
        if((temp!=nullptr)&&(temp->getPlayerNum()==board[i][j]->getPlayerNum()))
        {
            temp->setHP(temp->getMaxHP());
        }
    }
    //i,j+1
         if((j+1)<=board.at(0).size()-1)
    {
        temp=board[i][j+1];
        if((temp!=nullptr)&&(temp->getPlayerNum()==board[i][j]->getPlayerNum()))
        {
            temp->setHP(temp->getMaxHP());
        }
    }

       pair <int,int> sol;
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
           if(board[i][j]!=nullptr)
           {
               Soldier* temp=board[i][j];
               if((temp->getPlayerNum()==board[source.first][source.second]->getPlayerNum())&&(dynamic_cast<Paramedic*>(temp)))
              { 
                  sol.first=i;
              sol.second=j;
              temp->action(board,sol);
           }
        }
    }
}
}
