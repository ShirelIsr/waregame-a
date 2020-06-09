#include "Paramedic.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>



void Paramedic::action(vector<vector<Soldier*>> &board, pair<int,int> source)
{
    int i=source.first;
    int j=source.second;
   if((i<0)||(i>board.size())||(j<0)||(j>board.size()))  __throw_out_of_range("err");
    Soldier* temp;
    int num =board[i][j]->getPlayerNum();

    //i-1,j 
    if((i-1)>=0)
    {
        temp=board[i-1][j];
        if((temp!=nullptr)&&(temp->getPlayerNum()==num))
        {
            temp->setHP(temp->getMaxHP());
        }
    }
    //i+1,j
     if((i+1)<=board.size()-1)
    {
        temp=board[i+1][j];
        if((temp!=nullptr)&&(temp->getPlayerNum()==num))
        {
            temp->setHP(temp->getMaxHP());
        }
    }
    //i,j-1
    if((j-1)>=0)
    {
        temp=board[i][j-1];
        if((temp!=nullptr)&&(temp->getPlayerNum()==num))
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
}
