#include "board.h"
#include "pawn.hpp"
#include "knight.hpp"
#include "rook.hpp"
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
    // Black side 
    for(int i = 9; i <=16; i++){
        this->setPiece(new Pawn(i,"Black"));
    }
    this->setPiece(new Knight(2,"Black"));
    this->setPiece(new Knight(7,"Black"));
    this->setPiece(new Rook(1,"Black"));
    this->setPiece(new Rook(8,"Black"));
    this->setPiece(new Bishop(3,"Black"));
    this->setPiece(new Bishop(6,"Black"));
    this->setPiece(new Queen(4,"Black"));
    this->setPiece(new King(5,"Black"));
    // White side
    for(int i = 49; i <=56; i++){
        this->setPiece(new Pawn(i,"White"));
    }
    this->setPiece(new Knight(63,"White"));
    this->setPiece(new Knight(58,"White"));
    this->setPiece(new Rook(64,"White"));
    this->setPiece(new Rook(57,"White"));
    this->setPiece(new Bishop(59,"White"));
    this->setPiece(new Bishop(62,"White"));
    this->setPiece(new Queen(60,"White"));
    this->setPiece(new King(61,"White"));

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
    // board.setPiece(new Rook(Alliance::White, 57));
    // board.setPiece(new Knight(Alliance::White, 58));
    // board.setPiece(new Bishop(Alliance::White, 59));
    // board.setPiece(new Queen(Alliance::White, 60));
    // board.setPiece(new King(Alliance::White, 61));
    // board.setPiece(new Bishop(Alliance::White, 62));
    // board.setPiece(new Knight(Alliance::White, 63));
    // board.setPiece(new Rook(Alliance::White, 64));
    // for (int i = 49; i<= 56; i++){
    //     board.setPiece(new Rook(Alliance::Black, i));
    // }

    //Board* board = new Board();
}
