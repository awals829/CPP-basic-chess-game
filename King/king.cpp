#include "King.h"
using namespace std;


King::King(bool col) : Piece (col) {}


King::~King() {}


char King::getSymbol() const
{
    char symbol;

    if (getColour())
    {
	symbol = 'K';
    }
    else
    {
	symbol = 'k';
    }
    
    return symbol;
}



bool King::canMove(const Board& b, int fromX,
		    int fromY, int toX, int toY) const
{
    PiecePtr toPiece = NULL;

    bool canMove = false;
    bool occupied = b.isOccupied(toX,toY);
    bool pieceCol = getColour();
    bool vertCheck = isVertical(fromX, fromY, toX, toY);
    bool horizCheck = isHorizontal(fromX, fromY, toX, toY);
    bool diagCheck = isDiagonal(fromX, fromY, toX, toY);
	
    int vertDist = vertDistance(fromX, toX);
    int horizDist = horizDistance(fromY, toY);

    if(vertCheck && vertDist == 1)
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
    else if(horizCheck && horizDist == 1)
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
    else if(diagCheck && horizDist == 1 && vertDist == 1)
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


void King::notifyMoved() {}


PiecePtr King::clone() const
{
    PiecePtr piece = new King(getColour());
    *piece = *this;
    return piece;
    
}
