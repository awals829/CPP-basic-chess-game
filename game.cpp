/*
    Details: Sets up a chess game on a board for two players to
             alternate turns moving pieces around on the board.
	     The game ends when a user enters the coordinates (-1, -1),
	     or a king piece on either side is captured.
*/


#include "Board.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "ioutil.h"
#include <iostream>

using namespace std;

void gameSetup(Board &main, int x, int y);
void pieceInfoMenu();
void gamePrimary(Board &gameBoard, int x, int y);
void coordinateMenu(int &x, int &y, bool &eof);
bool kingCheck(Board &main, int x, int y);

int main()
{
    Board gameBoard;
    
    int x = 0,
	y = 0;
    
    gameSetup (gameBoard, x, y);
    
    pieceInfoMenu();

    gamePrimary(gameBoard, x, y);

    return 0;
}


/*

gameprimary runs the game the players play

*/
void gamePrimary(Board &gameBoard, int x, int y)
{
    int fromX = 0,
	fromY = 0,
	toX = 0,
	toY = 0;

    bool playerCol = WHITE,
	 move,
	 eof,
	 king = false;

    char trigger;

    while(trigger != 'q')
    {
	cout << "\n\n====== The Current Game Board ======\n"
	     << endl
	     << gameBoard;

	if(playerCol == WHITE)
	{
	    cout << "=========================\n"
		 << "Player 1's (White) Turn: \n"
		 << "=========================\n";
	}
	else
	{
	    cout << "=========================\n"
		 << "Player 2's (Black) Turn: \n"
		 << "=========================\n";
	}

	cout << "\nENTER YOUR PIECE FROM COORDINATES\n";
	
	coordinateMenu(fromX, fromY, eof);
	    
	if(fromX == -1 || fromY == -1)
	{
	    trigger = 'q';
	}
	else
	{
	    cout << "\nENTER YOUR PIECE DESTINATION COORDINATES\n";
	    coordinateMenu(toX, toY, eof);
	    
	    if(toX == -1 || toY == -1)
	    {
		trigger = 'q';
	    }
	    else
	    {
		king = kingCheck(gameBoard, toX, toY);
		move = gameBoard.move(playerCol, fromX, fromY, toX, toY);

		if(move && king)
		{
		    if(playerCol == WHITE)
		    {
			cout << "\n-----------------------------\n"
			     << "\n         Player 1 Win's!!    \n"
			     << "\n          Ending Game        \n"
			     << "\n-----------------------------\n"
			     << gameBoard;
		    }
		    else
		    {
			cout << "\n-----------------------------\n"
			     << "\n         Player 2 Win's!!    \n"
			     << "\n          Ending Game        \n"
			     << "\n-----------------------------\n"
			     << gameBoard;
		    }

		    trigger = 'q';
		}
		else if(move && !king)
		{
		    playerCol = !playerCol;
		}
		else
		{
		    cout << endl << endl
			 << "===============================================\n"
			 << "=====                                     =====\n"
			 << "=====            ILLEGAL MOVE             =====\n"
			 << "=====                                     =====\n"
			 << "===============================================\n";
		}
	    }
	}	    
    }

    cout << "\n====================\n"
	 << " THANKS FOR PLAYING"
	 << "\n====================\n";
    
    return;
}


/*

  gameSetup initilizes all the pieces necessary
  for a chess game to be placed onto a board.

*/
void gameSetup(Board &main, int x, int y)
{

    //--------------------------------------------
    
    for(y = 0; y < MAXCOLS; y++)
    {
        PiecePtr temp = new Pawn(BLACK);
	main.place(temp, 1, y);
    }

    for(y = 0;y < MAXCOLS; y++)
    {
        PiecePtr temp = new Pawn(WHITE);
	main.place(temp, 6, y);
    }

    //--------------------------------------------
    
    PiecePtr KingBlack = new King(BLACK);
    PiecePtr KingWhite = new King(WHITE);

    main.place(KingBlack, 0, 4);
    main.place(KingWhite, 7, 4);

    //--------------------------------------------

    PiecePtr QueenBlack = new Queen(BLACK);
    PiecePtr QueenWhite = new Queen(WHITE);

    main.place(QueenBlack, 0, 3);
    main.place(QueenWhite, 7, 3);

    //--------------------------------------------
    
    PiecePtr RookBlack1 = new Rook(BLACK);
    PiecePtr RookBlack2 = new Rook(BLACK);
    
    PiecePtr RookWhite1 = new Rook(WHITE);
    PiecePtr RookWhite2 = new Rook(WHITE);

    main.place(RookBlack1, 0, 0);
    main.place(RookBlack2, 0, 7);

    main.place(RookWhite1, 7, 0);
    main.place(RookWhite2, 7, 7);

    //--------------------------------------------

    PiecePtr BishopBlack1 = new Bishop(BLACK);
    PiecePtr BishopBlack2 = new Bishop(BLACK);
    
    PiecePtr BishopWhite1 = new Bishop(WHITE);
    PiecePtr BishopWhite2 = new Bishop(WHITE);

    main.place(BishopBlack1, 0, 2);
    main.place(BishopBlack2, 0, 5);

    main.place(BishopWhite1, 7, 2);
    main.place(BishopWhite2, 7, 5);

    //--------------------------------------------

    PiecePtr KnightBlack1 = new Knight(BLACK);
    PiecePtr KnightBlack2 = new Knight(BLACK);
    
    PiecePtr KnightWhite1 = new Knight(WHITE);
    PiecePtr KnightWhite2 = new Knight(WHITE);

    main.place(KnightBlack1, 0, 1);
    main.place(KnightBlack2, 0, 6);

    main.place(KnightWhite1, 7, 1);
    main.place(KnightWhite2, 7, 6);

    //--------------------------------------------
    
    return;
}


/*

  pieceInfoMenu displays a prompt to the screen with information about
  how the pieces are assigned to the players and their symbolizations.

*/
void pieceInfoMenu()
{
        cout << endl
	 << "============================================================\n"
	 << "WHITE Pieces are on the BOTTOM denoted by uppercase letters \n"
	 << "============================================================\n"
	 << endl
	 << "=====================================================\n"
	 << "BLACK Pieces are on TOP denoted by lowercase letters \n"
	 << "=====================================================\n"
	 << endl
	 << "**** Player 1 is White and Player 2 is Black ****\n\n";

	return;
}


/*

  kingCheck determine if the piece at the location is a king,
  if a king is found at this location a boolean of true is returned.

*/
bool kingCheck(Board &main, int x, int y)
{
    bool check = false;

    if(main.isOccupied(x, y))
    {
	PiecePtr checkKing = main.getPiece(x, y);

	if(checkKing->getSymbol() == 'K'
	   || checkKing->getSymbol() == 'k')
	{
	    check = true;
	}
	delete checkKing;
    }
    return check;
}


/*

  coordinateMenu takes in the given user coordinate information
  and determine if the info is valid. If the coordinates are not
  valid then it reprompts the user for a correct set of coordinates.

*/
void coordinateMenu(int &x, int &y, bool &eof)
{
    cout << "\nEnter your piece row and column\n"
	 << "**** Enter -1 in either prompt to exit ****\n\n";
    x = readInt("Enter Row Coordinate: ", eof);
    cout << endl;
    y = readInt("Enter Column Coordinate: ", eof);

    while ((x < -1 || y < -1) ||
	   (x > MAXROWS - 1 || y > MAXCOLS - 1))
    {
	cout << endl << endl
	     << "===============================================\n"
	     << "=====                                     =====\n"
	     << "=====          INVALID COORDINATE         =====\n"
	     << "=====                                     =====\n"
	     << "===============================================\n";

	x = readInt("Enter Row Coordinate: ", eof);
	cout << endl;
	y = readInt("Enter Column Coordinate: ", eof);
    }
    
    return;
}
