#include "board.h"
#include "pawn.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"
#include <vector>

Board::Board()
{
    for (int i = 0; i < 8; i++)
    {
        std::vector<Grid *> temp;
        for (int j = 0; j < 8; j++)
        {
            std::vector<int> gridPos;
            gridPos.push_back(j);
            gridPos.push_back(i);
            temp.push_back(new Grid(gridPos, i * 100, j * 100));
        }
        grids.push_back(temp);
    }

    board_texture.loadFromFile("Board.png");
    board_sprite.setTexture(board_texture);
    board_sprite.setPosition(0, 0);

    sf::Vector2f targetSize(800.0f, 800.0f);

    board_sprite.setScale(
        targetSize.x / board_sprite.getGlobalBounds().width,
        targetSize.y / board_sprite.getGlobalBounds().height);

    circle_texture.loadFromFile("Sprites/square.png");
    circle_sprite.setTexture(circle_texture);
    sf::Vector2f targetSizeCircle(100.0f, 100.0f);

    circle_sprite.setScale(
        targetSizeCircle.x / circle_sprite.getGlobalBounds().width,
        targetSizeCircle.y / circle_sprite.getGlobalBounds().height);
}

void Board::setPiece(Piece *piece)
{
    if (piece != nullptr)
        setPiece(*piece);
}

void Board::setPiece(Piece &piece)
{
    std::vector<int> position;
    std::vector<int> gridPos;
    std::vector<int> temp = piece.getPosition();
    std::vector<int> old = piece.getOld();
    int x = grids[temp[0]][temp[1]]->GetCoordinates()[0];
    int y = grids[temp[0]][temp[1]]->GetCoordinates()[1];
    if (grids[temp[0]][temp[1]]->isEmpty())
    {
        position = piece.getPosition();
        delete grids[temp[0]][temp[1]];
        grids[position[0]][position[1]] = new Grid(piece, x, y);
    }
    else
    {
        position = piece.getPosition();
        delete grids[temp[0]][temp[1]];
        grids[position[0]][position[1]] = new Grid(piece, x, y);
    }
}
void Board::movePiece(Piece &piece)
{
    std::vector<int> position;
    std::vector<int> gridPos;
    std::vector<int> temp = piece.getPosition();
    std::vector<int> old = piece.getOld();
    int x = grids[temp[0]][temp[1]]->GetCoordinates()[0];
    int y = grids[temp[0]][temp[1]]->GetCoordinates()[1];
    if (grids[temp[0]][temp[1]]->isEmpty())
    {
        position = piece.getPosition();
        delete grids[temp[0]][temp[1]];
        grids[position[0]][position[1]] = new Grid(piece, x, y);
        delete grids[old[0]][old[1]];
        grids[old[0]][old[1]] = new Grid(old, old[0] * 100, old[1] * 100);
    }
    else
    {
        position = piece.getPosition();
        delete grids[temp[0]][temp[1]];
        grids[position[0]][position[1]] = new Grid(piece, x, y);
        delete grids[old[0]][old[1]];
        grids[old[0]][old[1]] = new Grid(old, old[0] * 100, old[1] * 100);
    }
    if (piece.getType() == 0)
    {
        piece.setFirstTimeMove(false);
    }
}
Grid *Board::getGrid(std::vector<int> position)
{
    if (position[0] < -1 || position[0] > 8)
        throw std::invalid_argument("Invalid position");
    if (position[1] < -1 || position[1] > 8)
        throw std::invalid_argument("Invalid position");
    else
    {
        return grids[position[0]][position[1]];
    }
}

void Board::draw(sf::RenderWindow &window)
{
    window.draw(board_sprite);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (grids[i][j]->getPiece() != nullptr)
            {
                window.draw(grids[i][j]->getPiece()->getSprite());
            }
        }
    }
}

void Board::showSelection(sf::RenderWindow &window, int x, int y)
{
    std::vector<std::vector<int>> showMoves;
    showMoves = possibleMoves(grids[x][y]->getPiece());
    for (int i = 0; i < showMoves.size(); i++)
    {
        circle_sprite.setPosition(showMoves[i][0] * 100, showMoves[i][1] * 100);
        window.draw(circle_sprite);
    }
}

void Board::startGame()
{
    //Black side
    this->setPiece(new Rook({0, 0}, false));
    this->setPiece(new Knight({1, 0}, false));
    this->setPiece(new Bishop({2, 0}, false));
    this->setPiece(new Queen({3, 0}, false));
    this->setPiece(new King({4, 0}, false));
    this->setPiece(new Bishop({5, 0}, false));
    this->setPiece(new Knight({6, 0}, false));
    this->setPiece(new Rook({7, 0}, false));
    //White side
    for (int i = 0; i <= 7; i++)
    {
        this->setPiece(new Pawn({i, 1}, false));
    }
    this->setPiece(new Rook({0, 7}, true));
    this->setPiece(new Knight({1, 7}, true));
    this->setPiece(new Bishop({2, 7}, true));
    this->setPiece(new Queen({3, 7}, true));
    this->setPiece(new King({4, 7}, true));
    this->setPiece(new Bishop({5, 7}, true));
    this->setPiece(new Knight({6, 7}, true));
    this->setPiece(new Rook({7, 7}, true));
    for (int i = 0; i <= 7; i++)
    {
        this->setPiece(new Pawn({i, 6}, true));
    }
}

std::vector<std::vector<int>> Board::possibleMoves(Piece *piece)
{
    std::vector<std::vector<int>> AvailableMoves;
    switch (piece->getType())
    {
    case 0: //Pawn
    {
        //Piece* p = new Pawn(piece->getPosition(),piece->getColor());
        if (piece->color == true)
        {
            if (piece->isFirstTime == true)
            {
                AvailableMoves.push_back({{piece->position[0], piece->position[1] - 1}});
                AvailableMoves.push_back({{piece->position[0], piece->position[1] - 2}});
            }
            else if (piece->isFirstTime == false)
            {
                if (this->getGrid({piece->position[0], piece->position[1] - 1})->getPiece() == nullptr)
                {
                    AvailableMoves.push_back({{piece->position[0], piece->position[1] - 1}});
                }
                if (piece->position[0] != 7)
                {
                    if (this->getGrid({piece->position[0] + 1, piece->position[1] - 1})->getPiece() != nullptr && this->getGrid({piece->position[0] + 1, piece->position[1] - 1})->getPiece()->getColor() != piece->color)
                    {
                        AvailableMoves.push_back({piece->position[0] + 1, piece->position[1] - 1});
                    }
                }
                if (piece->position[0] != 0)
                {
                    if (this->getGrid({piece->position[0] - 1, piece->position[1] - 1})->getPiece() != nullptr && this->getGrid({piece->position[0] - 1, piece->position[1] - 1})->getPiece()->getColor() != piece->color)
                    {
                        AvailableMoves.push_back({piece->position[0] - 1, piece->position[1] - 1});
                    }
                }
            }
        }
        if (piece->color == false)
        {
            if (piece->isFirstTime == true)
            {
                AvailableMoves.push_back({{piece->position[0], piece->position[1] + 1}});
                AvailableMoves.push_back({{piece->position[0], piece->position[1] + 2}});
            }
            else if (piece->isFirstTime == false)
            {
                if (this->getGrid({piece->position[0], piece->position[1] + 1})->getPiece() == nullptr)
                {
                    AvailableMoves.push_back({{piece->position[0], piece->position[1] + 1}});
                }
                if (piece->position[0] != 7)
                {
                    if (this->getGrid({piece->position[0] + 1, piece->position[1] + 1})->getPiece() != nullptr && this->getGrid({piece->position[0] + 1, piece->position[1] + 1})->getPiece()->getColor() != piece->color)
                    {
                        AvailableMoves.push_back({piece->position[0] + 1, piece->position[1] + 1});
                    }
                }
                if (piece->position[0] != 0)
                {
                    if (this->getGrid({piece->position[0] - 1, piece->position[1] + 1})->getPiece() != nullptr && this->getGrid({piece->position[0] - 1, piece->position[1] + 1})->getPiece()->getColor() != piece->color)
                    {
                        AvailableMoves.push_back({piece->position[0] - 1, piece->position[1] + 1});
                    }
                }
            }
        }
        return AvailableMoves;
        break;
    }
    case 1: //Rook
    {
        //to the vertical movement movement
         for (int i = 1; i <= 7; i++)
        {
            if (piece->position[0] <= 7 && piece->position[1]-i >= 0)
            {
                if (this->getGrid({piece->position[0], piece->position[1]-i})->getPiece() == nullptr)
                {
                    AvailableMoves.push_back({piece->position[0], piece->position[1] - i});
                }
                else if (this->getGrid({piece->position[0], piece->position[1] - i})->getPiece()->getColor() != piece->getColor())
                {
                    AvailableMoves.push_back({piece->position[0], piece->position[1] - i});
                    break;
                }
                else if (this->getGrid({piece->position[0], piece->position[1] - i})->getPiece() != nullptr)
                {
                    break;
                }
            }
        }

        return AvailableMoves;
        break;
    }
    case 2: //Knight
    {
        //bottom side
        if (piece->position[1] + 2 >= 0 && piece->position[1] + 2 <= 7)
        {
            //bottom right
            if (piece->position[0] + 1 >= 0 && piece->position[0] + 1 <= 7)
            {
                if (this->getGrid({piece->position[0] + 1, piece->position[1] + 2})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] + 1, piece->position[1] + 2})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] + 1, piece->position[1] + 2});
            }
            //bottom left
            if (piece->position[0] - 1 >= 0 && piece->position[0] - 1 <= 7)
            {
                if (this->getGrid({piece->position[0] - 1, piece->position[1] + 2})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] - 1, piece->position[1] + 2})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] - 1, piece->position[1] + 2});
            }
        }
        //top side
        if (piece->position[1] - 2 >= 0 && piece->position[1] - 2 <= 7)
        {
            //top right
            if (piece->position[0] + 1 >= 0 && piece->position[0] + 1 <= 7)
            {
                if (this->getGrid({piece->position[0] + 1, piece->position[1] - 2})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] + 1, piece->position[1] - 2})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] + 1, piece->position[1] - 2});
            }
            //bottom left
            if (piece->position[0] - 1 >= 0 && piece->position[0] - 1 <= 7)
            {
                if (this->getGrid({piece->position[0] - 1, piece->position[1] - 2})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] - 1, piece->position[1] - 2})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] - 1, piece->position[1] - 2});
            }
        }
        //left side
        if (piece->position[0] - 2 >= 0 && piece->position[0] - 2 <= 7)
        {
            //left bottom
            if (piece->position[1] + 1 >= 0 && piece->position[1] + 1 <= 7)
            {
                if (this->getGrid({piece->position[0] - 2, piece->position[1] + 1})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] - 2, piece->position[1] + 1})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] - 2, piece->position[1] + 1});
            }
            //left top
            if (piece->position[1] - 1 >= 0 && piece->position[1] - 1 <= 7)
            {
                if (this->getGrid({piece->position[0] - 2, piece->position[1] - 1})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] - 2, piece->position[1] - 1})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] - 2, piece->position[1] - 1});
            }
        }
        //right side
        if (piece->position[0] + 2 >= 0 && piece->position[0] + 2 <= 7)
        {
            //left bottom
            if (piece->position[1] + 1 >= 0 && piece->position[1] + 1 <= 7)
            {
                if (this->getGrid({piece->position[0] - 2, piece->position[1] + 1})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] - 2, piece->position[1] + 1})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] + 2, piece->position[1] + 1});
            }
            //left top
            if (piece->position[1] - 1 >= 0 && piece->position[1] - 1 <= 7)
            {
                if (this->getGrid({piece->position[0] - 2, piece->position[1] - 1})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] - 2, piece->position[1] - 1})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] + 2, piece->position[1] - 1});
            }
        }
        return AvailableMoves;
        break;
    }

    case 3: //Bishop
    {
        //bottom left to top right
        for (int i = 1; i <= 7; i++)
        {
            if (piece->position[0] + i <= 7 && piece->position[1] - i >= 0)
            {
                if (this->getGrid({piece->position[0] + i, piece->position[1] - i})->getPiece() == nullptr)
                {
                    AvailableMoves.push_back({piece->position[0] + i, piece->position[1] - i});
                }
                else if (this->getGrid({piece->position[0] + i, piece->position[1] - i})->getPiece()->getColor() != piece->getColor())
                {
                    AvailableMoves.push_back({piece->position[0] + i, piece->position[1] - i});
                    break;
                }
                else if (this->getGrid({piece->position[0] + i, piece->position[1] - i})->getPiece() != nullptr)
                {
                    break;
                }
            }
        }
        //bottom right to top left
        for (int i = 1; i <= 7; i++)
        {
            if (piece->position[0] - i >= 0 && piece->position[1] - i >= 0)
            {
                if (this->getGrid({piece->position[0] - i, piece->position[1] - i})->getPiece() == nullptr)
                {
                    AvailableMoves.push_back({piece->position[0] - i, piece->position[1] - i});
                }
                else if (this->getGrid({piece->position[0] - i, piece->position[1] - i})->getPiece()->getColor() != piece->getColor())
                {
                    AvailableMoves.push_back({piece->position[0] - i, piece->position[1] - i});
                    break;
                }
                else if (this->getGrid({piece->position[0] - i, piece->position[1] - i})->getPiece() != nullptr)
                {
                    break;
                }
            }
        }

        //top left to bottom right
        for (int i = 1; i <= 7; i++)
        {
            if (piece->position[0] + i <= 7 && piece->position[1] + i <= 7)
            {
                if (this->getGrid({piece->position[0] + i, piece->position[1] + i})->getPiece() == nullptr)
                {
                    AvailableMoves.push_back({piece->position[0] + i, piece->position[1] + i});
                }
                else if (this->getGrid({piece->position[0] + i, piece->position[1] + i})->getPiece()->getColor() != piece->getColor())
                {
                    AvailableMoves.push_back({piece->position[0] + i, piece->position[1] + i});
                    break;
                }
                else if (this->getGrid({piece->position[0] + i, piece->position[1] + i})->getPiece() != nullptr)
                {
                    break;
                }
            }
        }

        //top right to bottom left
        for (int i = 1; i <= 7; i++)
        {
            if (piece->position[0] - i >= 0 && piece->position[1] + i <= 7)
            {
                if (this->getGrid({piece->position[0] - i, piece->position[1] + i})->getPiece() == nullptr)
                {
                    AvailableMoves.push_back({piece->position[0] - i, piece->position[1] + i});
                }
                else if (this->getGrid({piece->position[0] - i, piece->position[1] + i})->getPiece()->getColor() != piece->getColor())
                {
                    AvailableMoves.push_back({piece->position[0] - i, piece->position[1] + i});
                    break;
                }
                else if (this->getGrid({piece->position[0] - i, piece->position[1] + i})->getPiece() != nullptr)
                {
                    break;
                }
            }
        }

        return AvailableMoves;
        break;
    }
    case 5: //King
    {
        //bottom 3 block check and sides
        if (piece->position[1] + 1 >= 0 && piece->position[1] + 1 <= 7)
        { //bottom
            if (this->getGrid({piece->position[0], piece->position[1] + 1})->getPiece() == nullptr ||
                this->getGrid({piece->position[0], piece->position[1] + 1})->getPiece()->getColor() != piece->getColor())
                AvailableMoves.push_back({piece->position[0], piece->position[1] + 1});
            if (piece->position[0] + 1 >= 0 && piece->position[0] + 1 <= 7)
            {
                //bottom right
                if (this->getGrid({piece->position[0] + 1, piece->position[1] + 1})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] + 1, piece->position[1] + 1})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] + 1, piece->position[1] + 1});
                //right
                if (this->getGrid({piece->position[0] + 1, piece->position[1]})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] + 1, piece->position[1]})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] + 1, piece->position[1]});
            }
            if (piece->position[0] - 1 >= 0 && piece->position[0] - 1 <= 7)
            {
                //bottom left
                if (this->getGrid({piece->position[0] - 1, piece->position[1] + 1})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] - 1, piece->position[1] + 1})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] - 1, piece->position[1] + 1});
                //left
                if (this->getGrid({piece->position[0] - 1, piece->position[1]})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] - 1, piece->position[1]})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] - 1, piece->position[1]});
            }
        }
        //top 3 block check
        if (piece->position[1] - 1 >= 0 && piece->position[1] - 1 <= 7)
        {
            //top
            if (this->getGrid({piece->position[0], piece->position[1] - 1})->getPiece() == nullptr ||
                this->getGrid({piece->position[0], piece->position[1] - 1})->getPiece()->getColor() != piece->getColor())
                AvailableMoves.push_back({piece->position[0], piece->position[1] - 1});
            if (piece->position[0] + 1 >= 0 && piece->position[0] + 1 <= 7)
            {
                //top right
                if (this->getGrid({piece->position[0] + 1, piece->position[1] - 1})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] + 1, piece->position[1] - 1})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] + 1, piece->position[1] - 1});
            }
            if (piece->position[0] - 1 >= 0 && piece->position[0] - 1 <= 7)
            {
                //top left
                if (this->getGrid({piece->position[0] - 1, piece->position[1] - 1})->getPiece() == nullptr ||
                    this->getGrid({piece->position[0] - 1, piece->position[1] - 1})->getPiece()->getColor() != piece->getColor())
                    AvailableMoves.push_back({piece->position[0] - 1, piece->position[1] - 1});
            }
        }
        return AvailableMoves;
        break;
    }
    }
}
