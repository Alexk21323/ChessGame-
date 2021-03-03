#include "board.h"

typedef Board::Builder Builder;

Builder::Builder(){
    for(int i = 0; i < 64; i++){
        grids.push_back(new Grid(i));
    }
}

Builder& Builder::setPiece(Piece& piece){
    if(grids[piece.getPosition].isEmpty()){
        const int position = piece.getPosition;
        delete grids[position];
        grids[position] = new Grid(piece);
    }
    //deference this pointer 
    return *this;
}

Builder& Builder::setPiece(Piece* piece){
    if(piece != nullptr) 
        setPiece(*piece);
    //deference this pointer 
    return *this;
}

Builder& Builder::setMovemaker(Color moveMaker){
    this->moveMaker = moveMaker;
    return *this;
}

//Board class

Board::Board(){
    this->grids = builder.grids;
    board_texture.loadFromFile("Board.png");
    board_sprite.setTexture(t);
    board_sprite.setPosition(0,0);
    
    sf::Vector2f targetSize(1000.0f, 1000.0f);
    
    board_sprite.setScale(
        targetSize.x / board_sprite.getGlobalBounds().width,
        targetSize.y / board_sprite.getGlobalBounds().height
    );
}

Grid* Board::getGrid(int position){
    if(position < 1 || position > 64)
        throw std::invalid_argument("Invalid position");
    else 
        return grids[position];
}

Grid* Board::operator [](int i){
    return getGrid(i);
}

Board* Board::startGame(){
    //Black side 
    Builder builder = new Builder();
    builder.setPiece(new Rook(Alliance::Black, 1));
    builder.setPiece(new Knight(Alliance::Black, 2));
    builder.setPiece(new Bishop(Alliance::Black, 3));
    builder.setPiece(new Queen(Alliance::Black, 4));
    builder.setPiece(new King(Alliance::Black, 5));
    builder.setPiece(new Bishop(Alliance::Black, 6));
    builder.setPiece(new Knight(Alliance::Black, 7));
    builder.setPiece(new Rook(Alliance::Black, 8));
    for (int i = 9; i<= 16; i++){
        builder.setPiece(new Rook(Alliance::Black, i));
    }
    //White Side 
    builder.setPiece(new Rook(Alliance::White, 57));
    builder.setPiece(new Knight(Alliance::White, 58));
    builder.setPiece(new Bishop(Alliance::White, 59));
    builder.setPiece(new Queen(Alliance::White, 60));
    builder.setPiece(new King(Alliance::White, 61));
    builder.setPiece(new Bishop(Alliance::White, 62));
    builder.setPiece(new Knight(Alliance::White, 63));
    builder.setPiece(new Rook(Alliance::White, 64));
    for (int i = 49; i<= 56; i++){
        builder.setPiece(new Rook(Alliance::Black, i));
    }
    return new Board(*this);
}