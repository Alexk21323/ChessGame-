#ifndef _POSSIBLE_MOVE_HPP
#define _POSSIBLE_MOVE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../human.hpp"
#include "../board.h"
#include "../piece.h"

TEST(Possible, wPawnMove)
{
    Board *board = new Board();
    Piece* piece = new Pawn({0, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({0,5});
    expected.push_back({0,4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove)
{
    Board *board = new Board();
    Piece* piece = new Pawn({1, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({1,2});
    expected.push_back({1,3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}
TEST(Possible, wPawnMove1)
{
    Board *board = new Board();
    Piece* piece = new Pawn({1, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({1,5});
    expected.push_back({1,4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove1)
{
    Board *board = new Board();
    Piece* piece = new Pawn({1, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({1,2});
    expected.push_back({1,3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}
TEST(Possible, wPawnMove2)
{
    Board *board = new Board();
    Piece* piece = new Pawn({2, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({2,5});
    expected.push_back({2,4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove2)
{
    Board *board = new Board();
    Piece* piece = new Pawn({2, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({2,2});
    expected.push_back({2,3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}
TEST(Possible, wPawnMove3)
{
    Board *board = new Board();
    Piece* piece = new Pawn({3, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({3,5});
    expected.push_back({3,4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove3)
{
    Board *board = new Board();
    Piece* piece = new Pawn({3, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({3,2});
    expected.push_back({3,3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}


TEST(Possible, wPawnMove4)
{
    Board *board = new Board();
    Piece* piece = new Pawn({4, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({4,5});
    expected.push_back({4,4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove4)
{
    Board *board = new Board();
    Piece* piece = new Pawn({4, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({4,2});
    expected.push_back({4,3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}



TEST(Possible, wPawnMove5)
{
    Board *board = new Board();
    Piece* piece = new Pawn({5, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({5,5});
    expected.push_back({5,4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove5)
{
    Board *board = new Board();
    Piece* piece = new Pawn({5, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({5,2});
    expected.push_back({5,3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}


TEST(Possible, wPawnMove6)
{
    Board *board = new Board();
    Piece* piece = new Pawn({6, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({6,5});
    expected.push_back({6,4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove6)
{
    Board *board = new Board();
    Piece* piece = new Pawn({6, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({6,2});
    expected.push_back({6,3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, wPawnMove7)
{
    Board *board = new Board();
    Piece* piece = new Pawn({7, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({7,5});
    expected.push_back({7,4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove7)
{
    Board *board = new Board();
    Piece* piece = new Pawn({7, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({7,2});
    expected.push_back({7,3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}







#endif //_POSSIBLE_MOVE_HPP