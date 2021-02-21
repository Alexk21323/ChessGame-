#include "piece.h"

sf::Texture Piece::getPiece(){
    return t;
}

void Piece::setTexture(std::string file){
    t.loadFromFile(file);
}

void Piece::setSprite(){
    s.setTexture(t);
}

sf::Sprite Piece::getSprite(){
    return s;
}

void Piece::setSize(){
    s.setPosition(10,10);
    sf::Vector2f targetSize(100.0f, 100.0f);
     s.setScale(
        targetSize.x / s.getGlobalBounds().width,
        targetSize.y / s.getGlobalBounds().height
    );


}