#ifndef _GRID_H_
#define _GRID_H_

#include "piece.h"
#include "pawn.hpp"

class Grid {
    int position;
    Piece* piece;
    int x;
    int y;
    
   
public:
    ~Grid(){}
    Grid(int destination, int x, int y);
    Grid(Piece& piece, int x, int y);
    Grid(Piece* piece);
    int GetX(){ return x; }
    int GetY(){ return y; }
    const int getPosition() const {return this->position;}
    Piece* getPiece() const {return this->piece;}
    bool isEmpty() {return this->piece == nullptr;}
    friend std::ostream& operator <<(std::ostream& out, Grid& grid){
        if(grid.isEmpty()) 
            return out << "-";
        else 
            return out << "piece is here";
    }
};

#endif //_GRID_H_