#ifndef _PIECE_SPRITE_H
#define _PIECE_SPRITE_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class pieceSprite{
public:

//Black pieces texture
static sf::Texture bKing;
static sf::Texture bQueen;
static sf::Texture bRook;
static sf::Texture bKnight;
static sf::Texture bBishop;
static sf::Texture bPawn;

static sf::Texture wKing;
static sf::Texture wQueen;
static sf::Texture wRook;
static sf::Texture wKnight;
static sf::Texture wBishop;
static sf::Texture wPawn;

static sf::Texture createSprite(std::string str);


};









#endif //_PIECE_SPRITE_H