#include "grid.h"
#include "piece.h"

Grid::Grid(std::vector<int> destination, int x1, int y1)
{
    this->position = destination;
    this->piece = nullptr;
    x = x1;
    y = y1;
}

Grid::Grid(Piece &piece, int x1, int y1)
{
    this->position = piece.getPosition();
    this->piece = &piece;
    this->x = x1;
    this->y = y1;

    piece.setSpriteLocation(x,y);
}

Grid::Grid(Piece *piece)
{
    if (piece == nullptr)
    {
        throw std::invalid_argument("Piece Does not exist");
    }
    this->position = piece->getPosition();
    this->piece = piece;
}