#include "grid.h"
#include "piece.h"

Grid::Grid(int position){
    this->position = position;
    this->piece = nullptr;
}

Grid::Grid(Piece& piece){
    this->position = piece.get_Position();
    this->piece = &piece; 
}

Grid::Grid(Piece* piece){
    if(piece == nullptr){
        throw std::invalid_argument("Piece Does not exist");
    }
    this->position = piece->getPosition();
    this->piece = piece;
}

