/*
The Rook Class Header File

Public Method Functions Specifications:

    getSymbol: Getter function that grabs the character symbol 
               of the rook piece.

    canMove: Determines if the piece can move vertically or horizontally 
             on the board from a given coordinate to another given coordinate. 

    clone: Copies an exact match of the rook and returns a pointer
           to that piece
*/

#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
using namespace std;

class Rook : public Piece
{
public:

    Rook(bool col);

    ~Rook();

    virtual char getSymbol() const;

    virtual bool canMove(const Board& b, int fromX, int fromY, int toX, int toY) const;

    virtual void notifyMoved();

    virtual PiecePtr clone() const;    
};

#endif
