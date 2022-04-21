#include "Board.h"
#include "Piece.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

using namespace std;

class test_board : public testing::Test
{
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

//===============================================================================

TEST_F(test_board, testConstructor)
{
    int x, y;
    PiecePtr check;
    Board A;

    for(x = 0; x < MAXROWS; x++)
    {
	for(y = 0; y < MAXCOLS; y++)
	{
	    check = A.getPiece(x, y);
	    ASSERT_TRUE(check == NULL);
	}
    }
}


TEST_F(test_board, testCopyConstructor)
{
    Board A;
    PiecePtr a = new Piece(WHITE);
    bool occupied;
    
    A.place(a,4,4);

    Board B(A);
    
    occupied = B.isOccupied(4, 4);
    EXPECT_TRUE(occupied);
}

//===============================================================================

TEST_F(test_board, testEmptyBoardLocationIsOccupiedFunction)
{
    int x, y;
    Board A;

    for(x = 0; x < MAXROWS; x++)
    {
	for(y = 0; y < MAXCOLS; y++)
	{
	    EXPECT_FALSE(A.isOccupied(x,y));
	}
    }
}


TEST_F(test_board, testOccupiedBoardLocationIsOccupiedFunction)
{
    Board A;
    PiecePtr a = new Piece(WHITE);

    A.place(a, 0, 0);

    EXPECT_TRUE(A.isOccupied(0 ,0));
}

//===============================================================================

TEST_F(test_board, testEmptyLocationGetPieceFunction)
{
    Board A;
    EXPECT_TRUE(A.getPiece(0, 0) == NULL);
}


TEST_F(test_board, testOccupiedLocationGetPieceFunction)
{
    Board A;
    PiecePtr a = new Piece(WHITE);
    PiecePtr check;
    
    A.place(a, 0, 0);
    
    check = A.getPiece(0, 0);

    EXPECT_TRUE(check != NULL);
    delete check;
}

//===============================================================================

TEST_F(test_board, testEmptyBoardPlaceMultiplePieces)
{
    Board A;
    PiecePtr a = new Piece(WHITE),
       	     b = new Piece(WHITE),
	     c = new Piece(WHITE),
	     check;

    A.place(a,0,0);
    A.place(b,4,1);
    A.place(c,3,3);

    check = A.getPiece(0,0);
    EXPECT_TRUE(check != NULL);
    delete check;

    check = A.getPiece(4,1);
    EXPECT_TRUE(check != NULL);
    delete check;
    
    check = A.getPiece(3,3);
    EXPECT_TRUE(check != NULL);
    delete check;
}


TEST_F(test_board, testNotEmptyBoardLocationPlacePiece)
{
    Board A;
    PiecePtr a = new Piece(WHITE),
	     b = new Piece(WHITE),
	     check;

    bool place;

    place = A.place(a,4,4);
    EXPECT_TRUE(place);

    check = A.getPiece(4,4);
    EXPECT_TRUE(check != NULL);
    delete check;
    
    place = A.place(b,4,4);
    EXPECT_FALSE(place);
    delete b;
    
    check = A.getPiece(4,4);
    EXPECT_TRUE(check != NULL);
    delete check;
 
}

//===============================================================================

TEST_F(test_board, testFullBoardLocationRemovePiece)
{
    Board A;
    PiecePtr a = new Piece(WHITE),
	     check;

    bool place, remove;

    place = A.place(a,4,4);
    EXPECT_TRUE(place);

    check = A.getPiece(4,4);
    EXPECT_TRUE(check != NULL);
    delete check;
    
    remove = A.remove(4,4);
    EXPECT_TRUE(remove);
    
    check = A.getPiece(4,4);
    EXPECT_TRUE(check == NULL);

}


TEST_F(test_board, testFullBoardLocationMultipleRemovePiece)
{
    Board A;
    PiecePtr a = new Piece(WHITE),
	     b = new Piece(WHITE),
	     check;

    bool place, remove;

    
    place = A.place(a,4,4);
    EXPECT_TRUE(place);

    check = A.getPiece(4,4);
    EXPECT_TRUE(check != NULL);
    delete check;
    
    
    place = A.place(b,5,5);
    EXPECT_TRUE(place);

    check = A.getPiece(5,5);
    EXPECT_TRUE(check != NULL);
    delete check;
    
    
    remove = A.remove(4,4);
    EXPECT_TRUE(remove);

    check = A.getPiece(4,4);
    EXPECT_TRUE(check == NULL);


    
    remove = A.remove(5,5);
    EXPECT_TRUE(remove);

    check = A.getPiece(5,5);
    EXPECT_TRUE(check == NULL);

}


TEST_F(test_board, testEmptyBoardLocationRemovePiece)
{
    Board A;
    bool remove;
    
    remove = A.remove(2,4);
    EXPECT_FALSE(remove);

}

//*******************************************************************************

TEST_F(test_board, testFirstMoveWhitePieceTwoSpacesNotOccupied)
{
    Board A;
    PiecePtr a = new Piece(WHITE);
    bool playerCol = WHITE;

    A.place(a, 7, 0);
    
    EXPECT_TRUE(A.move(playerCol, 7, 0, 5, 0));
    EXPECT_TRUE(A.isOccupied(5,0));
}


TEST_F(test_board, testFirstMoveBlackPieceTwoSpacesNotOccupied)
{
    Board A;
    PiecePtr a = new Piece(BLACK);
    bool playerCol = BLACK;

    A.place(a, 0, 0);
    EXPECT_TRUE(A.move(playerCol, 0, 0, 2, 0));
    EXPECT_TRUE(A.isOccupied(2,0));
}


TEST_F(test_board, testFirstMoveWhitePieceOneSpaceNotOccupied)
{
    Board A;
    PiecePtr a = new Piece(WHITE);
    bool playerCol = WHITE;

    A.place(a, 7, 0);
    
    EXPECT_TRUE(A.move(playerCol, 7, 0, 6, 0));
    EXPECT_TRUE(A.isOccupied(6,0));
}


TEST_F(test_board, testFirstMoveBlackPieceOneSpaceNotOccupied)
{
    Board A;
    PiecePtr a = new Piece(BLACK);
    bool playerCol = BLACK;

    A.place(a, 0, 0);
    EXPECT_TRUE(A.move(playerCol, 0, 0, 1, 0));
    EXPECT_TRUE(A.isOccupied(1,0));
}


TEST_F(test_board, testFirstMoveWhitePieceForwardTwoSpacesOccupied)
{
    Board A;
    PiecePtr a = new Piece(WHITE);
    PiecePtr b = new Piece(BLACK);
    bool playerCol = WHITE;

    A.place(a, 7, 0);
    A.place(b, 5, 0);

    EXPECT_FALSE(A.move(playerCol, 7, 0, 5, 0));
}


TEST_F(test_board, testFirstMoveBlackPieceForwardTwoSpacesOccupied)
{
    Board A;
    PiecePtr a = new Piece(BLACK);
    PiecePtr b = new Piece(WHITE);
    bool playerCol = BLACK;

    A.place(a, 0, 0);
    A.place(b, 2, 0);

    EXPECT_FALSE(A.move(playerCol, 0, 0, 2, 0));    
}


TEST_F(test_board, testFirstMoveWhitePieceForwardOneSpaceOccupied)
{
    Board A;
    PiecePtr a = new Piece(WHITE);
    PiecePtr b = new Piece(BLACK);
    bool playerCol = WHITE;
    
    A.place(a, 7, 0);
    A.place(b, 5, 0);

    EXPECT_FALSE(A.move(playerCol, 7, 0, 5, 0));
}

TEST_F(test_board, testFirstMoveBlackPieceForwardOneSpaceOccupied)
{
    Board A;
    PiecePtr a = new Piece(BLACK);
    PiecePtr b = new Piece(WHITE);
    bool playerCol = BLACK;

    A.place(a, 0, 0);
    A.place(b, 1, 0);

    EXPECT_FALSE(A.move(playerCol, 0, 0, 1, 0));    
}

TEST_F(test_board, testFirstMoveWhitePieceBlockedPath)
{
    Board A;
    PiecePtr a = new Piece(WHITE);
    PiecePtr b = new Piece(BLACK);
    bool playerCol = WHITE;
    
    A.place(a, 4, 1);
    A.place(b, 3, 1);

    EXPECT_FALSE(A.move(playerCol, 4, 1, 2, 1));
}

TEST_F(test_board, testFirstMoveBlackPieceBlockedPath)
{
    Board A;
    PiecePtr a = new Piece(BLACK);
    PiecePtr b = new Piece(WHITE);
    bool playerCol = BLACK;
    
    A.place(a, 3, 1);
    A.place(b, 4, 1);

    EXPECT_FALSE(A.move(playerCol, 3, 1, 5, 1));
}

TEST_F(test_board, testFirstMoveWhitePieceDiagonalEmpty)
{
    Board A;
    PiecePtr a = new Piece(WHITE);
    bool playerCol = WHITE;
    
    A.place(a, 3, 0);

    EXPECT_FALSE(A.move(playerCol, 3, 0, 2, 1));
}

TEST_F(test_board, testFirstMoveBlackPieceDiagonalEmpty)
{
    Board A;
    PiecePtr a = new Piece(BLACK);
    bool playerCol = BLACK;
    
    A.place(a, 2, 1);

    EXPECT_FALSE(A.move(playerCol, 2, 1, 3, 2));
}

TEST_F(test_board, testFirstMoveWhitePieceDiagonalOccupiedSameColour)
{
    Board A;
    PiecePtr a = new Piece(WHITE);
    PiecePtr b = new Piece(WHITE);
    bool playerCol = WHITE;
    
    A.place(a, 3, 0);
    A.place(b, 2, 1);

    EXPECT_FALSE(A.move(playerCol, 3, 0, 2, 1));
}

TEST_F(test_board, testFirstMoveBlackPieceDiagonalOccupiedSameColour)
{
    Board A;
    PiecePtr a = new Piece(BLACK);
    PiecePtr b = new Piece(BLACK);
    bool playerCol = BLACK;
    
    A.place(a, 2, 1);
    A.place(b, 3, 2);

    EXPECT_FALSE(A.move(playerCol, 2, 1, 3, 2));
}

TEST_F(test_board, testFirstMoveWhitePieceDiagonalOccupiedDiffColour)
{
    Board A;
    PiecePtr a = new Piece(WHITE);
    PiecePtr b = new Piece(BLACK);
    bool playerCol = WHITE;
    
    A.place(a, 3, 0);
    A.place(b, 2, 1);

    EXPECT_TRUE(A.move(playerCol, 3, 0, 2, 1));
}

TEST_F(test_board, testFirstMoveBlackPieceDiagonalOccupiedDiffColour)
{
    Board A;
    PiecePtr a = new Piece(BLACK);
    PiecePtr b = new Piece(WHITE);
    bool playerCol = BLACK;
    
    A.place(a, 2, 1);
    A.place(b, 3, 2);

    EXPECT_TRUE(A.move(playerCol, 2, 1, 3, 2));
}

TEST_F(test_board, testFirstMoveWhitePieceDiagonalTwoSpaces)
{
    Board A;
    PiecePtr a = new Piece(WHITE);
    bool playerCol = BLACK;
    
    A.place(a, 3, 0);
    
    EXPECT_FALSE(A.move(playerCol, 3, 0, 1, 2));
}

TEST_F(test_board, testFirstMoveBlackPieceDiagonalTwoSpaces)
{
    Board A;
    PiecePtr a = new Piece(BLACK);
    bool playerCol = BLACK;
    
    A.place(a, 3, 0);
    
    EXPECT_FALSE(A.move(playerCol, 3, 0, 3, 1));
}

TEST_F(test_board, testMoveWrongPieceColour)
{
    Board A;
    PiecePtr a = new Piece(BLACK);
    bool playerCol = WHITE;

    A.place(a, 1, 1);

    EXPECT_FALSE(A.move(playerCol, 1, 1, 2, 1));
}

TEST_F(test_board, testMoveNoPiece)
{
    Board A;
    bool playerCol = WHITE;

    EXPECT_FALSE(A.move(playerCol, 4, 4, 3, 4));
}

TEST_F(test_board, testMoveBackwards)
{
    Board A;
    PiecePtr a = new Piece(WHITE);

    A.place(a, 3, 1);

    EXPECT_FALSE(A.move(a, 3, 1, 4, 1));
}

TEST_F(test_board, testMoveForwardTwoSpacesTwice)
{
    Board A;
    PiecePtr a = new Piece(WHITE);

    A.place(a, 4, 3);

    EXPECT_TRUE(A.move(a, 4, 3, 2, 3));
    EXPECT_FALSE(A.move(a, 2, 3, 0, 1));
    EXPECT_FALSE(A.isOccupied(0, 1));
    
}

//*******************************************************************************

TEST_F(test_board, testCopyOperator)
{
    Board A;
    Board B;
    PiecePtr a = new Piece(BLACK);

    A.place(a, 4, 4);

    EXPECT_FALSE(B.isOccupied(4, 4));
    B = A;
    EXPECT_TRUE(B.isOccupied(4, 4));
}

