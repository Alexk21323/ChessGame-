#include "grid.h"
#include "piece.h"

Grid::Grid(int position, int x1, int y1){
    this->position = position;
    this->piece = nullptr;
    x = x1;
    y = y1;
    std::cout<< x <<"  " << y << std::endl;

}

Grid::Grid(Piece& piece, int x1, int y1){
    this->position = piece.getPosition();
    this->piece = &piece; 
    this->x = x1;
    this->y = y1;
    std::cout<< x <<"  " << y << std::endl;
    piece.setPosition(x,y);
}

Grid::Grid(Piece* piece){
    if(piece == nullptr){
   
       throw std::invalid_argument("Piece Does not exist");
    }
    this->position = piece->getPosition();
    this->piece = piece;
}