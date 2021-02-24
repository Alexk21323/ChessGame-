#include "board.h"
#include "piece.h"d

typedef Board::Builder Builder;

Builder::Builder(){
    for(int i = 0; i < 64; i++){
        tiles.push_back(new Tile(i));
    }
}

Builder& Builder::setPiece(Piece& piece){
    if(tiles[piece.getPosition].isEmpty()){
        const int position = piece.getPosition;
        delete tiles[position];
        tiles[position] = new Tile(piece);
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

//Board 
