#ifndef _KING_H
#define _KING_H

#include "piece.h"
#include <SFML/Graphics.hpp>

class King : public Piece
{
public:
    //member variables

    sf::Sprite sprite;
    sf::Texture texture;

    King(std::vector<int> pos, bool color1)
    {
        type = 5;
        if (color1)
        {
            color = color1;
            texture.loadFromFile("Sprites/wking.png");
            sprite.setTexture(texture);

            sf::Vector2f targetSize(100.0f, 100.0f);
            sprite.setScale(
                targetSize.x / sprite.getGlobalBounds().width,
                targetSize.y / sprite.getGlobalBounds().height);
        }
        else
        {
            color = color1;
            texture.loadFromFile("Sprites/bking.png");
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

    void setSpriteLocation(int x, int y)
    {
        sprite.setPosition(x, y);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(sprite);
    }
};

#endif //_KING_H