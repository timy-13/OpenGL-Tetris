#include "piece.h"

int pieceMatrices[1][4][5][5] = {
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
	this->rotate = 1;

}

Piece::~Piece() {

}

void Piece::drawPiece(glm::vec2 posMatrix[5][5], int type, int rotation, Sprite& sprite, glm::vec3 color) {
	// this->blockMatrix[5][5] = blockMatrix[5][5];

	// int** blockMatrix[5][5] = getPiece(type, rotation);

	

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (pieceMatrices[type][rotation][i][j] == 1) {
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

}

//int** Piece::getPiece(int type, int rotation) {
//	return pieceMatrices [type][rotation][5][5];
//}


// [type][rotation][x][y]

