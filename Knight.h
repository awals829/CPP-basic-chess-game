/*
The Knight Class Header File

Public Method Functions Specifications:

    getSymbol: Getter function that grabs the character symbol 
               of the knight piece.

    canMove: Determines if the piece can move in an L-Shape direction
             on the board from a given coordinate to another given coordinate. 

    clone: Copies an exact match of the knight and returns a pointer
           to that piece
*/

#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
using namespace std;

class Knight : public Piece
{
public:

    Knight(bool col);

    ~Knight();

    virtual char getSymbol() const;

    virtual bool canMove(const Board& b, int fromX, int fromY, int toX, int toY) const;

    virtual void notifyMoved();

    virtual PiecePtr clone() const;
};

#endif
