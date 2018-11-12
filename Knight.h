#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
class Knight :
	public Piece
{
public:
	Knight(Board *board, int column, int row, bool isBlack);
	/**
	* Returns image name
	*/
    virtual string getImageName()
	{
		if (!isBlack) {
			return "knightW.gif";
		}
		else {
			return "knightB.gif";
		}
	}

	/**
	* Returns list of all possible moves
	*/
	virtual vector<Move*> getPossibleMoves();
	virtual string getName() { return "Knight"; };
};


#endif
