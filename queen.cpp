#include "Queen.h"
using namespace std;


Queen::Queen(bool col) : Piece (col) {}


Queen::~Queen() {}


char Queen::getSymbol() const
{
    char symbol;

    if (getColour())
    {
	symbol = 'Q';
    }
    else
    {
	symbol = 'q';
    }
    
    return symbol;
}



bool Queen::canMove(const Board& b, int fromX,
		    int fromY, int toX, int toY) const
{
    PiecePtr toPiece = NULL;

    bool canMove = false;
    bool pathIsClear = isPathClear(b, fromX, fromY, toX, toY);
    bool occupied = b.isOccupied(toX,toY);
    bool pieceCol = getColour();
    bool vertCheck = isVertical(fromX, fromY, toX, toY);
    bool horizCheck = isHorizontal(fromX, fromY, toX, toY);
    bool diagCheck = isDiagonal(fromX, fromY, toX, toY);


    
    if(vertCheck && pathIsClear)
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
    else if(horizCheck && pathIsClear)
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
    else if(diagCheck && pathIsClear)
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


void Queen::notifyMoved() {}


PiecePtr Queen::clone() const
{
    PiecePtr piece = new Queen(getColour());
    *piece = *this;
    return piece;    
}
