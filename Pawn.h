/*
The Pawn Class Header File

Public Method Functions Specifications:

    getSymbol: Getter function that grabs the character symbol 
               of the a pawn

    canMove: Determines if the pawn can move on the board from 
             a given coordinate to another given coordinate.

    clone: Copies an exact match of the pawn and returns a pointer
           to that piece


*/

#ifndef PAWN_H
#define PAWN_H

class Pawn;
#include "Piece.h"
using namespace std;

class Pawn : public Piece
{
public:

    Pawn(bool col);

    ~Pawn();

    virtual char getSymbol() const;

    virtual bool canMove(const Board& b, int fromX, int fromY, int toX, int toY) const;

    virtual void notifyMoved();

    virtual PiecePtr clone() const;

private:

    bool hasMoved;
    
};

#endif
