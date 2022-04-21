/*
The King Class Header File

Public Method Functions Specifications:

    getSymbol: Getter function that grabs the character symbol 
               of the king piece.

    canMove: Determines if the piece can move one space in any direction
             on the board from a given coordinate to another given coordinate. 

    clone: Copies an exact match of the king and returns a pointer
           to that piece
*/

#ifndef KING_H
#define KING_H

#include "Piece.h"
using namespace std;

class King : public Piece
{
public:

    King(bool col);

    ~King();

    virtual char getSymbol() const;

    virtual bool canMove(const Board& b, int fromX, int fromY, int toX, int toY) const;

    virtual void notifyMoved();

    virtual PiecePtr clone() const;    
};

#endif
