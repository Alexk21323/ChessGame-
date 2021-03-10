#ifndef _UNDO_HPP
#define _UNDO_HPP
#include "board.h"
#include <vector>
#include <map>

class Undo
{
public:
    // bool activated;
    void undo(Board *board)
    {
        if (board->moves.size() != 0)
        {
            std::vector<std::vector<int>> move = board->moves.top();
            //Revert moved piece to old position
            Piece *temp = board->grids[move[1][0]][move[1][1]]->getPiece();
            if (temp->getType() == 0)
            {                
                if (temp->moveCount == 1){
                    temp->isFirstTime = true;
                }
                temp->moveCount--;
            }
            temp->setPositionUndo(move[0][0], move[0][1]);
            delete board->grids[move[0][0]][move[0][1]];
            int x = move[0][0] * 100;
            int y = move[0][1] * 100;
            board->grids[move[0][0]][move[0][1]] = new Grid(temp);
            board->moves.pop();
            //Spawn captured piece to original position
            if (board->captured.size() != 0)
            {
                Piece *temp2 = board->captured.top();
                delete board->grids[move[1][0]][move[1][1]];
                x = move[1][0];
                y = move[1][1];
                if (temp2 == nullptr)
                    board->grids[move[1][0]][move[1][1]] = new Grid({x, y}, x * 100, y * 100);
                else
                    board->grids[move[1][0]][move[1][1]] = new Grid(temp2);
                board->captured.pop();
            }
            // activated = true;
        }
        // else if (board->moves.size() == 0){
        //     activated = false;
        // }
    }
};

#endif //_UNDO_HPP