#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <ostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include "grid.h"
#include "piece.h"

class Board
{
    //Display Variables
    sf::Image image;
    sf::Sprite board_sprite;
    sf::Texture board_texture;
    
public:
    ~Board();
    Board();
    void startGame();
    Grid *getGrid(std::vector<int> position);
    void setPiece(Piece *piece);
    void setPiece(Piece &piece);
    //void setMoveMaker(Alliance moveMaker);
    void draw(sf::RenderWindow &window);
    // Grid* operator [][](std::vector<int> index);
    void movePiece(Piece& piece);
    std::vector<std::vector<Grid *>> grids; //<-----call pieces with this
};

#endif //_BOARD_HS