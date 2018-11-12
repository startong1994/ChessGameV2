#ifndef ROOK_H
#define  ROOK_H


#include "Piece.h"
class Rook :
	public Piece
{
public:
	Rook(Board *board, int column, int row, bool isBlack);
	virtual string getImageName()
	{
		if (!isBlack)
		{
			return "rookW.gif";
		}
		else
		{
			return "rookB.gif";
		}
	}

	/**
	* Returns list of all possible moves
	*/
	vector<Move *> getPossibleMoves();

	/**
	* Adds possible moves for rook
	* @param possibleMoves - list of possible moves
	* @return list with added possible moves
	*/
	virtual vector<Move*> getPossibleRookMoves(vector<Move*> possibleMoves);
	virtual string getName() { return "Rook"; };
	Rook();
	~Rook();
};


#endif
