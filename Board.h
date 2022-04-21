/*
The Board Class Header File

Public Method Functions Specifications:

    Constuctor: Initializes the instantiated board to an empty board.
    
    Deconstructor: Deallocates all pieces from the board and prints piece
                   locations to a file named "final_board.txt".

    isOccupied: Checks the given grid location to see if a piece is 
                at the location or not.

    getPiece: Takes the given coordinates and returns a copy of the piece
              at the given coordinates, or NULL if there is no piece.

    Copy Constructor: Copies a board including all it's pieces to another
                      board object.

    Move: Moves pieces around on the board using coordinates.

    Place: Places pieces on the board for using coordinates.

    Remove: Removes the selected piece from the board using coordinates.

    Write: Writes the board to the given source of output.

    Assignment Operator: Allows the use of the ' = ' operator for board copying.

    Output Operator: Allows the use of the ' << ' to cout the board.
    
*/

#ifndef BOARD_H
#define BOARD_H

class Board;
class Piece;
#include "Piece.h"
#include <iostream>
using namespace std;

#define MAXROWS 8
#define MAXCOLS 8

typedef Piece* PiecePtr;

class Board
{
public:
   Board();
   Board (const Board& other);
   ~Board();

   bool isOccupied (int x, int y) const;
   PiecePtr getPiece (int x, int y) const;

   bool move (bool playerCol, int fromX, int fromY, int toX, int toY);
   bool place (const PiecePtr& p, int x, int y);
   bool remove (int x, int y);
 
   void write (ostream& out) const;

   Board& operator= (const Board& other);

private:
   PiecePtr grid[MAXROWS][MAXCOLS];

   void initBoard();
   void clearBoard();
   void copyBoard(const Board& other);
};

ostream& operator<< (ostream& out, const Board& b);

#endif
