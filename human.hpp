#ifndef _HUMAN_HPP
#define _HUMAN_HPP

#include "player.hpp"

class Human : public Player
{

public:
    int x;
    int y;
    int xPiece;
    int yPiece;
    std::vector<std::vector<int>> posMove;
    bool select(int x, int y, Board *board)
    {
        Piece *tmpPiece;
        this->xPiece = x / 100;
        this->yPiece = y / 100;
        if( board->getGrid({xPiece, yPiece})->getPiece()== nullptr){
            return false;
        }
        tmpPiece = board->getGrid({xPiece, yPiece})->getPiece();
        std::cout<<"coord "<<xPiece<<"\t"<<yPiece<<std::endl;
        posMove = board->possibleMoves(tmpPiece);
        for (int i = 0; i < posMove.size(); i++)
        { 
            std::cout <<"possible";
            for (int j = 0; j < posMove[i].size(); j++)
            {
                std::cout<<posMove[i][j];
            }
            std::cout << "\n";
        }
        if (!posMove.empty())
        {
            return true;
        }
        else 
            return false;

    }
    bool makeMove(int mouseX, int mouseY, Board *board)
    {
        bool flag = false;
        this->x = mouseX;
        this->y = mouseY;
        int destinationX = x / 100;
        int destinationY = y / 100;
        Piece *tmpPiece;
        std::vector<int> destination;
        destination.push_back(destinationX);
        destination.push_back(destinationY);
       
        if (board->getGrid({xPiece, yPiece})->getPiece() != nullptr)
        {
            if (xPiece != destinationX || yPiece != destinationY)
            {
                tmpPiece = board->getGrid({xPiece, yPiece})->getPiece();
                for (int i = 0; i < posMove.size(); i++)
                {
                    if (posMove.at(i) == destination)
                    {
                        tmpPiece->setPostion(destinationX, destinationY);
                        board->movePiece(*tmpPiece);
                        if (tmpPiece->getColor() == false && destinationY == 7 && tmpPiece->getType() == 0)
                        {
                            board->triggerPromotion = true;
                            board->setPromotion(tmpPiece);
                        }
                        if (tmpPiece->getColor() == true && destinationY == 0 && tmpPiece->getType() == 0)
                        {
                            board->triggerPromotion = true;
                             board->setPromotion(tmpPiece);
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

#endif //_HUMAN_HPP