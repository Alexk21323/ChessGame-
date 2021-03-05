#ifndef _PAWN_H
#define _PAWN_H

#include "piece.h"
#include "grid.h"
#include <SFML/Graphics.hpp>



class Pawn: public Piece{
public:
//member variables

sf::Sprite sprite; 
sf::Texture texture;
    Pawn(int pos){ 
        texture.loadFromFile("Sprites/wpawn.png");
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

    int getPosition(){
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

#endif //