/*
The Piece Class Header File

Public Method Functions Specifications:

    Piece: Initializes a piece to a colour boolean, either WHITE (true)
           or BLACK (false).

    getSymbol: Getter function that grabs the character symbol 
               of the chosen piece.

    getColour: Getter function that grabs the boolean colour 
               of the chosen piece.

    canMove: Determines if the piece can move on the board from 
             a given coordinate to another given coordinate.

    notifyMoved: Notifies the piece that it has moved at least once
                 by setting the hasMoved boolean to true.

*/

#ifndef PIECE_H
#define PIECE_H

class Piece;
class Board;
#include "Board.h"
#include <iostream>
#include <cmath>
using namespace std;

#define WHITE true
#define BLACK false

typedef Piece* PiecePtr;

class Piece
{
public:
    Piece (bool col);

    virtual ~Piece();

    virtual char getSymbol() const = 0;

    bool getColour() const;

    virtual bool canMove(const Board& b,
                       int fromX, int fromY, int toX, int toY) const = 0;

    virtual void notifyMoved();

    virtual PiecePtr clone() const = 0;

protected:

    bool isVertical (int fromX, int fromY, int toX, int toY) const;

    bool isHorizontal (int fromX, int fromY, int toX, int toY) const;

    bool isDiagonal (int fromX, int fromY, int toX, int toY) const;

    bool isForward (int fromX, int toX) const;

    int vertDistance (int fromX, int toX) const;

    int horizDistance (int fromY, int toY) const;

    bool isPathClear (const Board& b, int fromX,
		      int fromY, int toX, int toY) const;

private:

    bool colour;

    bool hasMoved;
};

#endif
