#ifndef _GRID_H_
#define _GRID_H_
#include "piece.h"

Class Grid {
    int position;
    Piece* piece;
    
Public:
    ~Grid() = delete;
    Grid(int destination);
    Grid(int destination, int x, int y);
    Grid(Piece& piece);
    Grid(Piece* piece);
    int x;
    int y;
    const int getPosition() const {return this->position;}
    Piece* getPiece() const {return this->piece;}
    bool isEmpty() {return this->piece == nullptr}
    friend std::ostream& operator <<(std::ostream& out, Tile& tile){
        if(tile.isempty()) return out << '-';
        else 
            return out << *tile->getPiece();
    }
<<<<<<< HEAD:Grid.h
}

=======
    
}
>>>>>>> 9fb6f0f32f32c18c2571be43efcefca1d1d6a3a0:grid.h
