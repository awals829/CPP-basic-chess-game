/*
The Queen Class Header File

Public Method Functions Specifications:

    getSymbol: Getter function that grabs the character symbol 
               of the queen piece.

    canMove: Determines if the piece can move any direction on the board from 
             a given coordinate to another given coordinate. 

    clone: Copies an exact match of the queen and returns a pointer
           to that piece
*/

#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
using namespace std;

class Queen : public Piece
{
public:

    Queen(bool col);

    ~Queen();

    virtual char getSymbol() const;

    virtual bool canMove(const Board& b, int fromX, int fromY, int toX, int toY) const;

    virtual void notifyMoved();

    virtual PiecePtr clone() const;    
};

#endif
