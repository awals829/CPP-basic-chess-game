/*
The Rook Class Header File

Public Method Functions Specifications:

    getSymbol: Getter function that grabs the character symbol 
               of the bishop piece.

    canMove: Determines if the piece can move diagonally on the board from 
             a given coordinate to another given coordinate.

    clone: Copies an exact match of the bishop and returns a pointer
           to that piece
*/

#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
using namespace std;

class Bishop : public Piece
{
public:

    Bishop(bool col);

    ~Bishop();

    virtual char getSymbol() const;

    virtual bool canMove(const Board& b, int fromX, int fromY, int toX, int toY) const;

    virtual void notifyMoved();

    virtual PiecePtr clone() const;    
};

#endif
