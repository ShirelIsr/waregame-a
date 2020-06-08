#include <iostream>
#include "Board.hpp"
using namespace std;
namespace WarGame{

void WarGame::Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
{
        Soldier* temp = board[source.first][source.second];
          if(temp==nullptr) __throw_invalid_argument("ERR, ther is no soldier ");
          if(temp->getPlayerNum() != player_number) __throw_invalid_argument("ERR,The soldier belongs to the other player");
      
     
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
        if((dest.first<0)||(dest.second<0) ||(dest.first>= board.size())||(dest.second>=board.at(0).size()))
        { __throw_out_of_range("ERR,Exceeded game board limits");
        }
         
         if((*this)[dest] != nullptr)
         {
             throw invalid_argument("ERR, A soldier already exists in this location");
         }

         board[dest.first][dest.second]=temp;
        board[source.first][source.second]=nullptr;
        temp->action(board,dest);

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
        if((dest.first<0)||(dest.second<0) ||(dest.first>= board.size())||(dest.second>=board.size()))
        {
            return true;
        }
        return false;
         
}

bool WarGame::Board::has_soldiers(uint player_number) const{

    for (int i = 0; i < this->board.size() ; ++i) 
    {
        for (int j = 0; j < this->board.at(i).size() ; ++j) 
        {
            Soldier *temp=board[i][j];
            if(temp != nullptr)
            {
                if (temp->getPlayerNum() == player_number) 
                {
                    return true;
                }
        }

    }
    }
    return false;
}

Soldier*& Board::operator[](std::pair<int,int> location)
{
    return board[location.first][location.second];
  
}
Soldier* Board::operator[](std::pair<int,int> location) const{

        return board[location.first][location.second];
}

}

