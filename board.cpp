#include "board.h"
#include "pawn.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"
#include <vector>

Board::Board(){
    for(int i = 0; i < 8; i++){
        std::vector <Grid*> temp;
        for(int j = 0; j < 8; j++){
            std::vector<int> gridPos;
            gridPos.push_back(j);
            gridPos.push_back(i);
            temp.push_back(new Grid(gridPos, i *100, j*100 ));
            }
        grids.push_back(temp);
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
    std::vector<int> position;
    std::vector<int> gridPos;
    std::vector<int> temp = piece.getPosition();
    int x = grids[temp[0]][temp[1]]->GetCoordinates()[0];
    int y = grids[temp[0]][temp[1]]->GetCoordinates()[1];
    if(grids[temp[0]][temp[1]]->isEmpty()){
        position = piece.getPosition();
        gridPos = grids[temp[0]][temp[1]]->GetPos();
        delete grids[temp[0]][temp[1]];
        grids[position[0]][position[1]] = new Grid(piece, x, y);
    }

}
Grid* Board::getGrid(std::vector<int> position){
    if(position[0] < 0  || position[0] > 7)
        throw std::invalid_argument("Invalid position");
    if(position[1] < 0  || position[1] > 7)
        throw std::invalid_argument("Invalid position"); 
    else{
        return grids[position[0]][position[1]];
    }
}

void Board::draw(sf::RenderWindow &window){
    window.draw(board_sprite);
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
        if(grids[i][j]->getPiece() != nullptr)
            window.draw(grids[i][j]->getPiece()->getSprite());
        }
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
    
    this->setPiece(new Rook({0, 7}));
    this->setPiece(new Knight({1, 7}));
    this->setPiece(new Bishop({2, 7}));
    this->setPiece(new Queen({3, 7}));
    this->setPiece(new King({4, 7}));
    this->setPiece(new Bishop({5, 7}));
    this->setPiece(new Knight({6, 7}));
    this->setPiece(new Rook({7, 7}));
    for (int i = 0; i <=7 ; i++){
        this->setPiece(new Pawn({i, 6}));
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