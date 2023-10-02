#include "../shared.h"

#include "piece.h"

#include <vector>

class Board {
public:

	glm::vec2 boardPosMatrix[BOARD_WIDTH][BOARD_HEIGHT];
	std::vector<std::vector<int>> boardBlockMatrix;
	std::vector<int> lines;

	Board();
	~Board();

	bool isEmptyBlock(int x, int y);
	bool isMove(int x, int y, int type, int rotation);

	void fillPiece(int x, int y, int type, int rotation, Sprite& sprite, glm::vec3 color);

	void deleteLines();

};