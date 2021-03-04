#include "board.h"
#include "pawn.hpp"
Board::Board(){
    int grid_position = 1; 
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j ++){
            grids.push_back(new Grid(grid_position, i *100, j*100 ));
            grid_position += 1;
        }
    }   
}

void Board::setPiece(Piece* piece){
    if(piece != nullptr) 
        setPiece(*piece);
}

void Board::setPiece(Piece& piece){ 
    int position;
    if(grids[piece.getPosition()]->isEmpty()){
        position = piece.getPosition();
        delete grids[position];
        grids[position] = new Grid(piece);
    }
    else{ 
        position = piece.getPosition();
        grids[position] = new Grid(piece);
    }
}
Grid* Board::getGrid(int position){
    if(position < 1 || position > 64)
        throw std::invalid_argument("Invalid position");
    else 
        return grids[position];
}

Grid* Board::operator[](int i){
    return getGrid(i);
}


void Board::draw(sf::RenderWindow &window){
    sf::Texture board_texture;
    sf::Sprite board_sprite;
    board_texture.loadFromFile("Board.png");
    board_sprite.setTexture(board_texture);
    board_sprite.setPosition(0,0);
    
    sf::Vector2f targetSize(800.0f, 800.0f);
    
    board_sprite.setScale(
        targetSize.x / board_sprite.getGlobalBounds().width,
        targetSize.y / board_sprite.getGlobalBounds().height
    );
    window.draw(board_sprite);
    window.draw(grids[1]->getPiece()->getSprite());
}

void Board::startGame(){
    // Black side 
    this->setPiece(new Pawn(1));
    
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



/*

    1 -> 0-99.99 * 0-99.99
    x/100 
    y/100  






*/