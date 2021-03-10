#ifndef _ROOK_H
#define _ROOk_H

#include "piece.h"
#include "grid.h"
#include <SFML/Graphics.hpp>

class Rook : public Piece
{
public:
    //member variables

    sf::Sprite sprite;
    sf::Texture texture;

    Rook(std::vector<int> pos, bool color1)
    {
        type = 1;
        if (color1)
        {
            color = color1;
            texture.loadFromFile("Sprites/wrook.png");
            sprite.setTexture(texture);

            sf::Vector2f targetSize(100.0f, 100.0f);
            sprite.setScale(
                targetSize.x / sprite.getGlobalBounds().width,
                targetSize.y / sprite.getGlobalBounds().height);
        }
        else
        {
            color = color1;
            texture.loadFromFile("Sprites/brook.png");
            sprite.setTexture(texture);

            sf::Vector2f targetSize(100.0f, 100.0f);
            sprite.setScale(
                targetSize.x / sprite.getGlobalBounds().width,
                targetSize.y / sprite.getGlobalBounds().height);
        }
        position = pos;
    }

    sf::Sprite getSprite()
    {
        return sprite;
    }

    std::vector<int> getPosition()
    {
        return position;
    }    
    std::vector<int> getOld(){return oldPosition;}  

    void setSpriteLocation(int x, int y)
    {
        sprite.setPosition(x, y);
    }
    void draw(sf::RenderWindow &window)
    {
        window.draw(sprite);
    }
 
};

#endif //_ROOk_H