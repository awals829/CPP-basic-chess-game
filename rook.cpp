#include "Rook.h"
using namespace std;


Rook::Rook(bool col) : Piece (col) {}


Rook::~Rook() {}


char Rook::getSymbol() const
{
    char symbol;

    if (getColour())
    {
	symbol = 'R';
    }
    else
    {
	symbol = 'r';
    }
    
    return symbol;
}



bool Rook::canMove(const Board& b, int fromX,
		    int fromY, int toX, int toY) const
{
    PiecePtr toPiece = NULL;

    bool canMove = false;
    bool pathIsClear = isPathClear(b, fromX, fromY, toX, toY);
    bool occupied = b.isOccupied(toX,toY);
    bool pieceCol = getColour();
    bool vertCheck = isVertical(fromX, fromY, toX, toY);
    bool horizCheck = isHorizontal(fromX, fromY, toX, toY);

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

    return canMove;
}


void Rook::notifyMoved() {}


PiecePtr Rook::clone() const
{
    PiecePtr piece = new Rook(getColour());
    *piece = *this;
    return piece;
    
}
