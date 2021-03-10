#ifndef _COMPUTER_HPP
#define _COMPUTER_HPP

#include "player.hpp"

class Computer : public Player
{
public:
    int x;
    int y;
    int xPiece;
    int yPiece;

    bool makeMove(int x, int y, Board* board){return false;}
    bool select(int x, int y, Board* board){return false;}

    void makeMove(std::vector<Piece*> piece, Board *board)
    {
        
        std::vector<std::vector<int>> posMove;
        Piece *tmpPiece;
        //get the pieces
        int x = std::rand() % (piece.size());
        posMove = board->possibleMoves(piece[x]);
        while(posMove.empty()){
            int x = std::rand() % (piece.size());
            posMove = board->possibleMoves(piece[x]);
        }
        tmpPiece = piece[x];
        int randCord = std::rand()%(posMove.size());
        std::vector<int> destination = posMove[randCord];
        tmpPiece->setPostion(destination[0], destination[1]);
        board->movePiece(*tmpPiece);

    }

    //generate the random move
    std::vector<Piece *> selectValidPieces(Board *board)
    {
        /*
            After called
            go through board and select the invalid pieces
            in this case black and return a piece vector
            then generate rando

        */
        std::vector<Piece *> validPieces;
        for (int i = 0; i < board->grids.size(); i++)
        {
            for (int j = 0; j < board->grids[i].size(); j++)
            {
                if(board->grids[i][j]->getPiece()!= nullptr)
                {
                    if (board->grids[i][j]->getPiece()->getColor() == false)
                        validPieces.push_back(board->grids[i][j]->getPiece());
                }
            }
        }
        return validPieces;
    }
};

#endif //_COMPUTER_HPP