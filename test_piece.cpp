#include "Board.h"
#include "Piece.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

using namespace std;

class test_piece : public testing::Test
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

TEST_F(test_piece, testConstructor)
{
    Piece white(WHITE);
    Piece black(BLACK);

    EXPECT_TRUE(white.getColour() == WHITE);
    EXPECT_TRUE(black.getColour() == BLACK);
}

//*******************************************************************************

TEST_F(test_piece, testGetSymbol)
{
    Piece white(WHITE);
    Piece black(BLACK);

    EXPECT_EQ(white.getSymbol(), 'P');
    EXPECT_EQ(black.getSymbol(), 'p');
}

//*******************************************************************************

TEST_F(test_piece, testGetColour)
{
    Piece white(WHITE);
    Piece black(BLACK);

    EXPECT_FALSE(white.getColour() == BLACK);
    EXPECT_FALSE(black.getColour() == WHITE);
}

//*******************************************************************************

TEST_F(test_piece, testNotifyMovedNewPieceMovingTwoSpaces)
{
    Board A;
    PiecePtr white = new Piece(WHITE);
    bool playerCol = WHITE;
    
    A.place(white, 4, 0);
    white->notifyMoved();

    EXPECT_FALSE(A.move(playerCol, 4, 0, 2, 0));
}

//*******************************************************************************

TEST_F(test_piece, testCanMoveTwoSpacesPieceHasnotMoved)
{
    Board A;
    PiecePtr white = new Piece(WHITE);

    A.place(white, 5, 0);
    
    EXPECT_TRUE(white->canMove(A, 5, 0, 3, 0));
}

TEST_F(test_piece, testCanMoveOneSpacesWhitePieceHasnotMoved)
{
    Board A;
    PiecePtr white = new Piece(WHITE);

    A.place(white, 5, 0);
    
    EXPECT_TRUE(white->canMove(A, 5, 0, 4, 0));
}

TEST_F(test_piece, testCanMoveOneSpacesBlackPieceHasnotMoved)
{
    Board A;
    PiecePtr black = new Piece(BLACK);

    A.place(black, 0, 0);
    
    EXPECT_TRUE(black->canMove(A, 0, 0, 1, 0));
}

TEST_F(test_piece, testCanMoveTwoSpacesPieceHasMoved)
{
    Board A;
    PiecePtr white = new Piece(WHITE);

    A.place(white, 5, 0);
    
    EXPECT_TRUE(white->canMove(A, 5, 0, 3, 0));
}

TEST_F(test_piece, testCannotMoveMoreThanAllowedSpaces)
{
    Board A;
    PiecePtr white = new Piece(WHITE);

    A.place(white, 5, 0);
    
    EXPECT_FALSE(white->canMove(A, 5, 0, 0, 0));
}

TEST_F(test_piece, testCannotMoveTwoSpacesIfPieceHasMoved)
{
    Board A;
    PiecePtr white = new Piece(WHITE);
    bool playerCol = WHITE;
    
    A.place(white, 7, 0);
    white->notifyMoved();

    EXPECT_FALSE(A.move(playerCol, 7, 0, 5, 0));
}

TEST_F(test_piece, testCanMoveOneSpacesIfPieceHasMoved)
{
    Board A;
    PiecePtr white = new Piece(WHITE);
    bool playerCol = WHITE;
    
    A.place(white, 6, 0);
    white->notifyMoved();

    EXPECT_TRUE(A.move(playerCol, 6, 0, 5, 0));
}


TEST_F(test_piece, testCanMoveDiagonallyIfPieceHasMoved)
{
    Board A;
    PiecePtr white = new Piece(WHITE);
    PiecePtr black = new Piece(BLACK);
    bool playerCol = WHITE;
    
    A.place(white, 6, 0);
    A.place(black, 5, 1);
    white->notifyMoved();

    EXPECT_TRUE(A.move(playerCol, 6, 0, 5, 1));
}


TEST_F(test_piece, testCannotMovePawnPieceMoveBackwards)
{
    Board A;
    PiecePtr white = new Piece(WHITE);

    A.place(white, 5, 0);
    
    EXPECT_FALSE(white->canMove(A, 5, 0, 6, 0));
}

TEST_F(test_piece, testCannotMovePieceToOccupiedLocationForward)
{
    Board A;
    PiecePtr white = new Piece(WHITE);
    PiecePtr black = new Piece(BLACK);

    A.place(white, 7, 3);
    A.place(black, 6, 3);

    EXPECT_FALSE(white->canMove(A, 7, 0, 6, 3));
}

TEST_F(test_piece, testCannotMoveWhitePieceBlockedPathForward)
{
    Board A;
    PiecePtr white = new Piece(WHITE);
    PiecePtr black = new Piece(BLACK);

    A.place(white, 7, 3);
    A.place(black, 6, 3);

    EXPECT_FALSE(white->canMove(A, 7, 0, 5, 3));
}

TEST_F(test_piece, testCannotMoveBlackPieceBlockedPathForward)
{
    Board A;
    PiecePtr black = new Piece(BLACK);
    PiecePtr white = new Piece(WHITE);

    A.place(black, 0, 0);
    A.place(white, 1, 0);

    EXPECT_FALSE(white->canMove(A, 0, 0, 2, 0));
}

TEST_F(test_piece, testCannotMovePawnPieceDiagonalEmpty)
{
    Board A;
    PiecePtr white = new Piece(WHITE);

    A.place(white, 7, 0);
  
    EXPECT_FALSE(white->canMove(A, 7, 0, 6, 1));    
}

TEST_F(test_piece, testCannotMovePawnPieceDiagonalOccupiedSameColour)
{
    Board A;
    PiecePtr white = new Piece(WHITE);
    PiecePtr white2 = new Piece(WHITE);
    
    A.place(white, 4, 4);
    A.place(white2, 3, 5);
  
    EXPECT_FALSE(white->canMove(A, 4, 4, 3, 5));    
}

TEST_F(test_piece, testCanMovePawnPieceDiagonalOccupiedDiffColour)
{
    Board A;
    PiecePtr white = new Piece(WHITE);
    PiecePtr black = new Piece(BLACK);
    
    A.place(white, 4, 4);
    A.place(black, 3, 5);
  
    EXPECT_TRUE(white->canMove(A, 4, 4, 3, 5));    
}
    


//*******************************************************************************


//*******************************************************************************


//*******************************************************************************


//*******************************************************************************


