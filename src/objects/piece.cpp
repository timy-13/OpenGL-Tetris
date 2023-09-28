#include "piece.h"


Piece::Piece() {

}
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25
Piece::Piece(T blockMatrix[5][5], glm::vec3 color) : color(color) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			this->blockMatrix[i][j] = blockMatrix[i][j];
		}
	}
}

Piece::~Piece() {

}

void Piece::drawPiece(T blockMatrix[5][5], Sprite &sprite, glm::vec3 color) {
	// this->blockMatrix[5][5] = blockMatrix[5][5];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (this->blockMatrix[i][j].first == 1) {
				sprite.drawSprite(this->blockMatrix[i][j].second, glm::vec2(BLOCK_SIZE, BLOCK_SIZE), 0.0f, color);
			}
		}
	}

	this->centerPos = blockMatrix[2][2].second;
}

void Piece::moveLeft() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			this->blockMatrix[i][j].second.x -= BLOCK_SIZE;
		}
	}
}

void Piece::moveRight() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			this->blockMatrix[i][j].second.x += BLOCK_SIZE;
		}
	}
}

void Piece::moveDown() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			this->blockMatrix[i][j].second.y -= BLOCK_SIZE;
		}
	}
}

T Piece::getPiece(std::string pieceName, int rotation) {
	
}

T Square[5][5] = {
	{T(0, glm::vec2(0.0, 0.0)), T(0, glm::vec2(30.0, 0.0)), T(0, glm::vec2(60.0, 0.0)), T(0, glm::vec2(90.0, 0.0)), T(0, glm::vec2(120.0, 0.0))},
	{T(0, glm::vec2(0.0, 30.0)), T(0, glm::vec2(30.0, 30.0)), T(0, glm::vec2(60.0, 30.0)), T(0, glm::vec2(90.0, 30.0)), T(0, glm::vec2(120.0, 30.0))},
	{T(0, glm::vec2(0.0, 60.0)), T(0, glm::vec2(30.0, 60.0)), T(1, glm::vec2(60.0, 60.0)), T(1, glm::vec2(90.0, 60.0)), T(0, glm::vec2(120.0, 60.0))},
	{T(0, glm::vec2(0.0, 90.0)), T(0, glm::vec2(30.0, 90.0)), T(1, glm::vec2(60.0, 90.0)), T(1, glm::vec2(90.0, 90.0)), T(0, glm::vec2(120.0, 90.0))},
	{T(0, glm::vec2(0.0, 120.0)), T(0, glm::vec2(30.0, 120.0)), T(0, glm::vec2(60.0, 120.0)), T(0, glm::vec2(90.0, 120.0)), T(0, glm::vec2(120.0, 120.0))}
};