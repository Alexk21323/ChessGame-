#ifndef _PIECE_HPP
#define _PIECE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "human.hpp"
#include "board.h"
#include "piece.h"
//TEST piece positions

//Black pawn
TEST(Black, pawn1)
{

    Piece *pawn = new Pawn({0, 1}, false);

    EXPECT_EQ(pawn->getPosition()[0], 0);
    EXPECT_EQ(pawn->getPosition()[1], 1);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), false);
}
TEST(Black, pawn2)
{

    Piece *pawn = new Pawn({1, 1}, false);

    EXPECT_EQ(pawn->getPosition()[0], 1);
    EXPECT_EQ(pawn->getPosition()[1], 1);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), false);
}
TEST(Black, pawn3)
{

    Piece *pawn = new Pawn({2, 1}, false);

    EXPECT_EQ(pawn->getPosition()[0], 2);
    EXPECT_EQ(pawn->getPosition()[1], 1);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), false);
}
TEST(Black, pawn4)
{

    Piece *pawn = new Pawn({3, 1}, false);

    EXPECT_EQ(pawn->getPosition()[0], 3);
    EXPECT_EQ(pawn->getPosition()[1], 1);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), false);
}
TEST(Black, pawn5)
{

    Piece *pawn = new Pawn({4, 1}, false);

    EXPECT_EQ(pawn->getPosition()[0], 4);
    EXPECT_EQ(pawn->getPosition()[1], 1);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), false);
}
TEST(Black, pawn6)
{

    Piece *pawn = new Pawn({5, 1}, false);

    EXPECT_EQ(pawn->getPosition()[0], 5);
    EXPECT_EQ(pawn->getPosition()[1], 1);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), false);
}
TEST(Black, pawn7)
{

    Piece *pawn = new Pawn({6, 1}, false);

    EXPECT_EQ(pawn->getPosition()[0], 6);
    EXPECT_EQ(pawn->getPosition()[1], 1);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), false);
}
TEST(Black, pawn8)
{

    Piece *pawn = new Pawn({7, 1}, false);

    EXPECT_EQ(pawn->getPosition()[0], 7);
    EXPECT_EQ(pawn->getPosition()[1], 1);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), false);
}

//remainer of black pieces
TEST(Black, rook)
{

    Piece *piece = new Rook({0, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 0);
    EXPECT_EQ(piece->getPosition()[1], 0);
    EXPECT_EQ(piece->getType(), 1);
    EXPECT_EQ(piece->getColor(), false);
}

TEST(Black, knight)
{

    Piece *piece = new Knight({1, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 1);
    EXPECT_EQ(piece->getPosition()[1], 0);
    EXPECT_EQ(piece->getType(), 2);
    EXPECT_EQ(piece->getColor(), false);
}
TEST(Black, bishop)
{

    Piece *piece = new Bishop({2, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 2);
    EXPECT_EQ(piece->getPosition()[1], 0);
    EXPECT_EQ(piece->getType(), 3);
    EXPECT_EQ(piece->getColor(), false);
}

TEST(Black, queen)
{

    Piece *piece = new Queen({3, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 0);
    EXPECT_EQ(piece->getType(), 4);
    EXPECT_EQ(piece->getColor(), false);
}

TEST(Black, king)
{

    Piece *piece = new King({4, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 4);
    EXPECT_EQ(piece->getPosition()[1], 0);
    EXPECT_EQ(piece->getType(), 5);
    EXPECT_EQ(piece->getColor(), false);
}
TEST(Black, bishop2)
{

    Piece *piece = new Bishop({5, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 5);
    EXPECT_EQ(piece->getPosition()[1], 0);
    EXPECT_EQ(piece->getType(), 3);
    EXPECT_EQ(piece->getColor(), false);
}
TEST(Black, knight2)
{

    Piece *piece = new Knight({6, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 6);
    EXPECT_EQ(piece->getPosition()[1], 0);
    EXPECT_EQ(piece->getType(), 2);
    EXPECT_EQ(piece->getColor(), false);
}
TEST(Black, rook2)
{

    Piece *piece = new Rook({7, 0}, false);

    EXPECT_EQ(piece->getPosition()[0], 7);
    EXPECT_EQ(piece->getPosition()[1], 0);
    EXPECT_EQ(piece->getType(), 1);
    EXPECT_EQ(piece->getColor(), false);
}

//WHITE Pawn
TEST(White, pawn1)
{

    Piece *pawn = new Pawn({0, 6}, true);

    EXPECT_EQ(pawn->getPosition()[0], 0);
    EXPECT_EQ(pawn->getPosition()[1], 6);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), true);
}
TEST(White, pawn2)
{

    Piece *pawn = new Pawn({1, 6}, true);

    EXPECT_EQ(pawn->getPosition()[0], 1);
    EXPECT_EQ(pawn->getPosition()[1], 6);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), true);
}
TEST(White, pawn3)
{

    Piece *pawn = new Pawn({2, 6}, true);

    EXPECT_EQ(pawn->getPosition()[0], 2);
    EXPECT_EQ(pawn->getPosition()[1], 6);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), true);
}
TEST(White, pawn4)
{

    Piece *pawn = new Pawn({3, 6}, true);

    EXPECT_EQ(pawn->getPosition()[0], 3);
    EXPECT_EQ(pawn->getPosition()[1], 6);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), true);
}
TEST(White, pawn5)
{

    Piece *pawn = new Pawn({4, 6}, true);

    EXPECT_EQ(pawn->getPosition()[0], 4);
    EXPECT_EQ(pawn->getPosition()[1], 6);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), true);
}
TEST(White, pawn6)
{

    Piece *pawn = new Pawn({5, 6}, true);

    EXPECT_EQ(pawn->getPosition()[0], 5);
    EXPECT_EQ(pawn->getPosition()[1], 6);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), true);
}
TEST(White, pawn7)
{

    Piece *pawn = new Pawn({6, 6}, true);

    EXPECT_EQ(pawn->getPosition()[0], 6);
    EXPECT_EQ(pawn->getPosition()[1], 6);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), true);
}
TEST(White, pawn8)
{

    Piece *pawn = new Pawn({7, 6}, true);

    EXPECT_EQ(pawn->getPosition()[0], 7);
    EXPECT_EQ(pawn->getPosition()[1], 6);
    EXPECT_EQ(pawn->getType(), 0);
    EXPECT_EQ(pawn->getColor(), true);
}

//remainer of white pieces
TEST(White, rook)
{

    Piece *piece = new Rook({0, 7}, true);

    EXPECT_EQ(piece->getPosition()[0], 0);
    EXPECT_EQ(piece->getPosition()[1], 7);
    EXPECT_EQ(piece->getType(), 1);
    EXPECT_EQ(piece->getColor(), true);
}

TEST(White, knight)
{

    Piece *piece = new Knight({1, 7}, true);

    EXPECT_EQ(piece->getPosition()[0], 1);
    EXPECT_EQ(piece->getPosition()[1], 7);
    EXPECT_EQ(piece->getType(), 2);
    EXPECT_EQ(piece->getColor(), true);
}
TEST(White, bishop)
{

    Piece *piece = new Bishop({2, 7}, true);

    EXPECT_EQ(piece->getPosition()[0], 2);
    EXPECT_EQ(piece->getPosition()[1], 7);
    EXPECT_EQ(piece->getType(), 3);
    EXPECT_EQ(piece->getColor(), true);
}

TEST(White, queen)
{

    Piece *piece = new Queen({3, 7}, true);

    EXPECT_EQ(piece->getPosition()[0], 3);
    EXPECT_EQ(piece->getPosition()[1], 7);
    EXPECT_EQ(piece->getType(), 4);
    EXPECT_EQ(piece->getColor(), true);
}

TEST(White, king)
{

    Piece *piece = new King({4, 7}, true);

    EXPECT_EQ(piece->getPosition()[0], 4);
    EXPECT_EQ(piece->getPosition()[1], 7);
    EXPECT_EQ(piece->getType(), 5);
    EXPECT_EQ(piece->getColor(), true);
}
TEST(White, bishop2)
{

    Piece *piece = new Bishop({5, 7}, true);

    EXPECT_EQ(piece->getPosition()[0], 5);
    EXPECT_EQ(piece->getPosition()[1], 7);
    EXPECT_EQ(piece->getType(), 3);
    EXPECT_EQ(piece->getColor(), true);
}
TEST(White, knight2)
{

    Piece *piece = new Knight({6, 7}, true);

    EXPECT_EQ(piece->getPosition()[0], 6);
    EXPECT_EQ(piece->getPosition()[1], 7);
    EXPECT_EQ(piece->getType(), 2);
    EXPECT_EQ(piece->getColor(), true);
}
TEST(White, rook2)
{

    Piece *piece = new Rook({7, 7}, true);

    EXPECT_EQ(piece->getPosition()[0], 7);
    EXPECT_EQ(piece->getPosition()[1], 7);
    EXPECT_EQ(piece->getType(), 1);
    EXPECT_EQ(piece->getColor(), true);
}

//Available Position Testing
TEST(AvailablePositions, pawn)
{

    Board *board = new Board();
    Piece *pawn = new Pawn({0, 1}, false);
    std::vector<std::vector<int>> posMove;
    board->possibleMoves(pawn);
    
   

}



#endif //_PIECE_HPP