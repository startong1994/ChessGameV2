
#include "Piece.h"
#include "Bishop.h"
#include "Move.h"
#include "Board.h"




Bishop::Bishop(Board * board, int column, int row, bool isBlack)
	:Piece(board, column, row, isBlack)
{

}

vector<Move*> Bishop::getPossibleBishopMoves(vector<Move*> possibleMoves)

{
	int curX = column;
	int curY = row;
	curX++;
	curY++;
	while (curX < 8 && curY < 8) {
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
		curY++;
	}
	curX = column;
	curY = row;
	curX++;
	curY--;
	while (curX < 8 && curY >= 0) {
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
		curY--;
	}
	curX = column;
	curY = row;
	curX--;
	curY++;
	while (curX >= 0 && curY < 8) {
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
		curY++;
	}
	curX = column;
	curY = row;
	curX--;
	curY--;
	while (curX >= 0 && curY >= 0) {
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
		curY--;
	}



	return possibleMoves;
};
