#ifndef PIECE_H
#define PIECE_H

#include "../shared.h"

#include "block.h"

#include <utility>

// matrix for positions of blocks
//typedef std::pair<int, glm::vec2> T;

class Piece {
public:

	glm::vec2 firstPos;
	glm::vec2 posMatrix[5][5];
	glm::vec3 color;

	bool left;
	bool right;
	bool rotated;
	int rotation;
	int type;

	Piece();
	Piece(glm::vec2 posMatrix[5][5], glm::vec3 color);
	~Piece();

	void drawPiece(glm::vec2 posMatrix[5][5], int type, Sprite &sprite, glm::vec3 color);

	void moveLeft();

	void moveRight();

	void moveDown();

	void rotatePiece();

	// int** getPiece(int type, int rotation);

	// pieces
	/*T Square[5][5] = {
		{T(0, glm::vec2(0.0, 0.0)), T(0, glm::vec2(30.0, 0.0)), T(0, glm::vec2(60.0, 0.0)), T(0, glm::vec2(90.0, 0.0)), T(0, glm::vec2(120.0, 0.0))},
		{T(0, glm::vec2(0.0, 30.0)), T(0, glm::vec2(30.0, 30.0)), T(0, glm::vec2(60.0, 30.0)), T(0, glm::vec2(90.0, 30.0)), T(0, glm::vec2(120.0, 30.0))},
		{T(0, glm::vec2(0.0, 60.0)), T(0, glm::vec2(30.0, 60.0)), T(1, glm::vec2(60.0, 60.0)), T(1, glm::vec2(90.0, 60.0)), T(0, glm::vec2(120.0, 60.0))},
		{T(0, glm::vec2(0.0, 90.0)), T(0, glm::vec2(30.0, 90.0)), T(1, glm::vec2(60.0, 90.0)), T(1, glm::vec2(90.0, 90.0)), T(0, glm::vec2(120.0, 90.0))},
		{T(0, glm::vec2(0.0, 120.0)), T(0, glm::vec2(30.0, 120.0)), T(0, glm::vec2(60.0, 120.0)), T(0, glm::vec2(90.0, 120.0)), T(0, glm::vec2(120.0, 120.0))}
	};

	T L[5][5] = {
		{T(0, glm::vec2(0.0, 0.0)), T(0, glm::vec2(30.0, 0.0)), T(0, glm::vec2(60.0, 0.0)), T(0, glm::vec2(90.0, 0.0)), T(0, glm::vec2(120.0, 0.0))},
		{T(0, glm::vec2(0.0, 30.0)), T(0, glm::vec2(30.0, 30.0)), T(1, glm::vec2(60.0, 30.0)), T(0, glm::vec2(90.0, 30.0)), T(0, glm::vec2(120.0, 30.0))},
		{T(0, glm::vec2(0.0, 60.0)), T(0, glm::vec2(30.0, 60.0)), T(1, glm::vec2(60.0, 60.0)), T(0, glm::vec2(90.0, 60.0)), T(0, glm::vec2(120.0, 60.0))},
		{T(0, glm::vec2(0.0, 90.0)), T(0, glm::vec2(30.0, 90.0)), T(1, glm::vec2(60.0, 90.0)), T(1, glm::vec2(90.0, 90.0)), T(0, glm::vec2(120.0, 90.0))},
		{T(0, glm::vec2(0.0, 120.0)), T(0, glm::vec2(30.0, 120.0)), T(0, glm::vec2(60.0, 120.0)), T(0, glm::vec2(90.0, 120.0)), T(0, glm::vec2(120.0, 120.0))}
	};*/

};


#endif
