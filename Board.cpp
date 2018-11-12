#include "Move.h"
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Board.h"



void Board::initboard()
{
    whiteMove = true;
	enpassant = NULL;

	for (int i = 0; i < 8; i++) {
		pieces.push_back(new Pawn(this, 1, i, false));
	}
	for (int i = 0; i < 8; i++) {
		pieces.push_back(new Pawn(this, 6, i, true));
	}
	pieces.push_back(new Rook(this, 0, 0, false));
	pieces.push_back(new Rook(this, 0, 7, false));
	pieces.push_back(new Rook(this, 7, 0, true));
	pieces.push_back(new Rook(this, 7, 7, true));
	pieces.push_back(new Knight(this, 0, 1, false));
	pieces.push_back(new Knight(this, 0, 6, false));
	pieces.push_back(new Knight(this, 7, 1, true));
	pieces.push_back(new Knight(this, 7, 6, true));
	pieces.push_back(new Bishop(this, 0, 2, false));
	pieces.push_back(new Bishop(this, 0, 5, false));
	pieces.push_back(new Bishop(this, 7, 2, true));
	pieces.push_back(new Bishop(this, 7, 5, true));
	pieces.push_back(new Queen(this, 0, 3, false));
    pieces.push_back(new Queen(this, 7, 3, true));

    whiteKing = new King(this, 0, 4, false);
	pieces.push_back(whiteKing);
	blackKing = new King(this, 7, 4, true);
    pieces.push_back(blackKing);
    Selected = NULL;
}

void Board::showMoves(vector<Move*> moves)
{

}

void Board::makeMove(int x, int y)
{
	// Select value        
	if (Selected == NULL) {
		Selected = getPiece(x, y);
		if (Selected == NULL) {
			return;
		}
		if (!((whiteMove && Selected->getColor()) || ((!whiteMove) && (!Selected->getColor())))) {
			Selected = NULL;
		}
		if (Selected != NULL) {
			//chess.getBoard()[Selected->getColumn()][Selected->getRow()].setBorder(BorderFactory.createBevelBorder(0, Color.RED, Color.RED));
			moves = Selected->getPossibleMoves();
			removeCheckMoves();
			showMoves(moves);
		}
	}
	else {
		if (acceptableMove(x, y)) {
			Pawn *prevenpassant = enpassant;
			performMove(x, y);
			if (prevenpassant == enpassant) {
				enpassant = NULL;
			}
			whiteMove = !whiteMove;
		}
//		chess.initilize();
		Selected = NULL;
	}
}

bool Board::isCheckMate(bool checkWhite)
{
	return false;
}

bool Board::acceptableMove(int x, int y)
{
	return true;
}

void Board::removeCheckMoves()
{
}

Piece * Board::getPiece(int x, int y)
{
	for (int i = 0; i <(int)pieces.size(); i++) {
		Piece *temp = pieces[i];
		if (temp->getColumn() == x && temp->getRow() == y) {
			return temp;
		}
	}
	return NULL;
}

Board::Board()
{
}


Board::~Board()
{
}

void Board::performMove(int x, int y)
{

	if (Selected != NULL) {
		if (Selected->getName()=="Pawn") {
			if (abs(Selected->getColumn() - x) == 2) {
				enpassant = (Pawn*)Selected;
			}
			if (enpassant != NULL) {
				if (y == enpassant->getRow() && abs(enpassant->getColumn() - x) == 1) {
					if (enpassant->getRow() != Selected->getRow()) {
						removePiece(enpassant);
						enpassant = NULL;
					}
				}
			}
		}
		Piece *victim = getPiece(x, y);
		removePiece(victim);
		if (Selected->getName()=="King") {
			King *castleKing = (King*)Selected;
			if (castleKing->getColor()) {
				if ((y - Selected->row) == 2) {
					Piece *castileRock = getPiece(0, 7);
					castileRock->setRow(5);
				}
				if ((Selected->row - y) == 2) {
					Piece *castileRock = getPiece(0, 0);
					castileRock->setRow(3);
				}
			}
			else {
				if ((y - Selected->row) == 2) {
					Piece *castileRock = getPiece(7, 7);
					castileRock->setRow(5);
				}
				if ((Selected->row - y) == 2) {
					Piece *castileRock = getPiece(7, 0);
					castileRock->setRow(3);
				}
			}

		}
		Selected->setColumn(x);
		Selected->setRow(y);
		//Selected->Move();
		if (Selected->getName()=="Pawn") {
			if (x == 7 || x == 0) {
				Piece* oldQueen = Selected;
				removePiece(Selected);
				Selected = new Queen(this, oldQueen->getColumn(), oldQueen->getRow(), !oldQueen->getColor());
				pieces.push_back(Selected);
				oldQueen = NULL;
			}
		}

    }
}

void Board::removePiece(Piece * piece)
{
	std::vector<Piece*>::iterator position = std::find(pieces.begin(), pieces.end(), piece);
	if (position != pieces.end()) // == myVector.end() means the element was not found
		pieces.erase(position);
}

