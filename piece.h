#ifndef _PIECES_H
#define _PIECES_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
class Piece{

public:


Piece(){}

//All of the textures needed

virtual sf::Sprite getSprite()=0;
virtual int getPosition() = 0;
virtual void draw(sf::RenderWindow &window) =0;




};

#endif //_PIECES_H