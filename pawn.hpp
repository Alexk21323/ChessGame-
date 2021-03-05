#ifndef _PAWN_H
#define _PAWN_H

#include "piece.h"
#include "grid.h"
#include <SFML/Graphics.hpp>



class Pawn: public Piece{
public:
//member variables
int position;
sf::Sprite sprite; 
sf::Texture texture;
    Pawn(int pos){ 
        texture.loadFromFile("Sprites/wpawn.png");
        sprite.setTexture(texture);
        sprite.setPosition(0,700);

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
       
        void draw(sf::RenderWindow& window){
        
       wee
            // int y = pos/8;
            // int x = (pos-y*8
            window.draw(sprite);
        }
        
    
};









#endif //