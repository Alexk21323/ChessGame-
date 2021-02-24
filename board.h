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

public:
~Board();
Board(Builder& builder){
    // board_texture.loadFromFile("Board.png");
    // board_sprite.setTexture(t);
    // board_sprite.setPosition(0,0);
    
    // sf::Vector2f targetSize(1000.0f, 1000.0f);
    
    // board_sprite.setScale(
    //     targetSize.x / board_sprite.getGlobalBounds().width,
    //     targetSize.y / board_sprite.getGlobalBounds().height
    // );
}
Tile* getTile();
Tile* operator [](std::size_t index);



};













#endif //_BOARD_H