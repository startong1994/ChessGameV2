#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Move.h"
#include "Board.h"


 
Queen::Queen(Board * board, int column, int row, bool isBlack)
	:Rook(board, column, row, isBlack)
{
}

vector<Move*> Queen::getPossibleMoves()

{
	Bishop *bishop = new Bishop(board,getColumn(),getRow(), isBlack);
	vector<Move *> possibleMoves;
	bishop->getPossibleBishopMoves(possibleMoves);
	getPossibleRookMoves(possibleMoves);
	return possibleMoves;
}
