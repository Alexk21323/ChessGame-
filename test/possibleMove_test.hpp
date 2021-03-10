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
    Piece *piece = new Pawn({0, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({0, 5});
    expected.push_back({0, 4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove)
{
    Board *board = new Board();
    Piece *piece = new Pawn({1, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({1, 2});
    expected.push_back({1, 3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}
TEST(Possible, wPawnMove1)
{
    Board *board = new Board();
    Piece *piece = new Pawn({1, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({1, 5});
    expected.push_back({1, 4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove1)
{
    Board *board = new Board();
    Piece *piece = new Pawn({1, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({1, 2});
    expected.push_back({1, 3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}
TEST(Possible, wPawnMove2)
{
    Board *board = new Board();
    Piece *piece = new Pawn({2, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({2, 5});
    expected.push_back({2, 4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove2)
{
    Board *board = new Board();
    Piece *piece = new Pawn({2, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({2, 2});
    expected.push_back({2, 3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}
TEST(Possible, wPawnMove3)
{
    Board *board = new Board();
    Piece *piece = new Pawn({3, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({3, 5});
    expected.push_back({3, 4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove3)
{
    Board *board = new Board();
    Piece *piece = new Pawn({3, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({3, 2});
    expected.push_back({3, 3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, wPawnMove4)
{
    Board *board = new Board();
    Piece *piece = new Pawn({4, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({4, 5});
    expected.push_back({4, 4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove4)
{
    Board *board = new Board();
    Piece *piece = new Pawn({4, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({4, 2});
    expected.push_back({4, 3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, wPawnMove5)
{
    Board *board = new Board();
    Piece *piece = new Pawn({5, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({5, 5});
    expected.push_back({5, 4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove5)
{
    Board *board = new Board();
    Piece *piece = new Pawn({5, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({5, 2});
    expected.push_back({5, 3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, wPawnMove6)
{
    Board *board = new Board();
    Piece *piece = new Pawn({6, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({6, 5});
    expected.push_back({6, 4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove6)
{
    Board *board = new Board();
    Piece *piece = new Pawn({6, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({6, 2});
    expected.push_back({6, 3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, wPawnMove7)
{
    Board *board = new Board();
    Piece *piece = new Pawn({7, 6}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({7, 5});
    expected.push_back({7, 4});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bPawnMove7)
{
    Board *board = new Board();
    Piece *piece = new Pawn({7, 1}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({7, 2});
    expected.push_back({7, 3});
    posMove = board->possibleMoves(piece);

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, wRook1)
{
    Board *board = new Board();
    Piece *piece = new Rook({7, 0}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    for(int i = 1; i <8; i++){
        expected.push_back({7, i});
    }
    for(int i = 6; i >= 0; i--){
        expected.push_back({i, 0});
    }
    posMove = board->possibleMoves(piece);
   
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bRook1)
{
    Board *board = new Board();
    Piece *piece = new Rook({7, 7}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    for(int i = 6; i >= 0; i--){
        expected.push_back({7, i});
    }
    for(int i = 6; i >= 0; i--){
        expected.push_back({i, 7});
    }
    posMove = board->possibleMoves(piece);
    
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
    
}
TEST(Possible, wBishop)
{ 
    Board *board = new Board();
    Piece *piece = new Bishop({0, 0}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    for(int i = 1; i <=7; i++){
        expected.push_back({i, i});
        
    }
    
    posMove = board->possibleMoves(piece);
    
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
    
}
TEST(Possible, bBishop)
{ 
    Board *board = new Board();
    Piece *piece = new Bishop({0, 7}, false);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({1,6});
    expected.push_back({2,5});
    expected.push_back({3,4});
    expected.push_back({4,3});
    expected.push_back({5,2});
    expected.push_back({6,1});
    expected.push_back({7,0});
    posMove = board->possibleMoves(piece);
    
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
    
}
TEST(Possible, wKnight)
{
    Board *board = new Board();
    Piece *piece = new Knight({1, 7}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({2, 5});
    expected.push_back({0, 5});
    expected.push_back({3, 6});
    posMove = board->possibleMoves(piece);
   
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, bKnight)
{
    Board *board = new Board();
    Piece *piece = new Knight({1, 0}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({2, 2});
    expected.push_back({0, 2});
    expected.push_back({3, 1});
    posMove = board->possibleMoves(piece);
   
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}
TEST(Possible, wKing)
{
    Board *board = new Board();
    Piece *piece = new King({4, 7}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({4, 6});
    expected.push_back({5, 6});
    expected.push_back({3, 6});
    expected.push_back({5, 7});
    expected.push_back({3, 7});
    
    posMove = board->possibleMoves(piece);
   
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}
TEST(Possible, bQueen)
{
    Board *board = new Board();
    Piece *piece = new Queen({3, 7}, false);
    Piece *knight = new Knight({4, 7}, false);
    Piece *knight1 = new Knight({2, 7}, false);
    Piece *knight2 = new Knight({2, 6}, false);
    Piece *knight3 = new Knight({4, 6}, false);
    Piece *knight4 = new Knight({3, 6}, true);
    board->setPiece(piece);
    board->setPiece(knight);
    board->setPiece(knight1);
    board->setPiece(knight2);
    board->setPiece(knight3);  
    board->setPiece(knight4);

    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({3, 6});


    
    posMove = board->possibleMoves(piece);
   
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}


TEST(Possible, blockedPiecePawn)
{
    Board* board = new Board();
    Piece* pawn = new Pawn({3,5}, false);
    Piece* piece = new Knight({3, 6}, false);
    board->setPiece(piece);
    board->setPiece(pawn);
    
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({3, 7});
    
    posMove = board->possibleMoves(pawn);
   
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}
TEST(Possible, pawnCanCapture)
{
    Board* board = new Board();
    Piece* pawn = new Pawn({3,3}, false);
    Piece* piece = new Knight({4, 4}, true);
    board->setPiece(piece);
    board->setPiece(pawn);

    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({3, 4});
    expected.push_back({3, 5});
    expected.push_back({4, 4});

    posMove = board->possibleMoves(pawn);
   
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}
TEST(Possible, pawnCantCapture)
{
    Board *board = new Board();
    Piece* pawn = new Pawn({3,6}, true);
    Piece *piece = new Knight({4, 5}, true);
    board->setPiece(piece);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({3, 5});
    expected.push_back({3, 4});

    posMove = board->possibleMoves(pawn);
   
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}
TEST(Possible, blockedPieceKnight)
{
    Board *board = new Board();
    Piece *piece = new Knight({1, 7}, true);
    Piece *piece2 = new Knight({2, 5}, true);
    board->setPiece(piece);
    board->setPiece(piece2);

    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    expected.push_back({0, 5});
    expected.push_back({3, 6});
    posMove = board->possibleMoves(piece);
   
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}

TEST(Possible, blockedPieceRook)
{
    Board *board = new Board();
    Piece *piece = new Rook({0, 7}, true);
    Piece *piece2 = new Rook({1, 7}, true);
    Piece *piece3 = new Rook({0, 6}, true);

    board->setPiece(piece);
    board->setPiece(piece2);
    board->setPiece(piece3);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    posMove = board->possibleMoves(piece);
   
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}


TEST(Possible, blockedBishop)
{
    Board *board = new Board();
    Piece *piece = new Bishop({3,4}, false);
    Piece *knight = new Knight({4, 3}, false);
    Piece *knight1 = new Knight({4, 5}, false);
    Piece *knight2 = new Knight({2, 5}, false);
    Piece *knight3 = new Knight({2, 3}, false);
    board->setPiece(piece);
    board->setPiece(knight);
    board->setPiece(knight1);
    board->setPiece(knight2);
    board->setPiece(knight3);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    
    posMove = board->possibleMoves(piece);
   
    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}
TEST(Possible, blockedBishopCapture)
{
    Board *board = new Board();
    Piece* piece = new Bishop({3,4}, false);
    Piece *knight = new Knight({4, 3}, false);
    Piece *knight1 = new Knight({4, 5}, false);
    Piece *knight2 = new Knight({2, 5}, false);
    Piece *knight3 = new Knight({2, 3}, true);
    board->setPiece(piece);
    board->setPiece(knight);
    board->setPiece(knight1);
    board->setPiece(knight2);
    board->setPiece(knight3);
    std::vector<std::vector<int>> posMove;
    std::vector<std::vector<int>> expected;
    
    posMove = board->possibleMoves(piece);
       expected.push_back({2, 3});

    EXPECT_THAT(posMove, ::testing::ContainerEq(expected));
}


#endif //_POSSIBLE_MOVE_HPP