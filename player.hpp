#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include "board.h"


class Player
{
    public:
    virtual bool select(int x, int y, Board* board) = 0;
    virtual bool makeMove(int x, int y, Board* board) = 0;
    //member variable
    


};

#endif //_PLAYER_HPP