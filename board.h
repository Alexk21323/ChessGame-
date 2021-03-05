#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <ostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include "grid.h"
#include "piece.h"

class Board{
//Display Variables
sf::Image image;
sf::Sprite board_sprite;
sf::Texture board_texture;
int x;
int y;

//Member Variabels 
//grids will keep track of what's on the board



public:
~Board();
Board();
void startGame();
Grid* getGrid(int position);
void setPiece(Piece* piece);
void setPiece(Piece& piece);
//void setMoveMaker(Alliance moveMaker);
void draw(sf::RenderWindow &window);
Grid* operator [](int index);
std::vector<Grid*> grids; //<-----call pieces with this

/*32 grids = 32 pieces => access everything else
player 
-Board  => move => int a, int b (a to b)
=>all other grid shit
=> stack of moves <a,b>

=>click will be in board move()

*/

};

#endif //_BOARD_H