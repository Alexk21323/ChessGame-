#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "piece.h"
#include "grid.h"
#include <SFML/Graphics.hpp>

class Knight : public Piece
{
public:
    //member variables

    sf::Sprite sprite;
    sf::Texture texture;
    Knight(std::vector<int> pos)
    {
        texture.loadFromFile("Sprites/wknight.png");
        sprite.setTexture(texture);

        sf::Vector2f targetSize(100.0f, 100.0f);
        sprite.setScale(
            targetSize.x / sprite.getGlobalBounds().width,
            targetSize.y / sprite.getGlobalBounds().height);
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

#endif //_KNIGHT_H