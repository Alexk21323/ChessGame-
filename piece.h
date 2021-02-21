#ifndef _PIECES_H
#define _PIECES_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Piece{

public:


sf::Sprite s;
sf::Texture t;
Piece(){}
sf::Texture getPiece();
void setSprite();
sf::Sprite getSprite();
void setTexture(std::string filename);
void setSize();
};








#endif //_PIECES_H