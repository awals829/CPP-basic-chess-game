#include "Knight.h"
using namespace std;


Knight::Knight(bool col) : Piece (col) {}


Knight::~Knight() {}


char Knight::getSymbol() const
{
    char symbol;

    if (getColour())
    {
	symbol = 'N';
    }
    else
    {
	symbol = 'n';
    }
    
    return symbol;
}

bool Knight::canMove(const Board& b, int fromX,
		    int fromY, int toX, int toY) const
{
    PiecePtr toPiece = NULL;

    bool canMove = false;
    bool occupied = b.isOccupied(toX,toY);
    bool pieceCol = getColour();

    int vertDist = vertDistance(fromX, toX);
    int horizDist = horizDistance(fromY, toY);

    if(vertDist == 2 && horizDist == 1)
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
    else if(vertDist == 1 && horizDist == 2)
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


void Knight::notifyMoved() {}


PiecePtr Knight::clone() const
{
    PiecePtr piece = new Knight(getColour());
    *piece = *this;
    return piece;
    
}
