#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <ostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include "grid.h"
#include "piece.h"

class Board{
public:
    //For starting a fresh Board 
    class Builder{
        vector <Grid*> grids;
        vector <Piece*> pieces;
        Builder();
        Builder& setPiece(Piece* piece);
        Builder& setMoveMaker(Alliance moveMaker);
        Board* build();
    }
private:
//Display Variables
sf::Image image;
sf::Sprite board_sprite;
sf::Texture board_texture;
int x;
int y;

//Member Variabels 
vector<piece*> Pieces;
vector<Grid*> grids;

public:
~Board();
Board(Builder& builder)();
Tile* getTile();
Tile* operator [](std::size_t index);
Board* startGame();
};

#endif //_BOARD_H