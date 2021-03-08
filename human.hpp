#ifndef _HUMAN_HPP
#define _HUMAN_HPP

#include "player.hpp"

class Human : public Player
{

public:
    int x;
    int y;
    int xPiece;
    int yPiece;
    std::vector<std::vector<int>> posMove;
    bool select(int x, int y, Board *board)
    {
        Piece *tmpPiece;
        this->xPiece = x / 100;
        this->yPiece = y / 100;
        tmpPiece = board->getGrid({xPiece, yPiece})->getPiece();
         
        std::cout<<"coord "<<xPiece<<"\t"<<yPiece<<std::endl;
        posMove = board->possibleMoves(tmpPiece);
        for (int i = 0; i < posMove.size(); i++)
        { 
            std::cout <<"possible";
            for (int j = 0; j < posMove[i].size(); j++)
            {
                std::cout<<posMove[i][j];
            }
            std::cout << "\n";
        }
        if (board->getGrid({xPiece, yPiece})->getPiece() != nullptr && !posMove.empty())
        {
            return true;
        }

        return false;
    }
    bool makeMove(int mouseX, int mouseY, Board *board)
    {
        bool flag = false;
        this->x = mouseX;
        this->y = mouseY;
        int destinationX = x / 100;
        int destinationY = y / 100;
        Piece *tmpPiece;
        //std::vector<std::vector<int>> posMove;
        std::vector<int> destination;
        destination.push_back(destinationX);
        destination.push_back(destinationY);
        //std::cout << "destination: " << destination[0] << destination[1] << std::endl;
       
       

        if (board->getGrid({xPiece, yPiece})->getPiece() != nullptr)
        {
            if (xPiece != destinationX || yPiece != destinationY)
            {
                tmpPiece = board->getGrid({xPiece, yPiece})->getPiece();
                for (int i = 0; i < posMove.size(); i++)
                {
                    if (posMove.at(i) == destination)
                    {
                        tmpPiece->setPostion(destinationX, destinationY);
                        board->movePiece(*tmpPiece);
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

#endif //_HUMAN_HPP