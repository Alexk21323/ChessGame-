#ifndef _HUMAN_HPP
#define _HUMAN_HPP

#include "player.hpp"


class Human : public Player
{
    
    public:
        int x, y;
        void move(int x, int y, Board* board){
            this->x = x;
            this->y = y;
            std::cout << x<< "\t"<< y<<"\n";
            
            board->getGrid({7,7})->getPiece()->setPosition(x-50,y-50);

        }


};

#endif //_HUMAN_HPP