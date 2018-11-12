#ifndef BOARD_H
#define BOARD_H
#include<vector>
#include<algorithm>

using namespace std;
class Pawn;
class King;
class Piece;
class Move;

class Board
{
private:
	vector<Piece*> pieces;
	//ChessGUI chess;
	Piece *Selected;
	vector<Move*> moves;
	bool whiteMove;
	Pawn *enpassant;
	King *whiteKing;
	King *blackKing;
public:

	void initboard();
	void showMoves(vector<Move*>  moves);
	void makeMove(int x, int y);
	/**
	* Checks for checkmate
	*
	* @param checkWhite - flag for white
	* @return true if checkmate, false otherwise
	*/
	bool isCheckMate(bool checkWhite);

	/** é	
	* Checks if given move is acceptable
	*
	* @param x - column to move
	* @param y - row to move
	* @return true if move is acceptable, false otherwise
	*/
	bool acceptableMove(int x, int y);

	/**
	* Removes moves to check
	*/
	void removeCheckMoves();
	/**
	* Returns piece at given place
	*
	* @param x - column
	* @param y - row
	* @return Piece on given place
	*/
	Piece *getPiece(int x, int y);
	Board();
	~Board();
	/**
	* Returns enpassant
	*
	* @return pawn enpassant
	*/
	Pawn* getEnpassant()
	{
		return enpassant;
	}
	void performMove(int x, int y);
	void removePiece(Piece *piece);
};


#endif
