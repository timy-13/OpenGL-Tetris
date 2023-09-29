#include "piece.h"

// [type][x][y]
int pieceMatrices[1][5][5] = {
	// L
	{
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
	}
};


Piece::Piece() {

}
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25
Piece::Piece(glm::vec2 posMatrix[5][5], glm::vec3 color) : color(color) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			this->posMatrix[i][j] = posMatrix[i][j];
		}
	}

	this->centerPos = posMatrix[2][2];
	this->left = false;
	this->right = false;
	this->rotation = 0;

}

Piece::~Piece() {

}

void Piece::drawPiece(glm::vec2 posMatrix[5][5], int type, Sprite& sprite, glm::vec3 color) {
	// this->blockMatrix[5][5] = blockMatrix[5][5];

	// int** blockMatrix[5][5] = getPiece(type, rotation);

	

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (pieceMatrices[type][i][j] == 1) {
				sprite.drawSprite(this->posMatrix[i][j], glm::vec2(BLOCK_SIZE, BLOCK_SIZE), 0.0f, color);
			}
		}
	}

	this->centerPos = posMatrix[2][2];
}

void Piece::moveLeft() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			this->posMatrix[i][j].x -= BLOCK_SIZE;
		}
	}
}

void Piece::moveRight() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			this->posMatrix[i][j].x += BLOCK_SIZE;
		}
	}
}

void Piece::moveDown() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			this->posMatrix[i][j].y -= BLOCK_SIZE;
		}
	}
}

void Piece::rotatePiece() {
	for (int j = 0; j < 2; j++) {
		for (int i = j; i < 4 - j; i++) {
			glm::vec2 temp = this->posMatrix[i][j];
			this->posMatrix[i][j] = this->posMatrix[4 - j][i];
			this->posMatrix[4 - j][i] = this->posMatrix[4 - i][4 - j];
			this->posMatrix[4 - i][4 - j] = this->posMatrix[j][4 - i];
			this->posMatrix[j][4 - i] = temp;

		}
	}

}

