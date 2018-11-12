#ifndef PIECE_H
#define PIECE_H


#include<vector>
#include<string>

using namespace std;

class Board;
class Move;

class Piece
{
private:	

public:
	Board *board;
	bool isBlack, moved ;
	int column, row;
public:
	Piece(Board *board,int column,int row,bool isBlack);
	virtual vector<Move *> getPossibleMoves()=0;

	int getColumn()
	{
		return column;
	}

	/**
	* Return row position
	* @return row position
	*/
	int getRow()
	{
		return row;
	}

	/**
	* Sets row position
	* @param value - row to set
	*/
	void setRow(int value)
	{
		row = value;
	}
	void setColumn(int value)
	{
		column = value;
	}

	/**
	* Returns image name
	*/
	virtual string getImageName()
	{
		return "pawnW.gif";
	}

	void setBoard(Board *board)
	{
		this->board = board;
	}

	/**
	* return color
	* @return true if color is white, false if black
	*/
	bool getColor()
	{
		return !isBlack;
	}

	virtual string getName()=0;
	Piece();
    virtual ~Piece();
};

#endif
