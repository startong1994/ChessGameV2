#include "Piece.h"
#include "King.h"
#include "Move.h"
#include "Board.h"




King::King(Board * board, int column, int row, bool isBlack)
	:Piece(board,column,row,isBlack)
{
}

vector<Move*> King::getPossibleMoves()
{
	vector<Move *> possibleMoves;
	int curX = column;
	int curY = row;
	int *addArrayX = new int[8] {1, 0, -1, 1, 0, -1, 1, -1};
	int *addArrayY = new int[8] {1, 1, 1, -1, -1, -1, 0, 0};
	for (int i = 0; i < 8; i++) {
		curX = column + addArrayX[i];
		curY = row + addArrayY[i];
		if (curX >= 0 && curX < 8 && curY >= 0 && curY < 8) {
			Piece *temp1 = board->getPiece(curX, curY);
			if (temp1 == NULL) {
				possibleMoves.push_back(new Move(column, row, curX, curY, !isBlack));
			}
			else if (!temp1->getColor() != isBlack) {
				possibleMoves.push_back(new Move(column, row, curX, curY, !isBlack));
			}
		}
	}
	if (!moved) {
		if (!isBlack) {
			Piece *temp1 = board->getPiece(0, 5);
			Piece *temp2 = board->getPiece(0, 6);
			Piece *temp3 = board->getPiece(0, 7);
			if (temp1 == NULL && temp2 == NULL && temp3->getName()=="Rook" && (!temp3->moved)) {
				possibleMoves.push_back(new Move(column, row, 0, 6, !isBlack));
			}
			temp1 = board->getPiece(0, 3);
			temp2 = board->getPiece(0, 2);
			Piece *temp4 = board->getPiece(0, 1);
			temp3 = board->getPiece(0, 0);
			if (temp1 == NULL && temp2 == NULL && temp4 == NULL && temp3->getName() == "Rook" && (!temp3->moved)) {
				possibleMoves.push_back(new Move(column, row, 0, 2, !isBlack));
			}
		}
		else {
			Piece *temp1 = board->getPiece(7, 5);
			Piece *temp2 = board->getPiece(7, 6);
			Piece *temp3 = board->getPiece(7, 7);
			if (temp1 == NULL && temp2 == NULL && temp3->getName() == "Rook" && (!temp3->moved)) {
				possibleMoves.push_back(new Move(column, row, 7, 6, !isBlack));
			}
			temp1 = board->getPiece(7, 3);
			temp2 = board->getPiece(7, 2);
			Piece *temp4 = board->getPiece(7, 1);
			temp3 = board->getPiece(7, 0);
			if (temp1 == NULL && temp2 == NULL && temp4 == NULL && temp3->getName() == "Rook"
				&& (!temp3->moved)) {
				possibleMoves.push_back(new Move(column, row, 7, 2, !isBlack));
			}
		}
	}
	return possibleMoves;
}

King::King()
{
}


King::~King()
{
}
