#include "Pawn.h"
using namespace std;


Pawn::Pawn(bool col) : Piece (col)
{
    hasMoved = false;
}


Pawn::~Pawn() {}


char Pawn::getSymbol() const
{
    char symbol;

    if (getColour())
    {
	symbol = 'P';
    }
    else
    {
	symbol = 'p';
    }
    
    return symbol;
}

bool Pawn::canMove(const Board& b, int fromX,
		    int fromY, int toX, int toY) const
{
    PiecePtr toPiece = NULL;

    bool canMove = false;
    bool pathisClear = isPathClear(b, fromX, fromY, toX, toY);
    bool occupied = b.isOccupied(toX,toY);
    bool forward = isForward(fromX, toX);
    bool pieceCol = getColour();

    int vertDist = vertDistance(fromX, toX);
    int horizDist = horizDistance(fromY, toY);

    if(!hasMoved && forward)
    {
	if((vertDist == 2 && horizDist == 0)
	   && pathisClear) //vertical movement 2 spaces
	{
	    if(!occupied)//if place not occupied
	    {
		canMove = true;
	    }
	}
	else if(vertDist == 1 && horizDist == 0)//vertical movement 1 space
	{
	    if(!occupied)//if place not occupied
	    {
		canMove = true;
	    }
	}
	else if(vertDist == 1 && horizDist == 1)//diagonal movement
	{
	    if(occupied)//spot has to be occupied to move diagonal
	    {
		toPiece = b.getPiece(toX, toY);//get occupying piece colour
		
		if(pieceCol != toPiece->getColour())//compare from piece and to piece colour
		{
		    canMove = true;//if colours are different
		}

		delete toPiece;
	    }
	}
    }
    else if(hasMoved && forward)
    {
	if(vertDist == 1 && horizDist == 0)//vertical movement 1 space
	{
	    if(!occupied)//if place not occupied
	    {
		canMove = true;
	    }
	}
	else if(vertDist == 1 && horizDist == 1)//diagonal movement
	{
	    if(occupied)//spot has to be occupied to move diagonal
	    {
		toPiece = b.getPiece(toX, toY);//get occupying piece colour
		
		if(pieceCol != toPiece->getColour())//compare from piece and to piece colour
		{
		    canMove = true;//if colours are different
		}

		delete toPiece;
	    }
	}
    }

    toPiece = NULL;
    return canMove;
}


void Pawn::notifyMoved()
{
    hasMoved = true;
    return;
}


PiecePtr Pawn::clone() const
{
    PiecePtr piece = new Pawn(getColour());
    *piece = *this;
    return piece;
}
