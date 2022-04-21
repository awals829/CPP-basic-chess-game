#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

using namespace std;

class test_pawn : public testing::Test
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

TEST_F(test_pawn, testConstructor)
{
    Pawn white(WHITE);
    Pawn black(BLACK);

    EXPECT_TRUE(white.getColour() == WHITE);
    EXPECT_TRUE(black.getColour() == BLACK);
}

//*******************************************************************************

TEST_F(test_pawn, testClone)
{
    PiecePtr piece1 = new Pawn(BLACK);
    PiecePtr piece2 = piece1->clone();

    EXPECT_TRUE(piece2->getColour() == BLACK);
    delete piece1;
    delete piece2;

    piece1 = new Pawn(WHITE);
    piece2 = piece1->clone();

    EXPECT_TRUE(piece2->getColour() == WHITE);
    delete piece1;
    delete piece2;
}
    
//*******************************************************************************

TEST_F(test_pawn, testGetSymbol)
{
    Pawn white(WHITE);
    Pawn black(BLACK);

    EXPECT_EQ(white.getSymbol(), 'P');
    EXPECT_EQ(black.getSymbol(), 'p');
}

//*******************************************************************************

TEST_F(test_pawn, testGetColour)
{
    Pawn white(WHITE);
    Pawn black(BLACK);

    EXPECT_FALSE(white.getColour() == BLACK);
    EXPECT_FALSE(black.getColour() == WHITE);
}

//*******************************************************************************

TEST_F(test_pawn, testNotifyMovedNewPawnMovingTwoSpaces)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);
    bool playerCol = WHITE;
    
    A.place(white, 4, 0);
    white->notifyMoved();

    EXPECT_FALSE(A.move(playerCol, 4, 0, 2, 0));
}

//*******************************************************************************

TEST_F(test_pawn, testCanMoveTwoSpacesPawnHasnotMoved)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);

    A.place(white, 5, 0);
    
    EXPECT_TRUE(white->canMove(A, 5, 0, 3, 0));
}

TEST_F(test_pawn, testCanMoveOneSpacesWhitePawnHasnotMoved)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);

    A.place(white, 5, 0);
    
    EXPECT_TRUE(white->canMove(A, 5, 0, 4, 0));
}

TEST_F(test_pawn, testCanMoveOneSpacesBlackPawnHasnotMoved)
{
    Board A;
    PiecePtr black = new Pawn(BLACK);

    A.place(black, 0, 0);
    
    EXPECT_TRUE(black->canMove(A, 0, 0, 1, 0));
}

TEST_F(test_pawn, testCanMoveTwoSpacesPawnHasMoved)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);

    A.place(white, 5, 0);
    
    EXPECT_TRUE(white->canMove(A, 5, 0, 3, 0));
}

TEST_F(test_pawn, testCannotMoveMoreThanAllowedSpaces)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);

    A.place(white, 5, 0);
    
    EXPECT_FALSE(white->canMove(A, 5, 0, 0, 0));
}

TEST_F(test_pawn, testCannotMoveTwoSpacesIfPawnHasMoved)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);
    bool playerCol = WHITE;
    
    A.place(white, 7, 0);
    white->notifyMoved();

    EXPECT_FALSE(A.move(playerCol, 7, 0, 5, 0));
}

TEST_F(test_pawn, testCanMoveOneSpacesIfPawnHasMoved)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);
    bool playerCol = WHITE;
    
    A.place(white, 6, 0);
    white->notifyMoved();

    EXPECT_TRUE(A.move(playerCol, 6, 0, 5, 0));
}


TEST_F(test_pawn, testCanMoveDiagonallyIfPawnHasMoved)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);
    PiecePtr black = new Pawn(BLACK);
    bool playerCol = WHITE;
    
    A.place(white, 6, 0);
    A.place(black, 5, 1);
    white->notifyMoved();

    EXPECT_TRUE(A.move(playerCol, 6, 0, 5, 1));
}


TEST_F(test_pawn, testCannotMovePawnPawnMoveBackwards)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);

    A.place(white, 5, 0);
    
    EXPECT_FALSE(white->canMove(A, 5, 0, 6, 0));
}

TEST_F(test_pawn, testCannotMovePawnToOccupiedLocationForward)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);
    PiecePtr black = new Pawn(BLACK);

    A.place(white, 7, 3);
    A.place(black, 6, 3);

    EXPECT_FALSE(white->canMove(A, 7, 0, 6, 3));
}

TEST_F(test_pawn, testCannotMoveWhitePawnBlockedPathForward)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);
    PiecePtr black = new Pawn(BLACK);

    A.place(white, 7, 3);
    A.place(black, 6, 3);

    EXPECT_FALSE(white->canMove(A, 7, 0, 5, 3));
}

TEST_F(test_pawn, testCannotMoveBlackPawnBlockedPathForward)
{
    Board A;
    PiecePtr black = new Pawn(BLACK);
    PiecePtr white = new Pawn(WHITE);

    A.place(black, 0, 0);
    A.place(white, 1, 0);

    EXPECT_FALSE(white->canMove(A, 0, 0, 2, 0));
}

TEST_F(test_pawn, testCannotMovePawnPawnDiagonalEmpty)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);

    A.place(white, 7, 0);
  
    EXPECT_FALSE(white->canMove(A, 7, 0, 6, 1));    
}

TEST_F(test_pawn, testCannotMovePawnPawnDiagonalOccupiedSameColour)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);
    PiecePtr white2 = new Pawn(WHITE);
    
    A.place(white, 4, 4);
    A.place(white2, 3, 5);
  
    EXPECT_FALSE(white->canMove(A, 4, 4, 3, 5));    
}

TEST_F(test_pawn, testCanMovePawnPawnDiagonalOccupiedDiffColour)
{
    Board A;
    PiecePtr white = new Pawn(WHITE);
    PiecePtr black = new Pawn(BLACK);
    
    A.place(white, 4, 4);
    A.place(black, 3, 5);
  
    EXPECT_TRUE(white->canMove(A, 4, 4, 3, 5));    
}
    


//*******************************************************************************

