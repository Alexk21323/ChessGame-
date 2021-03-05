#ifndef _KING_H
#define _KING_H

#include "piece.h"
#include "grid.h"
#include <SFML/Graphics.hpp>

class King: public Piece{
public:
//member variables
int position;
sf::Sprite sprite; 
sf::Texture texture;
King(int pos,std::string col){ 
    color = col;
    if(color == "White")
        texture.loadFromFile("Sprites/wking.png");
    if(color == "Black")
        texture.loadFromFile("Sprites/bking.png");
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

void setPosition(int x, int y){
    sprite.setPosition(x,y);
}

void move(int a, int b){
    sprite.setPosition(a, b);
}
       
void draw(sf::RenderWindow& window){
        
    // int y = pos/8;
    // int x = (pos-y*8
    window.draw(sprite);
}
        
    
};









#endif //