#include "Piece.h"
#include "Rook.h"
#include "Move.h"
#include "Board.h"


Rook::Rook(Board * board, int column, int row, bool isBlack)
	:Piece(board, column, row, isBlack)
{
}

/**
* Returns list of all possible moves
*/
vector<Move *> Rook::getPossibleMoves()
{

	vector<Move *> possibleMoves;
	getPossibleRookMoves(possibleMoves);
	return possibleMoves;
}


/**
* Adds possible moves for rook
* @param possibleMoves - list of possible moves
* @return list with added possible moves
*/
vector<Move*> Rook::getPossibleRookMoves(vector<Move*> possibleMoves)
{
	int curX = column;
	int curY = row;
	curX++;
	while (curX < 8) {
		Piece *temp1 = board->getPiece(curX, curY);
		if (temp1 == NULL) {
			possibleMoves.push_back(new Move(column, row, curX, curY, !isBlack));
		}
		else if (!temp1->getColor() != isBlack) {
			possibleMoves.push_back(new Move(column, row, curX, curY, !isBlack));
			break;
		}
		else {
			break;
		}
		curX++;
	}
	curX = column;
	curY = row;
	curX--;
	while (curX >= 0) {
		Piece *temp1 = board->getPiece(curX, curY);
		if (temp1 == NULL) {
			possibleMoves.push_back(new Move(column, row, curX, curY, !isBlack));
		}
		else if (!temp1->getColor() != isBlack) {
			possibleMoves.push_back(new Move(column, row, curX, curY, !isBlack));
			break;
		}
		else {
			break;
		}
		curX--;
	}
	curX = column;
	curY = row;
	curY++;
	while (curY < 8) {
		Piece *temp1 = board->getPiece(curX, curY);
		if (temp1 == NULL) {
			possibleMoves.push_back(new Move(column, row, curX, curY, !isBlack));
		}
		else if (!temp1->getColor() != isBlack) {
			possibleMoves.push_back(new Move(column, row, curX, curY, !isBlack));
			break;
		}
		else {
			break;
		}
		curY++;
	}
	curX = column;
	curY = row;
	curY--;
	while (curY >= 0) {
		Piece *temp1 = board->getPiece(curX, curY);
		if (temp1 == NULL) {
			possibleMoves.push_back(new Move(column, row, curX, curY, !isBlack));
		}
		else if (!temp1->getColor() != isBlack) {
			possibleMoves.push_back(new Move(column, row, curX, curY, !isBlack));
			break;
		}
		else {
			break;
		}
		curY--;
	}
	return possibleMoves;
}




Rook::Rook()
{
}


Rook::~Rook()
{
}
