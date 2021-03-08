#ifndef _PIECES_H
#define _PIECES_H
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

class Piece
{
public:
    std::vector<int> position;
    std::vector<int> oldPosition;
    bool color;
    int type;
    int x;
    int y;
    bool isFirstTime = true;

    Piece() {}
    //All of the textures needed

    virtual sf::Sprite getSprite() = 0;
    virtual std::vector<int> getPosition() = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    //virtual std::vector<int> getAvailableMoves() = 0;
    bool getColor() { return color; }
    int getType() { return type; }
    //virtual std::vector<int> getAvailableMoves() = 0;
    virtual void setSpriteLocation(int x, int y) = 0;
    std::vector<int> getOld()
    {
        return oldPosition;
    }
    void setFirstTimeMove(bool b)
    {
        isFirstTime = b;
    }

    void setPostion(int x, int y)
    {
        oldPosition = position;
        position[0] = x;
        position[1] = y;
    }
};

#endif //_PIECES_H