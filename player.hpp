#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include "board.h"
#include "piece.h"
#include "king.hpp"
#include "queen.hpp"
#include "knight.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "pawn.hpp"

class Player
{
    public:
    virtual bool select(int x, int y, Board* board) = 0;
    virtual bool makeMove(int x, int y, Board* board) = 0;
    //member variable
    


};

#endif //_PLAYER_HPP