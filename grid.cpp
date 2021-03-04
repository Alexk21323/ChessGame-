#include "grid.h"
#include "piece.h"

Grid::Grid(int position){
    this->position = position;
    this->piece = nullptr;
}

Grid::Grid(int position, int x, int y){
    this->position = position;
    this->piece = nullptr;
    this->x = x;
    this->y = y;
}

Grid::Grid(Piece& piece){
    this->position = piece.getPosition();
    this->piece = &piece; 
}

Grid::Grid(Piece* piece){
    if(piece == nullptr){
        throw std::invalid_argument("Piece Does not exist");
    }
    this->position = piece->getPosition();
    this->piece = piece;
}