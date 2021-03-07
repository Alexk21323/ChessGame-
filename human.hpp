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
    bool select(int x, int y, Board *board)
    {
        this->xPiece = x / 100;
        this->yPiece = y / 100;
        int tmpx = x / 100;
        int tmpy = y / 100;

        if (board->getGrid({xPiece, yPiece})->getPiece() != nullptr)
        {
            return true;
        }

        return false;
    }
    bool makeMove(int mouseX, int mouseY, Board *board)
    {
        this->x = mouseX;
        this->y = mouseY;
        int destinationX = x / 100;
        int destinationY = y / 100;
        std::cout<<"Initial: "<<xPiece <<"\t"<<yPiece<<std::endl;
        std::cout<<"Final: "<<destinationX <<"\t"<<destinationY<<std::endl;
        
        Piece *tmpPiece;
        if (board->getGrid({xPiece, yPiece})->getPiece() != nullptr)
        {
            if(xPiece != destinationX || yPiece != destinationY){
            tmpPiece = board->getGrid({xPiece, yPiece})->getPiece();
            tmpPiece->setPostion(destinationX, destinationY);
            board->movePiece(*tmpPiece);
            return true;
            }
        }
        return false;
    }

 
};

#endif //_HUMAN_HPP