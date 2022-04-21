/*
The Piece Class Member File

Private Data Member Specifications:

    Colour: Determines the colour of the piece by a set boolean, 
            WHITE (true) and BLACK (false);

    hasMoved: Boolean which states if the piece has already moved or not.


Private Member Function Specifications:

    isVertical: Checks to see if a piece being moved is moving vertically

    isHorizontal: Checks to see if a piece being moved is moving horizontally

    isDiagonal: Checks to see if a piece being moved is moving vertically

    isForward: Checks to see if a piece being moved is moving forward

    vertDistance: Calculates the vertical distance of squares being 
                  moved by the piece 

    horizDistance: Calculates the horizontal distance of squares being 
                   moved by the piece 

    isPathClear: Checks to see if the path between the piece locations and the
                 destination given is clear of all pieces. 

*/


#include "Piece.h"
#include "Board.h"

using namespace std;



//Public Functions

Piece::Piece(bool col)
{
    colour = col;
}

Piece::~Piece()
{}

bool Piece::getColour() const
{
    return colour;
}

void Piece::notifyMoved()
{}




// Private Functions

bool Piece::isVertical(int fromX, int fromY, int toX, int toY) const
{
    bool verticalMove = false;

    if (fromY == toY && fromX != toX)
    {
	verticalMove = true;
    }
    
    return verticalMove;
}


bool Piece::isHorizontal (int fromX, int fromY, int toX, int toY) const
{
    bool horizontalMove = false;

    if(fromX == toX && fromY != toY)
    {
	horizontalMove = true;
    }
    
    return horizontalMove;
}


bool Piece::isDiagonal (int fromX, int fromY, int toX, int toY) const
{
    bool diagonalMove = false;
    int vertDist = vertDistance (fromX, toX);
    int horizDist = horizDistance (fromY, toY);
    
    if((fromX != toX && fromY != toY) && 
       (vertDist == horizDist))
    {
	diagonalMove = true;
    }
    
    return diagonalMove;
}


bool Piece::isForward (int fromX, int toX) const
{
    bool forward = false;

    if(getColour() && fromX > toX)
    {
	forward = true;
    }
    else if (!getColour() && fromX < toX)
    {
	forward = true;
    }
    
    return forward;
}


 int Piece::vertDistance (int fromX, int toX) const
{
    return abs(fromX - toX);
}


int Piece::horizDistance (int fromY, int toY) const
{
    return abs(fromY - toY);
}


bool Piece::isPathClear (const Board& b, int fromX,
			 int fromY, int toX, int toY) const
{
    int x, y;
    bool pathIsClear = true;

    if(isVertical(fromX, fromY, toX, toY))
    {
	if(fromX > toX)
	{
	    for(x = fromX - 1; x > toX && pathIsClear != false; x--)
	    {
		if(b.isOccupied(x, toY))
		{
		    pathIsClear = false;
		}
	    }
	}
	else
	{
	    for(x = fromX + 1; x < toX && pathIsClear != false; x++)
	    {
		if(b.isOccupied(x, toY))
		{
		    pathIsClear = false;
		}
	    }
	}
    }

    else if(isHorizontal(fromX, fromY, toX, toY))
    {
	if(fromY < toY)
	{
	    for(y = fromX + 1; y < toY && pathIsClear != false; y++)
	    {
		if(b.isOccupied(toX, y))
		{
		    pathIsClear = false;
		}
	    }
	}
	else
	{
	    for(y = fromY - 1; y > toY && pathIsClear != false; y--)
	    {
		if(b.isOccupied(toX, y))
		{
		    pathIsClear = false;
		}
	    }
	}
    }

    else if(isDiagonal(fromX, fromY, toX, toY))
    {
	if(fromX > toX && fromY > toY)
	{	    
	    for(x = fromX - 1, y = fromY - 1; x > toX && y > toY
		    && pathIsClear != false; x--, y--)
            {
		if(b.isOccupied(x, y))
		{
		    pathIsClear = false;
		}
            
            }
        }
	else if(fromX > toX && fromY < toY)
	{	    
	    for(x = fromX - 1, y = fromY + 1; x > toX && y < toY
		    && pathIsClear != false; x--, y++)
            {
		if(b.isOccupied(x, y))
		{
		    pathIsClear = false;
		}
            
            }
        }
	else if(fromX < toX && fromY > toY)
	{	    
	    for(x = fromX + 1, y = fromY - 1; x < toX && y > toY
		    && pathIsClear != false; x++, y--)
            {
		if(b.isOccupied(x, y))
		{
		    pathIsClear = false;
		}
            
            }
        }
	else if(fromX < toX && fromY < toY)
	{	    
	    for(x = fromX + 1, y = fromY + 1; x < toX && y < toY
		    && pathIsClear != false; x++, y++)
            {
		if(b.isOccupied(x, y))
		{
		    pathIsClear = false;
		}
            
            }
        }
    }
    
    return pathIsClear;
}
