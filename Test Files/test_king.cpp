#include "Board.h"
#include "Piece.h"
#include "King.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

using namespace std;

class test_king : public testing::Test
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

TEST_F(test_king, testConstructor)
{
    King white(WHITE);
    King black(BLACK);

    EXPECT_TRUE(white.getColour() == WHITE);
    EXPECT_EQ(white.getSymbol(), 'K');
    EXPECT_TRUE(black.getColour() == BLACK);
    EXPECT_EQ(black.getSymbol(), 'k');
}

//*******************************************************************************

TEST_F(test_king, testKingClone)
{
    PiecePtr piece1 = new King(BLACK);
    PiecePtr piece2 = piece1->clone();

    EXPECT_TRUE(piece2->getColour() == BLACK);
    EXPECT_EQ(piece2->getSymbol(), 'k');

    delete piece1;
    delete piece2;

    piece1 = new King(WHITE);
    piece2 = piece1->clone();

    EXPECT_TRUE(piece2->getColour() == WHITE);
    EXPECT_EQ(piece2->getSymbol(), 'K');

    delete piece1;
    delete piece2;
}
    
//*******************************************************************************

TEST_F(test_king, testGetSymbol)
{
    King white(WHITE);
    King black(BLACK);

    EXPECT_EQ(white.getSymbol(), 'K');
    EXPECT_EQ(black.getSymbol(), 'k');
}

//*******************************************************************************

TEST_F(test_king, testGetColour)
{
    King white(WHITE);
    King black(BLACK);

    EXPECT_TRUE(white.getColour() == WHITE);
    EXPECT_TRUE(black.getColour() == BLACK);
}

//*******************************************************************************

TEST_F(test_king, testCanMoveVerticalAllDirectionsEmpty)
{
    Board A;
    PiecePtr king = new King(WHITE);
    
    A.place(king, 1, 1);

    EXPECT_TRUE(king->canMove(A, 1, 1, 0, 1));

    EXPECT_TRUE(king->canMove(A, 1, 1, 2, 1));

}

TEST_F(test_king, testCanMoveHorizonatallyAllDirectionsEmpty)
{
    Board A;
    PiecePtr king = new King(WHITE);
    
    A.place(king, 1, 1);

    EXPECT_TRUE(king->canMove(A, 1, 1, 1, 2));

    EXPECT_TRUE(king->canMove(A, 1, 1, 1, 0));

}

TEST_F(test_king, testCanMoveDiagonallyAllDirectionsEmpty)
{
    Board A;
    PiecePtr king = new King(WHITE);
    
    A.place(king, 1, 1);

    EXPECT_TRUE(king->canMove(A, 1, 1, 0, 0));

    EXPECT_TRUE(king->canMove(A, 1, 1, 2, 0));

    EXPECT_TRUE(king->canMove(A, 1, 1, 0, 2));

    EXPECT_TRUE(king->canMove(A, 1, 1, 2, 2));

}

TEST_F(test_king, testKingCannotMoveThroughSameColour)
{
    Board A;
    PiecePtr king = new King(WHITE);
    PiecePtr king2 = new King(WHITE);
    
    A.place(king, 0, 0);
    A.place(king2, 1, 1);
    
    EXPECT_FALSE(king->canMove(A, 0, 0, 1, 1));
}

TEST_F(test_king, testKingCanCaptureVerticallyDiffColour)
{
    Board A;
    PiecePtr king = new King(WHITE);
    PiecePtr king2 = new King(BLACK);
    
    A.place(king, 2, 2);
    A.place(king2, 1, 2);
    
    EXPECT_TRUE(king->canMove(A, 2, 2, 1, 2));
}

TEST_F(test_king, testKingCanCaptureHorizontallyDiffColour)
{
    Board A;
    PiecePtr king = new King(WHITE);
    PiecePtr king2 = new King(BLACK);
    
    A.place(king, 2, 2);
    A.place(king2, 2, 3);
    
    EXPECT_TRUE(king->canMove(A, 2, 2, 2, 3));
}

TEST_F(test_king, testKingCanCaptureDiagonallyDiffColour)
{
    Board A;
    PiecePtr king = new King(WHITE);
    PiecePtr king2 = new King(BLACK);
    
    A.place(king, 0, 0);
    A.place(king2, 1, 1);
    
    EXPECT_TRUE(king->canMove(A, 0, 0, 1, 1));
}

TEST_F(test_king, testKingCannotMoveMoreThanOneSpace)
{
    Board A;
    PiecePtr king = new King(WHITE);
    
    A.place(king, 2, 2);
    
    EXPECT_FALSE(king->canMove(A, 2, 2, 0, 2));
    EXPECT_FALSE(king->canMove(A, 2, 2, 0, 4));
    EXPECT_FALSE(king->canMove(A, 2, 2, 2, 4));
}
