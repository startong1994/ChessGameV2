#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn :public  Piece
{
public:
	Pawn(Board *board, int column, int row, bool isBlack);
	string getImageName()
	{
		if (!isBlack) {
			return "pawnW.gif";
		}
		else {
			return "pawnB.gif";
		}
	};

	/**
	* Returns list of all possible moves
	*/
	virtual vector<Move *> getPossibleMoves();
	virtual string getName() { return "Pawn"; };
};


#endif
