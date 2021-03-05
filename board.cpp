#include "board.h"
#include "pawn.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"

Board::Board(){
    int grid_position = 1; 
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            grids.push_back(new Grid(grid_position, j *100, i*100 ));
            grid_position += 1;
            }
        }
     
    board_texture.loadFromFile("Board.png");
    board_sprite.setTexture(board_texture);
    board_sprite.setPosition(0,0);
    
    sf::Vector2f targetSize(800.0f, 800.0f);
    
    board_sprite.setScale(
        targetSize.x / board_sprite.getGlobalBounds().width,
        targetSize.y / board_sprite.getGlobalBounds().height
    );
}

void Board::setPiece(Piece* piece){
    if(piece != nullptr) 
        setPiece(*piece);
}

void Board::setPiece(Piece& piece){ 
    int position;
    int x;
    int y;
    if(grids[piece.getPosition()-1]->isEmpty()){
        position = piece.getPosition();
        x = grids[position-1]->GetX();
        y = grids[position-1]->GetY();
        delete grids[position-1];
        grids[position-1] = new Grid(piece, x, y);
    }

}
Grid* Board::getGrid(int position){
    if(position < 1 || position > 64)
        throw std::invalid_argument("Invalid position");
    else 
        return grids[position-1];
}

Grid* Board::operator[](int i){
    return getGrid(i);
}

void Board::draw(sf::RenderWindow &window){
    window.draw(board_sprite);
    for(int i = 0; i < grids.size(); i++){
        if(grids[i]->getPiece() != nullptr)
            window.draw(grids[i]->getPiece()->getSprite());
    }
}
void Board::startGame(){
    // this->setPiece(new Pawn(1));
    // this->setPiece(new Pawn(2));
    // this->setPiece(new Pawn(3));
    // this->setPiece(new Pawn(4));
    // this->setPiece(new Pawn(5));
    // this->setPiece(new Pawn(6));

    // board.setPiece(new Knight(Alliance::Black, 2));
    // board.setPiece(new Bishop(Alliance::Black, 3));
    // board.setPiece(new Queen(Alliance::Black, 4));
    // board.setPiece(new King(Alliance::Black, 5));
    // board.setPiece(new Bishop(Alliance::Black, 6));
    // board.setPiece(new Knight(Alliance::Black, 7));
    // board.setPiece(new Rook(Alliance::Black, 8));
    // for (int i = 9; i<= 16; i++){
    //     board.setPiece(new Rook(Alliance::Black, i));
    // }
    // //White Side 
    this->setPiece(new Rook(57));
    this->setPiece(new Knight(58));
    this->setPiece(new Bishop(59));
    this->setPiece(new Queen(60));
    this->setPiece(new King(61));
    this->setPiece(new Bishop(62));
    this->setPiece(new Knight(63));
    this->setPiece(new Rook(64));
    for (int i = 49; i<= 56; i++){
        this->setPiece(new Pawn(i));
    }

}

/*
   

    pawn
    calcPossibleMoves return a vector of moves
    getMove()
    
    p-> click -> position ->getGrid(position) = piece 
    piece.getMovement(get possible vector of moves which in position, draw circle on these position)
    second click get another position, check of position contain in possible move vector 
    if contains invoke move(x,y) 
    

    pawn(int, int pos)
    if()



*/