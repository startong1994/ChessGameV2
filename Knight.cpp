
#include "Piece.h"
#include "Knight.h"
#include "Move.h"
#include "Board.h"



Knight::Knight(Board * board, int column, int row, bool isBlack)
    :Piece(board,column,row,isBlack)
{
}

vector<Move*> Knight::getPossibleMoves()
{
	vector<Move *> possibleMoves;
	int curX = column;
	int curY = row;
	int addArrayX[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
	int addArrayY[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
	for (int i = 0; i < 8; i++) {
		curX = getColumn() + addArrayX[i];
		curY = getRow() + addArrayY[i];
		if (curX >= 0 && curX < 8 && curY >= 0 && curY < 8) {
			Piece *temp1 = board->getPiece(curX, curY);
			if (temp1 == NULL) {
				possibleMoves.push_back(new Move(getColumn(), getRow(), curX, curY, !isBlack));
			}
			else if (!temp1->getColor() != isBlack) {
				possibleMoves.push_back(new Move(getColumn(), getRow(), curX, curY, !isBlack));
			}
		}
	}
	return possibleMoves;
}
