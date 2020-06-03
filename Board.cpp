#include <iostream>
#include "Board.hpp"

void WarGame::Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
{
        Soldier* temp = (*this)[source];
          if(temp->getPlayerNum() != player_number) __throw_invalid_argument("ERR,The soldier belongs to the other player");
        if(temp==nullptr) __throw_invalid_argument("ERR, ther is no soldier ");
      
     //   board[source.first][source.second]= nullptr;
        
        pair<int,int> dest;

        switch (direction)
        {
        case Down:
        {
            dest.first=source.first-1;
            dest.second=source.second;
             break;
        }
        case Up:
        {
            dest.first=source.first+1;
            dest.second=source.second;
             break;
        }
        case Right:
          {
            dest.first=source.first;
            dest.second=source.second+1;
             break;
        }
        case Left:
        {
            dest.first=source.first;
            dest.second=source.second+1;
             break;
        }
        default:
            break;
        }

        //check range
        if((dest.first<0)||(dest.second<0) ||(dest.first>= board.size())||(dest.second>=board.size())
         __throw_out_of_range("ERR,Exceeded game board limits");
         
         if((*this)[dest] != nullptr)
         {
             throw invalid_argument("ERR, A soldier already exists in this location");
         }

        (*this)[source]=nullptr;
        (*this)[dest]=temp;
        (temp)->action(board,dest);

}
std::pair<int,int> WarGame::Board::findNearest(uint player_number,std::pair<int,int> source){
    int x= source.first , y=source.second;
    int minDist=pow(board.size(),2);
    std::pair<int,int> ret;
    for (int i = 0; i < board.size(); ++i) 
    {
        for (int j = 0; j < board.at(0).size(); ++j)
        {
            if((board[i][j]!= nullptr) && (board[i][j]->player != player_number))
            {
                int col = std::sqrt(pow(i-x,2)+pow(j-y,2));
                if(minDist>col)
                {
                    minDist=col;
                    ret = {i,j};
                }
            }
        }
    }
    return ret;
}
std::pair<int,int> WarGame::Board::findHighest(uint player_number, pair<int, int> source)
 {
    int max=0;
    std::pair<int,int> ret;
    for (int i = 0; i < board.size(); ++i)
     {
        for (int j = 0; j < board.at(0).size(); ++j)
         {
            if((board[i][j]!= nullptr) && (board[i][j]->player != player_number))
            {
                if(board[i][j]->initial_health_points>max)
                {
                    max=board[i][j]->initial_health_points;
                    ret = {i,j};
                }
            }
        }
    }
    return ret;
}


bool WarGame::Board::isLegalMove(std::pair<int,int> source , MoveDIR direction)
{
   pair<int,int> dest;

        switch (direction)
        {
        case Down:
        {
            dest.first=source.first-1;
            dest.second=source.second;
             break;
        }
        case Up:
        {
            dest.first=source.first+1;
            dest.second=source.second;
             break;
        }
        case Right:
          {
            dest.first=source.first;
            dest.second=source.second+1;
             break;
        }
        case Left:
        {
            dest.first=source.first;
            dest.second=source.second+1;
             break;
        }
        default:
            break;
        }

        //check range
        if((dest.first<0)||(dest.second<0) ||(dest.first>= board.size())||(dest.second>=board.size())
        {
            return true;
        }
        return false;
         

}

bool WarGame::Board::has_soldiers(uint player_number) const{

    for (int i = 0; i < this->board.size() ; ++i) 
    {
        for (int j = 0; j < this->board.at(0).size() ; ++j) 
        {

            if((board[i][j]!= nullptr) && (board[i][j]->player == player_number))
            {
                return true;
            }

        }
    }
    return false;
}

WarGame::Soldier*& WarGame::Board::operator[](std::pair<int,int> location)
{
    return board[location.first][location.second];
  
}
WarGame::Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
    if(board[location.first][location.second]!= nullptr)
     {
        return board[location.first][location.second];
    }
    return nullptr;
}


