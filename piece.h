#ifndef _PIECES_H
#define _PIECES_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
class Piece{

public:
int position;
int x; 
int y; 
Piece(){}

//All of the textures needed

virtual sf::Sprite getSprite()=0;
virtual int getPosition() = 0;
virtual void draw(sf::RenderWindow &window) =0;
virtual void move(int a, int b) = 0;
virtual void setPosition(int x, int y) = 0;

};

#endif //_PIECES_H