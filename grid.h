#ifndef _GRID_H_
#define _GRID_H_

#include "piece.h"
#include "pawn.hpp"
#include <vector>

class Grid
{
    std::vector<int> position;
    Piece *piece;
    int x;
    int y;

public:
    ~Grid() {}
    Grid(std::vector<int> destination, int x, int y);
    Grid(Piece &piece, int x, int y);
    Grid(Piece *piece);
    std::vector<int> GetPos() { return position; }
    std::vector<int> GetCoordinates() { return {x, y}; }
    const std::vector<int> getPosition() const { return this->position; }
    Piece *getPiece() const { return this->piece; }
    void deletePiece(){
    Piece* tmp = this->piece;
    this->piece = nullptr;
    delete tmp;    
        
    }
    bool isEmpty() { return this->piece == nullptr; }
    friend std::ostream &operator<<(std::ostream &out, Grid &grid)
    {
        if (grid.isEmpty())
            return out << "-";
        else
            return out << "piece is here";
    }
};

#endif //_GRID_H_