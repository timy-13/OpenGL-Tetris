#include "board.h"

int piecesMatrices[1][1][5][5]{
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		}
		
	}
};

Board::Board() {

	this->boardBlockMatrix.assign(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0));
	
	this->lines.assign(BOARD_HEIGHT, 0);

}

Board::~Board() {
	
}

bool Board::isEmptyBlock(int x, int y) {
	if (boardBlockMatrix[y][x] == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Board::isMove(int x, int y, int type, int rotation) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			// can move down
			if (piecesMatrices[type][rotation][i][j] == 1 && (x+j < 0 || x+j >= BOARD_WIDTH || y+i >= BOARD_HEIGHT)) {
				return false;
			}

			// is touching another block
			if (piecesMatrices[type][rotation][i][j] == 1) {
				if (this->boardBlockMatrix[y + i][x + j] == 1) {
					return false;
				}
			}
		}
	}

	return true;
}

void Board::fillPiece(int x, int y, int type, int rotation, Sprite& sprite, glm::vec3 color) {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (piecesMatrices[type][rotation][i][j] == 1) {
				sprite.drawSprite(glm::vec2((x+j)*30.0f, (y+i)*30.0f), glm::vec2(BLOCK_SIZE, BLOCK_SIZE), 0.0f, color);
				this->boardBlockMatrix[y + i][x + j] = 1;
				this->lines[y + j]++;
			}
		}
	}
}

void Board::deleteLines() {

	std::vector<std::vector<int>>::iterator iter; // block matrix iterator
	iter = this->boardBlockMatrix.begin();

	for (auto it = this->lines.begin(); it != this->lines.end(); it++) {
		iter++;
		if (*it == 10) {
			this->boardBlockMatrix.erase(iter); // delete line
			this->boardBlockMatrix.insert(this->boardBlockMatrix.begin(), std::vector<int>(BOARD_WIDTH, 0)); // add line of 0 at top

			this->lines.erase(it); // delete line checker
			this->lines.insert(this->lines.begin(), 0); // add line at top
		}
	}
}

