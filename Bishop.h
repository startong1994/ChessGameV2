#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop(Board *board, int column, int row, bool isBlack);
	/**
	* Returns image name
	*/
	virtual string getImageName()
	{
		if (!isBlack)
		{
			return "bishopW.gif";
		}
		else
		{
			return "bishopB.gif";
		}
	};



	/**
	* Returns list of all possible moves
	*/
	virtual vector<Move *> getPossibleMoves()
	{

		vector<Move *> possibleMoves;
		getPossibleBishopMoves(possibleMoves);
		return possibleMoves;
	};

	/**
	* Adds possible moves for bishop
	* @param possibleMoves - list of possible moves
	* @return list with added possible moves
	*/
	vector<Move*> getPossibleBishopMoves(vector<Move*> possibleMoves);
	virtual string getName() { return "Bishop"; };

};

