/*
The Board Class Public Member File

Private Data Member Specification

    grid[][]: A Multidimensional array that points to individual pieces at
              a set of given index coordinates.

Private Member Function Specifications:

    initBoard: Initializes the entire board grid to point to NULL for a new
               board.

    clearBoard: Deletes/Deallocates all pieces on the grid and setting each
                location on the grid to NULL.

    copyBoard: Copies one board object to another board object.
*/


#include "Board.h"
#include "Piece.h"
#include <iostream>
#include <fstream>

using namespace std;

//===============================================================================
//===============================================================================

Board::Board()
{
    initBoard();
}

//===============================================================================
//===============================================================================

Board::Board (const Board& other)
{
    initBoard();
    copyBoard(other);
}

//===============================================================================
//===============================================================================

Board::~Board()
{
    int x, y;
    ofstream outfile;
    
    outfile.open("final_board.txt");

    for(x = 0; x < MAXROWS; x++)
    {
	for(y = 0; y < MAXCOLS; y++)
	{
	    if(grid[x][y] != NULL) 
	    {
		outfile << grid[x][y]->getSymbol() << ' ' << x << ' ' << y << endl;
	    }
	}
    }

    outfile.close();
    clearBoard();
}

//===============================================================================

bool Board::isOccupied (int x, int y) const
{
    bool occupied = true;

    if (grid[x][y] == NULL)
    {
	occupied = false;
    }

    return occupied;
    
}


//===============================================================================


PiecePtr Board::getPiece(int x, int y) const
{
    PiecePtr temp = NULL;

    if(grid[x][y] != NULL)
    {
	temp = grid[x][y]->clone(); 
    }

    return temp;
}


//===============================================================================
//===============================================================================


bool Board::move (bool playerCol, int fromX, int fromY, int toX, int toY)
{
    bool move = false;

    if(isOccupied(fromX, fromY))
    {
	if(playerCol == grid[fromX][fromY]->getColour())
	{
	    if(grid[fromX][fromY]->canMove(*this, fromX, fromY, toX, toY))
	    {
		if(isOccupied(toX, toY))
		{
		    PiecePtr p = grid[fromX][fromY]->clone();
		    remove(toX, toY);
		    remove(fromX, fromY);
		    place(p, toX, toY);
		    p->notifyMoved();
		    move = true;
		}
		else
		{
		    PiecePtr p = grid[fromX][fromY]->clone();
		    remove(fromX, fromY);
		    place(p, toX, toY);
		    p->notifyMoved();
		    move = true;
		}
	    }
	}
    }

    return move;
}

//===============================================================================
//===============================================================================

bool Board::place (const PiecePtr& p, int x, int y)
{
    bool placed = false;

    if(grid[x][y] == NULL)
    {
	grid[x][y] = p;
	placed = true;
    }

    return placed;
}

//===============================================================================
//===============================================================================

bool Board::remove (int x, int y)
{
    bool removed = false;

    if(grid[x][y] != NULL)
    {
	delete grid[x][y];
	grid[x][y] = NULL;
	removed = true;
    }

    return removed;
}

//===============================================================================
//===============================================================================

void Board::write (ostream& out) const
{
    int x, y;

    out << "  ";
    
    for(y = 0; y < MAXCOLS ; y++)
    {
	out << "  " << y << " ";
    }
    out << endl;

    for(x = 0; x < MAXROWS; x++)
    {
	out << "  ";
	for(y = 0; y < MAXCOLS; y++)
	{
	    out << "+---";
	}
	out << "+\n";

	out << x << " ";
	for(y = 0; y < MAXCOLS; y++)
	{
	    if(grid[x][y] != NULL)
	    {
		out <<"| " << grid[x][y]->getSymbol() << ' ';
	    }
	    else
	    {
	       out <<"|   ";
	    }
	}
	out <<'|';
	out << endl;
    }

    out << "  ";
    for(y = 0; y < MAXCOLS; y++)
    {
	out << "+---";
    }
    out << "+\n";
    out << endl;
    
    return;
}

//===============================================================================
//===============================================================================

Board& Board::operator= (const Board& other)
{
    if(this != &other)
    {
	clearBoard();
	copyBoard(other);
    }

    return *this;
}

//===============================================================================
//===============================================================================

void Board::initBoard()
{
    int x, y;

    for(x = 0; x < MAXROWS; x++)
    {
	for(y = 0; y < MAXCOLS; y++)
	{
	    grid[x][y] = NULL;
	}
    }

    return;
}

//===============================================================================
//===============================================================================

void Board::clearBoard()
{
    int x, y;

    for(x = 0; x < MAXROWS; x++)
    {
	for(y = 0; y < MAXCOLS; y++)
	{
	    if(grid[x][y] != NULL) 
	    {
		delete grid[x][y];
		grid[x][y] = NULL;
	    }
	}
    }
    
    return;
}

//===============================================================================
//===============================================================================

void Board::copyBoard(const Board& other)
{
    int x, y;

    for(x = 0; x < MAXROWS; x++)
    {
	for(y = 0; y < MAXCOLS; y++)
	{
	    if (other.grid[x][y] != NULL)
	    {
		grid[x][y] = other.grid[x][y]->clone();
	    }
	}
    }
    
    return;
}

//===============================================================================
//===============================================================================

ostream& operator << (ostream& out, const Board& board)
{
    board.write(out);
    return out;
}

//===============================================================================
//===============================================================================
