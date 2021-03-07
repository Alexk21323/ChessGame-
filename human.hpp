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
        this->xPiece = x/100;
        this->yPiece = y/100;
        int tmpx = x/100;
        int tmpy = y / 100;

         if(board->getGrid({xPiece, yPiece})->getPiece()!= nullptr){

             return true;
         }
         
        //get the pixel position to coordinates

       // std::cout << "initial: " << tmpx << "\t" << tmpy << "\n";
        // board->getGrid({7,7})->getPiece()->setPosition(tmpx,tmpy);
        return false;
    }
    bool makeMove(int mouseX, int mouseY, Board *board)
    {
        this->x = mouseX;
        this->y = mouseY;
        
        int destinationX = x / 100;
        int destinationY = y / 100;
        //std::cout << "tmp coord: " << x << "\t" << y << "\n";
        //std::cout << "final: " << destinationX << "\t" << destinationY << "\n";
        Piece *tmpPiece;
        if(board->getGrid({xPiece, yPiece})->getPiece()!= nullptr){
        tmpPiece = board->getGrid({xPiece, yPiece})->getPiece();
        tmpPiece->setPosition(destinationX, destinationY);
        board->setPiece(tmpPiece);
        return true;
        }
        return false;
    }
};

#endif //_HUMAN_HPP