#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

using namespace std;

class test_rook : public testing::Test
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

TEST_F(test_rook, testConstructor)
{
    Rook white(WHITE);
    Rook black(BLACK);

    EXPECT_TRUE(white.getColour() == WHITE);
    EXPECT_EQ(white.getSymbol(), 'R');
    EXPECT_TRUE(black.getColour() == BLACK);
    EXPECT_EQ(black.getSymbol(), 'r');
}

//*******************************************************************************

TEST_F(test_rook, testRookClone)
{
    PiecePtr piece1 = new Rook(BLACK);
    PiecePtr piece2 = piece1->clone();

    EXPECT_TRUE(piece2->getColour() == BLACK);
    EXPECT_EQ(piece2->getSymbol(), 'r');

    delete piece1;
    delete piece2;

    piece1 = new Rook(WHITE);
    piece2 = piece1->clone();

    EXPECT_TRUE(piece2->getColour() == WHITE);
    EXPECT_EQ(piece2->getSymbol(), 'R');

    delete piece1;
    delete piece2;
}
    
//*******************************************************************************

TEST_F(test_rook, testGetSymbol)
{
    Rook white(WHITE);
    Rook black(BLACK);

    EXPECT_EQ(white.getSymbol(), 'R');
    EXPECT_EQ(black.getSymbol(), 'r');
}

//*******************************************************************************

TEST_F(test_rook, testGetColour)
{
    Rook white(WHITE);
    Rook black(BLACK);

    EXPECT_TRUE(white.getColour() == WHITE);
    EXPECT_TRUE(black.getColour() == BLACK);
}

//*******************************************************************************


TEST_F(test_rook, testCanMoveVerticalAllDirectionsEmpty)
{
    Board A;
    PiecePtr rook = new Rook(WHITE);
    
    A.place(rook, 1, 1);

    EXPECT_TRUE(rook->canMove(A, 1, 1, 0, 1));

    EXPECT_TRUE(rook->canMove(A, 1, 1, 2, 1));

}

TEST_F(test_rook, testCanMoveVerticalManySpaces)
{
    Board A;
    PiecePtr rook = new Rook(WHITE);
    PiecePtr rook2 = new Rook(BLACK);
    
    A.place(rook, 0, 0);
    A.place(rook2, 4, 0);

    EXPECT_TRUE(rook->canMove(A, 0, 0, 4, 0));

    EXPECT_TRUE(rook2->canMove(A, 4, 0, 0, 0));

}

TEST_F(test_rook, testCanMoveHorizonatallyAllDirectionsEmpty)
{
    Board A;
    PiecePtr rook = new Rook(WHITE);
    
    A.place(rook, 4, 4);

    EXPECT_TRUE(rook->canMove(A, 4, 4, 4, 0));

    EXPECT_TRUE(rook->canMove(A, 4, 4, 4, 7));

}

TEST_F(test_rook, testCanMoveHorizontallyManySpaces)
{
    Board A;
    PiecePtr rook = new Rook(WHITE);
    PiecePtr rook2 = new Rook(BLACK);
    
    A.place(rook, 0, 0);
    A.place(rook2, 4, 0);

    EXPECT_TRUE(rook->canMove(A, 0, 0, 0, 4));

    EXPECT_TRUE(rook2->canMove(A, 4, 0, 4, 4));

}

TEST_F(test_rook, testCannotMoveDiagonallyAllDirections)
{
    Board A;
    PiecePtr rook = new Rook(WHITE);
    
    A.place(rook, 1, 1);

    EXPECT_FALSE(rook->canMove(A, 1, 1, 0, 0));

    EXPECT_FALSE(rook->canMove(A, 1, 1, 2, 0));

    EXPECT_FALSE(rook->canMove(A, 1, 1, 0, 2));

    EXPECT_FALSE(rook->canMove(A, 1, 1, 2, 2));

}

TEST_F(test_rook, testCannotMoveDiagonallyAllDirectionsEmptyManySpaces)
{
    Board A;
    PiecePtr rook = new Rook(WHITE);
    
    A.place(rook, 4, 4);

    EXPECT_FALSE(rook->canMove(A, 4, 4, 0, 0));

    EXPECT_FALSE(rook->canMove(A, 4, 4, 1, 7));

    EXPECT_FALSE(rook->canMove(A, 4, 4, 7, 1));

    EXPECT_FALSE(rook->canMove(A, 4, 4, 7, 7));

}

TEST_F(test_rook, testRookCannotMoveThroughBlockedAnyDirection)
{
    Board A;
    PiecePtr rook = new Rook(WHITE);
    PiecePtr rook2 = new Rook(WHITE);
    PiecePtr rook3 = new Rook(WHITE);
     
    A.place(rook, 3, 3);
    A.place(rook2, 1, 3);
    A.place(rook3, 3, 5);
    
    EXPECT_FALSE(rook->canMove(A, 3, 3, 0, 3));
    EXPECT_FALSE(rook->canMove(A, 3, 3, 3, 6));
}

TEST_F(test_rook, testRookCannotMoveThroughSameColour)
{
    Board A;
    PiecePtr rook = new Rook(WHITE);
    PiecePtr rook2 = new Rook(WHITE);
    
    A.place(rook, 0, 0);
    A.place(rook2, 1, 1);
    
    EXPECT_FALSE(rook->canMove(A, 0, 0, 1, 1));
}

TEST_F(test_rook, testRookCanCaptureVerticallyDiffColour)
{
    Board A;
    PiecePtr rook = new Rook(WHITE);
    PiecePtr rook2 = new Rook(BLACK);
    
    A.place(rook, 2, 2);
    A.place(rook2, 1, 2);
    
    EXPECT_TRUE(rook->canMove(A, 2, 2, 1, 2));
}

TEST_F(test_rook, testRookCanCaptureHorizontallyDiffColour)
{
    Board A;
    PiecePtr rook = new Rook(WHITE);
    PiecePtr rook2 = new Rook(BLACK);
    
    A.place(rook, 2, 2);
    A.place(rook2, 2, 3);
    
    EXPECT_TRUE(rook->canMove(A, 2, 2, 2, 3));
}

TEST_F(test_rook, testRookCannotCaptureDiagonallyDiffColour)
{
    Board A;
    PiecePtr rook = new Rook(WHITE);
    PiecePtr rook2 = new Rook(BLACK);
    
    A.place(rook, 0, 0);
    A.place(rook2, 1, 1);
    
    EXPECT_FALSE(rook->canMove(A, 0, 0, 1, 1));
}
