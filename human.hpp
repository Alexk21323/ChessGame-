#ifndef _HUMAN_HPP
#define _HUMAN_HPP

#include "player.hpp"

class Human : public Player
{

public:
    int x;
    int y;
    int x_c;
    int y_c;
    void select(int x, int y, Board *board)
    {
        this->x = x;
        this->y = y;
        int tmpx = x - (x % 100);
        int tmpy = y - (y % 100);

        //get the pixel position to coordinates
       
        std::cout<<"initial: "<<tmpx<<"\t"<<tmpy<<"\n";
       // board->getGrid({7,7})->getPiece()->setPosition(tmpx,tmpy);
    }
    void makeMove(int mouseX, int mouseY, Board *board, int xCoor, int yCoor)
    {
        this->x = mouseX;
        this->y = mouseY;
        this->x_c = xCoor;
        this->y_c = yCoor;
         int tmpx = x/100;
        int tmpy = y/100;
        std::cout<<"tmp coord: "<<x_c<<"\t"<<y_c<<"\n";
        std::cout<<"final: "<<tmpx<<"\t"<<tmpy<<"\n";
        Piece* tmpPiece;
        //if(board->getGrid({x_c, y_c})->getPiece()!= nullptr){
        tmpPiece = board->getGrid({x_c, y_c})->getPiece();
        tmpPiece->setPosition(tmpx, tmpy);
        board->setPiece(tmpPiece);
        //}

    }
};

#endif //_HUMAN_HPP