#ifndef PIECE_H
#define PIECE_H

#include "../shared.h"

#include "block.h"

#include <utility>

// matrix for positions of blocks
typedef std::pair<int, glm::vec2> T;

class Piece {
public:

	glm::vec2 centerPos;
	T blockMatrix[5][5];
	glm::vec3 color;

	bool left;
	bool right;
	bool rotate;

	Piece();
	Piece(T blockMatrix[5][5], glm::vec3 color);
	~Piece();

	void drawPiece(T blockMatrix[5][5], Sprite &sprite, glm::vec3 color);

	void moveLeft();

	void moveRight();

	void moveDown();

	T getPiece(std::string pieceName, int rotation);
};


#endif




