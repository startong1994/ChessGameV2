#include "Piece.h"
#include "Pawn.h"
#include "Move.h"
#include "Board.h"



 
 

Pawn::Pawn(Board * board, int column, int row, bool isBlack)
	:Piece(board, column, row, isBlack)
{
}

vector<Move *> Pawn::getPossibleMoves()
{
	vector<Move *> possibleMoves;
	if (!isBlack) {
		Piece *temp1 = board->getPiece(column + 1, row);
		if (temp1 == NULL) {
			possibleMoves.push_back(new Move(column, row, column + 1, row, !isBlack));
			if (column == 1) {
				temp1 = board->getPiece(column + 2, row);
				if (temp1 == NULL) {
					possibleMoves.push_back(new Move(column, row, column + 2, row, !isBlack));
				}
			}
		}
		temp1 = board->getPiece(column + 1, row + 1);
		if (temp1 != NULL) {
			if (temp1->isBlack) {
				possibleMoves.push_back(new Move(column, row, column + 1, row + 1, !isBlack));
			}
		}
		temp1 = board->getPiece(column + 1, row - 1);
		if (temp1 != NULL) {
			if (temp1->isBlack) {
				possibleMoves.push_back(new Move(column, row, column + 1, row - 1, !isBlack));
			}
		}
		if (column == 4) {
			Pawn *tempPawn = board->getEnpassant();
			if (tempPawn != NULL) {
				if (tempPawn->getRow() - 1 == row || tempPawn->getRow() + 1 == row) {
					possibleMoves.push_back(new Move(column, row, column + 1, tempPawn->getRow(), !isBlack));
				}
			}
		}

	}
	else {
		Piece *temp1 = board->getPiece(column - 1, row);
		if (temp1 == NULL) {
			possibleMoves.push_back(new Move(column, row, column - 1, row, !isBlack));
			if (column == 6) {
				temp1 = board->getPiece(column - 2, row);
				if (temp1 == NULL) {
					possibleMoves.push_back(new Move(column, row, column - 2, row, !isBlack));
				}
			}
		}
		temp1 = board->getPiece(column - 1, row + 1);
		if (temp1 != NULL) {
			if (!temp1->isBlack) {
				possibleMoves.push_back(new Move(column, row, column - 1, row + 1, !isBlack));
			}
		}
		temp1 = board->getPiece(column - 1, row - 1);
		if (temp1 != NULL) {
			if (!temp1->isBlack) {
				possibleMoves.push_back(new Move(column, row, column - 1, row - 1, !isBlack));
			}
		}
		if (column == 3) {
			Pawn *tempPawn = board->getEnpassant();
			if (tempPawn != NULL) {
				if (tempPawn->getRow() - 1 == row || tempPawn->getRow() + 1 == row) {
					possibleMoves.push_back(new Move(column, row, column - 1, tempPawn->getRow(), !isBlack));
				}
			}
		}
	}
	return possibleMoves;
}