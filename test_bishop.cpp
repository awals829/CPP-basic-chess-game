#include "Board.h"
#include "Piece.h"
#include "Bishop.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

using namespace std;

class test_bishop : public testing::Test
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

TEST_F(test_bishop, testConstructor)
{
    Bishop white(WHITE);
    Bishop black(BLACK);

    EXPECT_TRUE(white.getColour() == WHITE);
    EXPECT_EQ(white.getSymbol(), 'B');
    EXPECT_TRUE(black.getColour() == BLACK);
    EXPECT_EQ(black.getSymbol(), 'b');
}

//*******************************************************************************

TEST_F(test_bishop, testBishopClone)
{
    PiecePtr piece1 = new Bishop(BLACK);
    PiecePtr piece2 = piece1->clone();

    EXPECT_TRUE(piece2->getColour() == BLACK);
    EXPECT_EQ(piece2->getSymbol(), 'b');

    delete piece1;
    delete piece2;

    piece1 = new Bishop(WHITE);
    piece2 = piece1->clone();

    EXPECT_TRUE(piece2->getColour() == WHITE);
    EXPECT_EQ(piece2->getSymbol(), 'B');

    delete piece1;
    delete piece2;
}
    
//*******************************************************************************

TEST_F(test_bishop, testGetSymbol)
{
    Bishop white(WHITE);
    Bishop black(BLACK);

    EXPECT_EQ(white.getSymbol(), 'B');
    EXPECT_EQ(black.getSymbol(), 'b');
}

//*******************************************************************************

TEST_F(test_bishop, testGetColour)
{
    Bishop white(WHITE);
    Bishop black(BLACK);

    EXPECT_TRUE(white.getColour() == WHITE);
    EXPECT_TRUE(black.getColour() == BLACK);
}

//*******************************************************************************


TEST_F(test_bishop, testCannotMoveVerticalAllDirectionsEmpty)
{
    Board A;
    PiecePtr bishop = new Bishop(WHITE);
    
    A.place(bishop, 1, 1);

    EXPECT_FALSE(bishop->canMove(A, 1, 1, 0, 1));

    EXPECT_FALSE(bishop->canMove(A, 1, 1, 2, 1));

}

TEST_F(test_bishop, testCannotMoveVerticalManySpaces)
{
    Board A;
    PiecePtr bishop = new Bishop(WHITE);
    PiecePtr bishop2 = new Bishop(BLACK);
    
    A.place(bishop, 0, 0);
    A.place(bishop2, 4, 0);

    EXPECT_FALSE(bishop->canMove(A, 0, 0, 4, 0));

    EXPECT_FALSE(bishop2->canMove(A, 4, 0, 0, 0));

}

TEST_F(test_bishop, testCannotMoveHorizonatallyAllDirectionsEmpty)
{
    Board A;
    PiecePtr bishop = new Bishop(WHITE);
    
    A.place(bishop, 4, 4);

    EXPECT_FALSE(bishop->canMove(A, 4, 4, 4, 0));

    EXPECT_FALSE(bishop->canMove(A, 4, 4, 4, 7));

}

TEST_F(test_bishop, testCannotMoveHorizontallyManySpaces)
{
    Board A;
    PiecePtr bishop = new Bishop(WHITE);
    PiecePtr bishop2 = new Bishop(BLACK);
    
    A.place(bishop, 0, 0);
    A.place(bishop2, 4, 0);

    EXPECT_FALSE(bishop->canMove(A, 0, 0, 0, 4));

    EXPECT_FALSE(bishop2->canMove(A, 4, 0, 4, 4));

}

TEST_F(test_bishop, testCanMoveDiagonallyAllDirectionsEmpty)
{
    Board A;
    PiecePtr bishop = new Bishop(WHITE);
    
    A.place(bishop, 1, 1);

    EXPECT_TRUE(bishop->canMove(A, 1, 1, 0, 0));

    EXPECT_TRUE(bishop->canMove(A, 1, 1, 2, 0));

    EXPECT_TRUE(bishop->canMove(A, 1, 1, 0, 2));

    EXPECT_TRUE(bishop->canMove(A, 1, 1, 2, 2));

}

TEST_F(test_bishop, testCanMoveDiagonallyAllDirectionsEmptyManySpaces)
{
    Board A;
    PiecePtr bishop = new Bishop(WHITE);
    
    A.place(bishop, 4, 4);

    EXPECT_TRUE(bishop->canMove(A, 4, 4, 0, 0));

    EXPECT_TRUE(bishop->canMove(A, 4, 4, 1, 7));

    EXPECT_TRUE(bishop->canMove(A, 4, 4, 7, 1));

    EXPECT_TRUE(bishop->canMove(A, 4, 4, 7, 7));

}

TEST_F(test_bishop, testBishopCannotMoveThroughBlockedPathDiagonal)
{
    Board A;
    PiecePtr bishop = new Bishop(WHITE);
    PiecePtr bishop2 = new Bishop(WHITE);
    PiecePtr bishop3 = new Bishop(WHITE);
    PiecePtr bishop4 = new Bishop(WHITE);
    
    A.place(bishop, 0, 0);
    A.place(bishop2, 4, 0);
    A.place(bishop3, 0, 4);
    A.place(bishop4, 3, 3);
    
    EXPECT_FALSE(bishop->canMove(A, 0, 0, 7, 0));
    EXPECT_FALSE(bishop->canMove(A, 0, 0, 0, 7));
    EXPECT_FALSE(bishop->canMove(A, 0, 0, 4, 4));
}

TEST_F(test_bishop, testBishopCannotCaptureVerticallyDiffColour)
{
    Board A;
    PiecePtr bishop = new Bishop(WHITE);
    PiecePtr bishop2 = new Bishop(BLACK);
    
    A.place(bishop, 2, 2);
    A.place(bishop2, 1, 2);
    
    EXPECT_FALSE(bishop->canMove(A, 2, 2, 1, 2));
}

TEST_F(test_bishop, testBishopCannotCaptureHorizontallyDiffColour)
{
    Board A;
    PiecePtr bishop = new Bishop(WHITE);
    PiecePtr bishop2 = new Bishop(BLACK);
    
    A.place(bishop, 2, 2);
    A.place(bishop2, 2, 3);
    
    EXPECT_FALSE(bishop->canMove(A, 2, 2, 2, 3));
}

TEST_F(test_bishop, testBishopCanCaptureDiagonallyDiffColour)
{
    Board A;
    PiecePtr bishop = new Bishop(WHITE);
    PiecePtr bishop2 = new Bishop(BLACK);
    
    A.place(bishop, 0, 0);
    A.place(bishop2, 1, 1);
    
    EXPECT_TRUE(bishop->canMove(A, 0, 0, 1, 1));
}
