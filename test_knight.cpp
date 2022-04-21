#include "Board.h"
#include "Piece.h"
#include "Knight.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

using namespace std;

class test_knight : public testing::Test
{
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

//*******************************************************************************

TEST_F(test_knight, testConstructor)
{
    Knight white(WHITE);
    Knight black(BLACK);

    EXPECT_TRUE(white.getColour() == WHITE);
    EXPECT_EQ(white.getSymbol(), 'N');
    EXPECT_TRUE(black.getColour() == BLACK);
    EXPECT_EQ(black.getSymbol(), 'n');
}

//*******************************************************************************

TEST_F(test_knight, testKnightClone)
{
    PiecePtr piece1 = new Knight(BLACK);
    PiecePtr piece2 = piece1->clone();

    EXPECT_TRUE(piece2->getColour() == BLACK);
    EXPECT_EQ(piece2->getSymbol(), 'n');

    delete piece1;
    delete piece2;

    piece1 = new Knight(WHITE);
    piece2 = piece1->clone();

    EXPECT_TRUE(piece2->getColour() == WHITE);
    EXPECT_EQ(piece2->getSymbol(), 'N');

    delete piece1;
    delete piece2;
}
    
//*******************************************************************************

TEST_F(test_knight, testGetSymbol)
{
    Knight white(WHITE);
    Knight black(BLACK);

    EXPECT_EQ(white.getSymbol(), 'N');
    EXPECT_EQ(black.getSymbol(), 'n');
}

//*******************************************************************************

TEST_F(test_knight, testGetColour)
{
    Knight white(WHITE);
    Knight black(BLACK);

    EXPECT_TRUE(white.getColour() == WHITE);
    EXPECT_TRUE(black.getColour() == BLACK);
}

//*******************************************************************************

TEST_F(test_knight, testCanMoveEmptySpacesAll_LShapeDirections)
{
    Board A;
    PiecePtr knight = new Knight(BLACK);
    A.place(knight, 3, 4);

    EXPECT_TRUE(knight->canMove(A, 3, 4, 2, 2));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 1, 3));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 1, 5));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 2, 6));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 4, 6));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 5, 5));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 5, 3));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 4, 2));							
}

TEST_F(test_knight, testCanMoveToCaptureOccupiedSpacesAll_LShapeDirections)
{
    Board A;
    
    PiecePtr knight = new Knight(BLACK);
    PiecePtr knight1 = new Knight(WHITE);
    PiecePtr knight2 = new Knight(WHITE);
    PiecePtr knight3 = new Knight(WHITE);
    PiecePtr knight4 = new Knight(WHITE);
    PiecePtr knight5 = new Knight(WHITE);
    PiecePtr knight6 = new Knight(WHITE);
    PiecePtr knight7 = new Knight(WHITE);
    PiecePtr knight8 = new Knight(WHITE);

    A.place(knight, 3, 4);
    A.place(knight1, 2, 2);
    A.place(knight2, 1, 3);
    A.place(knight3, 1, 5);
    A.place(knight4, 2, 6);
    A.place(knight5, 4, 6);
    A.place(knight6, 5, 5);
    A.place(knight7, 5, 3);
    A.place(knight8, 4, 2);

    EXPECT_TRUE(knight->canMove(A, 3, 4, 2, 2));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 1, 3));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 1, 5));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 2, 6));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 4, 6));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 5, 5));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 5, 3));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 4, 2));							

}

TEST_F(test_knight, testCannotMoveSameColourOccupiedSpacesAll_LShapeDirections)
{
    Board A;
    
    PiecePtr knight = new Knight(WHITE);
    PiecePtr knight1 = new Knight(WHITE);
    PiecePtr knight2 = new Knight(WHITE);
    PiecePtr knight3 = new Knight(WHITE);
    PiecePtr knight4 = new Knight(WHITE);
    PiecePtr knight5 = new Knight(WHITE);
    PiecePtr knight6 = new Knight(WHITE);
    PiecePtr knight7 = new Knight(WHITE);
    PiecePtr knight8 = new Knight(WHITE);

    A.place(knight, 3, 4);
    A.place(knight1, 2, 2);
    A.place(knight2, 1, 3);
    A.place(knight3, 1, 5);
    A.place(knight4, 2, 6);
    A.place(knight5, 4, 6);
    A.place(knight6, 5, 5);
    A.place(knight7, 5, 3);
    A.place(knight8, 4, 2);

    EXPECT_FALSE(knight->canMove(A, 3, 4, 2, 2));
    EXPECT_FALSE(knight->canMove(A, 3, 4, 1, 3));
    EXPECT_FALSE(knight->canMove(A, 3, 4, 1, 5));
    EXPECT_FALSE(knight->canMove(A, 3, 4, 2, 6));
    EXPECT_FALSE(knight->canMove(A, 3, 4, 4, 6));
    EXPECT_FALSE(knight->canMove(A, 3, 4, 5, 5));
    EXPECT_FALSE(knight->canMove(A, 3, 4, 5, 3));
    EXPECT_FALSE(knight->canMove(A, 3, 4, 4, 2));							

}

TEST_F(test_knight, testCannotMoveDiagonalDirections)
{
    Board A;
    
    PiecePtr knight = new Knight(WHITE);

    A.place(knight, 3, 4);

    EXPECT_FALSE(knight->canMove(A, 3, 4, 2, 3));
    EXPECT_FALSE(knight->canMove(A, 3, 4, 2, 5));
    EXPECT_FALSE(knight->canMove(A, 3, 4, 4, 3));
    EXPECT_FALSE(knight->canMove(A, 3, 4, 4, 5));
}

TEST_F(test_knight, testCannotMoveOnlyHorizontalDirections)
{
    Board A;
    
    PiecePtr knight = new Knight(WHITE);

    A.place(knight, 3, 4);

    EXPECT_FALSE(knight->canMove(A, 3, 4, 3, 3));
    EXPECT_FALSE(knight->canMove(A, 3, 4, 3, 5));
}

TEST_F(test_knight, testCannotMoveOnlyVerticalDirections)
{
    Board A;
    
    PiecePtr knight = new Knight(WHITE);

    A.place(knight, 3, 4);

    EXPECT_FALSE(knight->canMove(A, 3, 4, 2, 4));
    EXPECT_FALSE(knight->canMove(A, 3, 4, 4, 4));
}

TEST_F(test_knight, testCanJumpOtherPiecesRegardlessofColour)
{
    Board A;
    
    PiecePtr knight = new Knight(WHITE);
    PiecePtr knight1 = new Knight(BLACK);
    PiecePtr knight2 = new Knight(WHITE);

    A.place(knight, 3, 4);
    A.place(knight1, 2, 4);
    A.place(knight2, 4, 4);

    EXPECT_TRUE(knight->canMove(A, 3, 4, 1, 3));
    EXPECT_TRUE(knight->canMove(A, 3, 4, 5, 5));
}

