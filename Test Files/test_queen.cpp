#include "Board.h"
#include "Piece.h"
#include "Queen.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

using namespace std;

class test_queen : public testing::Test
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

TEST_F(test_queen, testConstructor)
{
    Queen white(WHITE);
    Queen black(BLACK);

    EXPECT_TRUE(white.getColour() == WHITE);
    EXPECT_EQ(white.getSymbol(), 'Q');
    EXPECT_TRUE(black.getColour() == BLACK);
    EXPECT_EQ(black.getSymbol(), 'q');
}

//*******************************************************************************

TEST_F(test_queen, testQueenClone)
{
    PiecePtr piece1 = new Queen(BLACK);
    PiecePtr piece2 = piece1->clone();

    EXPECT_TRUE(piece2->getColour() == BLACK);
    EXPECT_EQ(piece2->getSymbol(), 'q');

    delete piece1;
    delete piece2;

    piece1 = new Queen(WHITE);
    piece2 = piece1->clone();

    EXPECT_TRUE(piece2->getColour() == WHITE);
    EXPECT_EQ(piece2->getSymbol(), 'Q');

    delete piece1;
    delete piece2;
}
    
//*******************************************************************************

TEST_F(test_queen, testGetSymbol)
{
    Queen white(WHITE);
    Queen black(BLACK);

    EXPECT_EQ(white.getSymbol(), 'Q');
    EXPECT_EQ(black.getSymbol(), 'q');
}

//*******************************************************************************

TEST_F(test_queen, testGetColour)
{
    Queen white(WHITE);
    Queen black(BLACK);

    EXPECT_TRUE(white.getColour() == WHITE);
    EXPECT_TRUE(black.getColour() == BLACK);
}

//*******************************************************************************


TEST_F(test_queen, testCanMoveVerticalAllDirectionsEmpty)
{
    Board A;
    PiecePtr queen = new Queen(WHITE);
    
    A.place(queen, 1, 1);

    EXPECT_TRUE(queen->canMove(A, 1, 1, 0, 1));

    EXPECT_TRUE(queen->canMove(A, 1, 1, 2, 1));

}

TEST_F(test_queen, testCanMoveVerticalManySpaces)
{
    Board A;
    PiecePtr queen = new Queen(WHITE);
    PiecePtr queen2 = new Queen(BLACK);
    
    A.place(queen, 0, 0);
    A.place(queen2, 4, 0);

    EXPECT_TRUE(queen->canMove(A, 0, 0, 4, 0));

    EXPECT_TRUE(queen2->canMove(A, 4, 0, 0, 0));

}

TEST_F(test_queen, testCanMoveHorizonatallyAllDirectionsEmpty)
{
    Board A;
    PiecePtr queen = new Queen(WHITE);
    
    A.place(queen, 4, 4);

    EXPECT_TRUE(queen->canMove(A, 4, 4, 4, 0));

    EXPECT_TRUE(queen->canMove(A, 4, 4, 4, 7));

}

TEST_F(test_queen, testCanMoveHorizontallyManySpaces)
{
    Board A;
    PiecePtr queen = new Queen(WHITE);
    PiecePtr queen2 = new Queen(BLACK);
    
    A.place(queen, 0, 0);
    A.place(queen2, 4, 0);

    EXPECT_TRUE(queen->canMove(A, 0, 0, 0, 4));

    EXPECT_TRUE(queen2->canMove(A, 4, 0, 4, 4));

}

TEST_F(test_queen, testCanMoveDiagonallyAllDirectionsEmpty)
{
    Board A;
    PiecePtr queen = new Queen(WHITE);
    
    A.place(queen, 1, 1);

    EXPECT_TRUE(queen->canMove(A, 1, 1, 0, 0));

    EXPECT_TRUE(queen->canMove(A, 1, 1, 2, 0));

    EXPECT_TRUE(queen->canMove(A, 1, 1, 0, 2));

    EXPECT_TRUE(queen->canMove(A, 1, 1, 2, 2));

}

TEST_F(test_queen, testCanMoveDiagonallyAllDirectionsEmptyManySpaces)
{
    Board A;
    PiecePtr queen = new Queen(WHITE);
    
    A.place(queen, 4, 4);

    EXPECT_TRUE(queen->canMove(A, 4, 4, 0, 0));

    EXPECT_TRUE(queen->canMove(A, 4, 4, 1, 7));

    EXPECT_TRUE(queen->canMove(A, 4, 4, 7, 1));

    EXPECT_TRUE(queen->canMove(A, 4, 4, 7, 7));

}

TEST_F(test_queen, testQueenCannotMoveThroughBlockedPathAnyDirection)
{
    Board A;
    PiecePtr queen = new Queen(WHITE);
    PiecePtr queen2 = new Queen(WHITE);
    PiecePtr queen3 = new Queen(WHITE);
    PiecePtr queen4 = new Queen(WHITE);
    
    A.place(queen, 0, 0);
    A.place(queen2, 4, 0);
    A.place(queen3, 0, 4);
    A.place(queen4, 3, 3);
    
    EXPECT_FALSE(queen->canMove(A, 0, 0, 7, 0));
    EXPECT_FALSE(queen->canMove(A, 0, 0, 0, 7));
    EXPECT_FALSE(queen->canMove(A, 0, 0, 4, 4));
}

TEST_F(test_queen, testQueenCannotMoveThroughSameColour)
{
    Board A;
    PiecePtr queen = new Queen(WHITE);
    PiecePtr queen2 = new Queen(WHITE);
    
    A.place(queen, 0, 0);
    A.place(queen2, 1, 1);
    
    EXPECT_FALSE(queen->canMove(A, 0, 0, 1, 1));
}

TEST_F(test_queen, testQueenCanCaptureVerticallyDiffColour)
{
    Board A;
    PiecePtr queen = new Queen(WHITE);
    PiecePtr queen2 = new Queen(BLACK);
    
    A.place(queen, 2, 2);
    A.place(queen2, 1, 2);
    
    EXPECT_TRUE(queen->canMove(A, 2, 2, 1, 2));
}

TEST_F(test_queen, testQueenCanCaptureHorizontallyDiffColour)
{
    Board A;
    PiecePtr queen = new Queen(WHITE);
    PiecePtr queen2 = new Queen(BLACK);
    
    A.place(queen, 2, 2);
    A.place(queen2, 2, 3);
    
    EXPECT_TRUE(queen->canMove(A, 2, 2, 2, 3));
}

TEST_F(test_queen, testQueenCanCaptureDiagonallyDiffColour)
{
    Board A;
    PiecePtr queen = new Queen(WHITE);
    PiecePtr queen2 = new Queen(BLACK);
    
    A.place(queen, 0, 0);
    A.place(queen2, 1, 1);
    
    EXPECT_TRUE(queen->canMove(A, 0, 0, 1, 1));
}
