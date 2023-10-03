#include "board.h"

// [type][rotation][x][y]
int piecesMatrices[7][4][5][5]{
	// L
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 1, 1, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
	   {
			{0, 0, 0, 0, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
	   {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 1, 1, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// L mirror
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 1, 1, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 1, 1, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 0, 0}
		}
    },

	// Square
    {
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		}
    },

	// T
	{
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 1, 1, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 1, 1, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
    },

	// N
	{
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 1, 1, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// N mirror
	{
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},


	// Line
	{
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 1, 1, 1},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0}
		},
	    {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{1, 1, 1, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
	    {
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		}
	}
};

glm::vec2 boardPosMatrix {
	 
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
				this->boardBlockMatrix[y + i][x + j] = 1;
				this->lines[y + j]++;
			}
		}
	}
}

// ERROR: must implement color matrix
// set color in fillPiece
void Board::drawBoard(Sprite &sprite) {
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			if (this->boardBlockMatrix[j][i] == 1) {
				sprite.drawSprite(glm::vec2(i * 30.0, j * 30.0), glm::vec2(BLOCK_SIZE, BLOCK_SIZE), 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
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

