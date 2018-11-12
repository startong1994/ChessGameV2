#ifndef QUEEN_H
#define QUEEN_H

#include "Rook.h"

class Queen:public Rook
{
public:
	Queen(Board *board, int column, int row, bool isBlack);
	/**
	* Returns image name
	*/
	string getImageName()
	{
		if (!isBlack)
		{
			return "queenW.gif";
		}
		else
		{
			return "queenB.gif";
		}
	}

	/**
	* Returns list of all possible moves
	*/
	virtual vector<Move *> getPossibleMoves();
	virtual string getName() { return "Queen"; };

};


#endif
