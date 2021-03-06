#ifndef _BISHOP_H
#define _BISHOP_H

#include "piece.h"
#include "grid.h"
#include <SFML/Graphics.hpp>

class Bishop: public Piece{
public:
//member variables

sf::Sprite sprite; 
sf::Texture texture;
    Bishop(std::vector<int> pos){ 
        texture.loadFromFile("Sprites/wbishop.png");
        sprite.setTexture(texture);

        sf::Vector2f targetSize(100.0f, 100.0f);
        sprite.setScale(
        targetSize.x / sprite.getGlobalBounds().width,
        targetSize.y / sprite.getGlobalBounds().height
        );
        position = pos;
    }
            
    sf::Sprite getSprite(){
        return sprite;
    }

    std::vector<int> getPosition(){
        return position;
    }
    
    void setPosition(int x, int y){
        sprite.setPosition(x,y);
    }
    void draw(sf::RenderWindow& window){
            window.draw(sprite);
        }

        void move(int a, int b){
        sprite.setPosition(a, b);
    }
};

#endif //_BISHOP_H