#ifndef _PAWN_H
#define _PAWN_H

#include "piece.h"
#include "grid.h"
#include <SFML/Graphics.hpp>

class Pawn : public Piece
{
public:
    //member variables

    bool isFirstTime = true;
    sf::Sprite sprite;
    sf::Texture texture;
    
    Pawn(std::vector<int> pos, bool color1)
    {
        if (color1 == true)
        {
            color = color1;
            texture.loadFromFile("Sprites/wpawn.png");

            sprite.setTexture(texture);

            sf::Vector2f targetSize(100.0f, 100.0f);
            sprite.setScale(
                targetSize.x / sprite.getGlobalBounds().width,
                targetSize.y / sprite.getGlobalBounds().height);
        }
        else
        {
            color = color1;
            texture.loadFromFile("Sprites/bpawn.png");
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



    void setFirstTimeMove(bool b)
    {
        isFirstTime = b;
    }

    std::vector<std::vector<int>> getAvailableMoves(Board* board)
    {
        std::vector<std::vector<int>> AvailableMoves;
        if(this->color == false)
        {
            if(isFirstTime == true)
            {
                AvailableMoves.push_back({{this->position[0],this->position[1]-1}});
                AvailableMoves.push_back({{this->position[0],this->position[1]-2}});
            }
            if (board->getGrid({{this->position[0],this->position[1]-1}})->getPiece()==nullptr)
            {
                AvailableMoves.push_back({{this->position[0],this->position[1]-1}});
            }
            if(board->getGrid({this->position[0]-1,this->position[1]-1})->getPiece() != nullptr && board->getGrid({this->position[0]-1,this->position[1]-1})->getPiece()->getColor() != this->color)
            {
                AvailableMoves.push_back({this->position[0]-1,this->position[1]-1});
            }
            if(board->getGrid({this->position[0]+1,this->position[1]-1})->getPiece() != nullptr && board->getGrid({this->position[0]+1,this->position[1]-1})->getPiece()->getColor() != this->color)
            {
                AvailableMoves.push_back({this->position[0]+1,this->position[1]-1});
            }
        }
        if(this->color == true)
        {
            if(isFirstTime == true)
            {
                AvailableMoves.push_back({{this->position[0],this->position[1]+1}});
                AvailableMoves.push_back({{this->position[0],this->position[1]+2}});
            }
            if(board->getGrid({this->position[0],this->position[1]+1})->getPiece() == nullptr)
            {
                AvailableMoves.push_back({{this->position[0],this->position[1]+1}});
            }
            if(board->getGrid({this->position[0]+1,this->position[1]+1})->getPiece() != nullptr && board->getGrid({this->position[0]+1,this->position[1]+1})->getPiece()->getColor() != this->color)
            {
                AvailableMoves.push_back({this->position[0]+1,this->position[1]+1});
            }
            if(board->getGrid({this->position[0]-1,this->position[1]+1})->getPiece() != nullptr && board->getGrid({this->position[0]-1,this->position[1]+1})->getPiece()->getColor() != this->color)
            {
                AvailableMoves.push_back({this->position[0]-1,this->position[1]+1});
            }
        }
        return AvailableMoves;
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

#endif //_PAWN_H
