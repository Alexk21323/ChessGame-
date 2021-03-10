#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <ostream>
#include <stack>
#include <vector>

#include <SFML/Graphics.hpp>
#include "grid.h"
#include "piece.h"

class Board
{
    //Display Variables
    sf::Image image;
    sf::Sprite board_sprite;
    sf::Texture board_texture;
    sf::Sprite circle_sprite;
    sf::Texture circle_texture;

    sf::Sprite background_sprite;
    sf::Texture background_texture;
    //black
    sf::Sprite rook_sprite;
    sf::Texture rook_texture;

    sf::Sprite knight_sprite;
    sf::Texture knight_texture;

    sf::Texture bishop_texture;
    sf::Sprite bishop_sprite;

    sf::Texture queen_texture;
    sf::Sprite queen_sprite;

    sf::Texture promotion_texture;
    sf::Sprite promotion_sprite;

    //white
    sf::Sprite wrook_sprite;
    sf::Texture wrook_texture;

    sf::Sprite wknight_sprite;
    sf::Texture wknight_texture;

    sf::Texture wbishop_texture;
    sf::Sprite wbishop_sprite;

    sf::Texture wqueen_texture;
    sf::Sprite wqueen_sprite;

    //undo sprite and texture
    sf::Texture undo_texture;
    sf::Sprite undo_sprite;

    sf::Text turn;
    sf::Font font;

public:
    ~Board(){}
    Board();
    int gameStatus; 
    void startGame();
    Grid *getGrid(std::vector<int> position);
    void setPiece(Piece *piece);
    void setPiece(Piece &piece);
    void setPromotion(Piece *piece);
    bool triggerPromotion = false;
    void showSelection(sf::RenderWindow &window, int x, int y);
    void draw(sf::RenderWindow &window);
    void movePiece(Piece &piece);
    sf::Sprite getBKnight() { return knight_sprite; }
    sf::Sprite getWKnight() { return wknight_sprite; }
    
    std::vector<std::vector<int>> possibleMoves(Piece *piece);
    std::vector<std::vector<Grid *>> grids; //<-----call pieces with this
    std::stack<std::vector<std::vector<int>>> moves;
    std::stack<Piece *> captured;
};

#endif //_BOARD_HS