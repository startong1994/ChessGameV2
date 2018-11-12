#include "Piece.h"
#include "Board.h"



Piece::Piece(Board * board, int column, int row, bool isBlack)
	:board(board), column(column),row(row),isBlack(isBlack)
{
}

vector<Move*> Piece::getPossibleMoves()
{
	return  vector<Move*>();
}

Piece::Piece()
{
}


Piece::~Piece()
{
}
