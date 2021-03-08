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
    sf::Sprite circle_sprite;
    sf::Texture circle_texture; 
    
public:
    ~Board();
    Board();
    void startGame();
    Grid *getGrid(std::vector<int> position);
    void setPiece(Piece *piece);
    void setPiece(Piece &piece);
    void showSelection(sf::RenderWindow& window, int x, int y);
    void draw(sf::RenderWindow &window);
    void movePiece(Piece& piece);
    std::vector<std::vector<int>> possibleMoves(Piece* piece);
    std::vector<std::vector<Grid *>> grids; //<-----call pieces with this
};

#endif //_BOARD_HS