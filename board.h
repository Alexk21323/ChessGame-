#ifndef _BOARD_H
#define _BOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>


class Board{
private:
sf::Image image;
sf::Sprite s;
sf::Texture t;
int x;
int y;

public:
Board(){
    t.loadFromFile("Board.png");
    s.setTexture(t);
    s.setPosition(0,0); 
    sf::Vector2f targetSize(1000.0f, 1000.0f);
    s.setScale(
        targetSize.x / s.getGlobalBounds().width,
        targetSize.y / s.getGlobalBounds().height
    );
}
void draw() const;
sf::Sprite getSprite(){return s;}






};













#endif //_BOARD_H