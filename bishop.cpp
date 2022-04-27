#include "Bishop.h"
using namespace std;


Bishop::Bishop(bool col) : Piece (col) {}


Bishop::~Bishop() {}


char Bishop::getSymbol() const
{
    char symbol;

    if (getColour())
    {
	symbol = 'B';
    }
    else
    {
	symbol = 'b';
    }
    
    return symbol;
}

bool Bishop::canMove(const Board& b, int fromX,
		    int fromY, int toX, int toY) const
{
    PiecePtr toPiece = NULL;

    bool canMove = false;
    bool pathIsClear = isPathClear(b, fromX, fromY, toX, toY);
    bool occupied = b.isOccupied(toX,toY);
    bool pieceCol = getColour();
    bool diagCheck = isDiagonal(fromX, fromY, toX, toY);

    if(diagCheck && pathIsClear)
    {
	if(occupied)
	{
	    toPiece = b.getPiece(toX, toY);
	    
	    if(pieceCol != toPiece->getColour())
	    {
		canMove = true;
	    }

	    delete toPiece;
	}
	else
	{
	    canMove = true;
	}
    }

    return canMove;
}


void Bishop::notifyMoved() {}


PiecePtr Bishop::clone() const
{
    PiecePtr piece = new Bishop(getColour());
    *piece = *this;
    return piece;
    
}
