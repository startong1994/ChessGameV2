#ifndef KING_H
#define KING_H


#include "Piece.h"

class King :public Piece
{
public:

    King(Board *board, int column, int row, bool isBlack);
	/**
	* Returns image name
	*/
    virtual string getImageName()
	{
		if (!isBlack) {
			return "kingW.gif";
		}
		else {
			return "kingB.gif";
		}
	};

	/**
	* Returns list of all possible moves
	*/
	vector<Move *> getPossibleMoves();
	virtual string getName() { return "King"; };
	King();
    virtual ~King();
};

#endif
