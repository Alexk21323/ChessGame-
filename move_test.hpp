#ifndef _MOVE_HPP
#define _MOVE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "human.hpp"
#include "board.h"
#include "piece.h"

TEST(BMovePiece, pawn)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({0, 1}, false);
    EXPECT_EQ(pawn->getPosition()[0], 0);
    EXPECT_EQ(pawn->getPosition()[1], 1);
    pawn->setPostion(0, 3);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 0);
    EXPECT_EQ(pawn->getPosition()[1], 3);
}
TEST(BMovePiece, pawn2)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({1, 1}, false);
    EXPECT_EQ(pawn->getPosition()[0], 1);
    EXPECT_EQ(pawn->getPosition()[1], 1);

    pawn->setPostion(1, 3);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 1);
    EXPECT_EQ(pawn->getPosition()[1], 3);
}

TEST(BMovePiece, pawn3)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({2, 1}, false);
    EXPECT_EQ(pawn->getPosition()[0], 2);
    EXPECT_EQ(pawn->getPosition()[1], 1);

    pawn->setPostion(2, 3);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 2);
    EXPECT_EQ(pawn->getPosition()[1], 3);
}
TEST(BMovePiece, pawn4)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({3, 1}, false);
    EXPECT_EQ(pawn->getPosition()[0], 3);
    EXPECT_EQ(pawn->getPosition()[1], 1);

    pawn->setPostion(3, 3);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 3);
    EXPECT_EQ(pawn->getPosition()[1], 3);
}

TEST(BMovePiece, pawn5)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({4, 1}, false);
    EXPECT_EQ(pawn->getPosition()[0], 4);
    EXPECT_EQ(pawn->getPosition()[1], 1);

    pawn->setPostion(4, 3);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 4);
    EXPECT_EQ(pawn->getPosition()[1], 3);
}
TEST(BMovePiece, pawn6)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({5, 1}, false);
    EXPECT_EQ(pawn->getPosition()[0], 5);
    EXPECT_EQ(pawn->getPosition()[1], 1);

    pawn->setPostion(5, 3);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 5);
    EXPECT_EQ(pawn->getPosition()[1], 3);
}
TEST(BMovePiece, pawn7)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({6, 1}, false);
    EXPECT_EQ(pawn->getPosition()[0], 6);
    EXPECT_EQ(pawn->getPosition()[1], 1);

    pawn->setPostion(6, 3);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 6);
    EXPECT_EQ(pawn->getPosition()[1], 3);
}
TEST(BMovePiece, pawn8)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({7, 1}, false);
    EXPECT_EQ(pawn->getPosition()[0], 7);
    EXPECT_EQ(pawn->getPosition()[1], 1);

    pawn->setPostion(7, 3);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 7);
    EXPECT_EQ(pawn->getPosition()[1], 3);
}

//White piece move
TEST(WMovePiece, pawn)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({0, 6}, true);
    EXPECT_EQ(pawn->getPosition()[0], 0);
    EXPECT_EQ(pawn->getPosition()[1], 6);

    pawn->setPostion(0, 4);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 0);
    EXPECT_EQ(pawn->getPosition()[1], 4);
}
TEST(WMovePiece, pawn1)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({1, 6}, true);
    EXPECT_EQ(pawn->getPosition()[0], 1);
    EXPECT_EQ(pawn->getPosition()[1], 6);

    pawn->setPostion(1, 4);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 1);
    EXPECT_EQ(pawn->getPosition()[1], 4);
}

TEST(WMovePiece, pawn3)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({2, 6}, true);
    EXPECT_EQ(pawn->getPosition()[0], 2);
    EXPECT_EQ(pawn->getPosition()[1], 6);

    pawn->setPostion(2, 4);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 2);
    EXPECT_EQ(pawn->getPosition()[1], 4);
}
TEST(WMovePiece, pawn4)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({3, 6}, true);
    EXPECT_EQ(pawn->getPosition()[0], 3);
    EXPECT_EQ(pawn->getPosition()[1], 6);

    pawn->setPostion(3, 4);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 3);
    EXPECT_EQ(pawn->getPosition()[1], 4);
}

TEST(WMovePiece, pawn5)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({4, 6}, true);
    EXPECT_EQ(pawn->getPosition()[0], 4);
    EXPECT_EQ(pawn->getPosition()[1], 6);

    pawn->setPostion(4, 4);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 4);
    EXPECT_EQ(pawn->getPosition()[1], 4);
}
TEST(WMovePiece, pawn6)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({5, 6}, true);
    EXPECT_EQ(pawn->getPosition()[0], 5);
    EXPECT_EQ(pawn->getPosition()[1], 6);

    pawn->setPostion(5, 4);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 5);
    EXPECT_EQ(pawn->getPosition()[1], 4);
}

TEST(WMovePiece, pawn7)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({6, 6}, true);
    EXPECT_EQ(pawn->getPosition()[0], 6);
    EXPECT_EQ(pawn->getPosition()[1], 6);

    pawn->setPostion(6, 4);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 6);
    EXPECT_EQ(pawn->getPosition()[1], 4);
}
TEST(WMovePiece, pawn8)
{
    Board *board = new Board();
    Piece *pawn = new Pawn({7, 6}, true);
    EXPECT_EQ(pawn->getPosition()[0], 7);
    EXPECT_EQ(pawn->getPosition()[1], 6);

    pawn->setPostion(7, 4);
    board->movePiece(*pawn);
    EXPECT_EQ(pawn->getPosition()[0], 7);
    EXPECT_EQ(pawn->getPosition()[1], 4);
}

//remainer of black pieces
TEST(Black, rook)
{
    Board *board = new Board();
    Piece *piece = new Rook({0, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 0);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(0, 4);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 0);
    EXPECT_EQ(piece->getPosition()[1], 4);
}
TEST(Black, knight)
{
    Board *board = new Board();
    Piece *piece = new Knight({1, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 1);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(2, 2);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 2);
    EXPECT_EQ(piece->getPosition()[1], 2);
}
TEST(Black, bishop)
{
    Board *board = new Board();
    Piece *piece = new Bishop({2, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 2);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(6, 4);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 6);
    EXPECT_EQ(piece->getPosition()[1], 4);
}

TEST(Black, queen)
{
    Board *board = new Board();
    Piece *piece = new Queen({3, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(3, 2);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 2);
}

TEST(Black, king)
{
    Board *board = new Board();
    Piece *piece = new King({4, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 4);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(3, 2);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 2);
}
TEST(Black, bishop2)
{
    Board *board = new Board();
    Piece *piece = new Bishop({5, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 5);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(3, 2);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 2);
}
TEST(Black, knight2)
{
    Board *board = new Board();
    Piece *piece = new Knight({6, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 6);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(3, 2);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 2);
}
TEST(Black, rook2)
{
    Board *board = new Board();
    Piece *piece = new Rook({7, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 7);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(3, 2);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 2);
}

TEST(White, rook)
{
    Board *board = new Board();
    Piece *piece = new Rook({0, 0}, true);

    EXPECT_EQ(piece->getPosition()[0], 0);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(0, 4);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 0);
    EXPECT_EQ(piece->getPosition()[1], 4);
}
TEST(White, knight)
{
    Board *board = new Board();
    Piece *piece = new Knight({1, 0}, true);

    EXPECT_EQ(piece->getPosition()[0], 1);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(2, 2);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 2);
    EXPECT_EQ(piece->getPosition()[1], 2);
}
TEST(White, bishop)
{
    Board *board = new Board();
    Piece *piece = new Bishop({2, 0}, true);

    EXPECT_EQ(piece->getPosition()[0], 2);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(6, 4);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 6);
    EXPECT_EQ(piece->getPosition()[1], 4);
}

TEST(White, queen)
{
    Board *board = new Board();
    Piece *piece = new Queen({3, 0}, true);

    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(3, 2);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 2);
}

TEST(White, king)
{
    Board *board = new Board();
    Piece *piece = new King({4, 0}, true);

    EXPECT_EQ(piece->getPosition()[0], 4);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(3, 2);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 2);
}
TEST(White, bishop2)
{
    Board *board = new Board();
    Piece *piece = new Bishop({5, 0}, true);

    EXPECT_EQ(piece->getPosition()[0], 5);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(3, 2);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 2);
}
TEST(White, knight2)
{
    Board *board = new Board();
    Piece *piece = new Knight({6, 0}, true);

    EXPECT_EQ(piece->getPosition()[0], 6);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(3, 2);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 2);
}
TEST(White, rook2)
{
    Board *board = new Board();
    Piece *piece = new Rook({7, 0}, true);

    EXPECT_EQ(piece->getPosition()[0], 7);
    EXPECT_EQ(piece->getPosition()[1], 0);

    piece->setPostion(3, 2);
    board->movePiece(*piece);
    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 2);
}

#endif //_TEST_HPP