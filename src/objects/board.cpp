#include "board.h"

int piecesMatrices[1][4][5][5]{

};

Board::Board() {
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			this->board[i][j] = BLOCK_EMPTY;
		}
	}
}

bool Board::isEmptyBlock(int x, int y) {
	if (board[x][y] == BLOCK_EMPTY) {
		return true;
	}
	else {
		return false;
	}
}

bool Board::isMove(int x, int y, int type, int rotation) {
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			if (piecesMatrices[type][rotation][i][j] == 1) {

			}
		}
	}
}

void Board::fillPiece(int x, int y, int type, int rotation) {


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (piecesMatrices[type][rotation][i][j] == 1) {
				board[i][j] = BLOCK_FULL;
			}
		}
	}
}

void Board::deleteLines() {
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {

		}
	}
}

