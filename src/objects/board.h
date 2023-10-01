#include "../shared.h"

#include "piece.h"

class Board {
public:

	enum { BLOCK_EMPTY, BLOCK_FULL};

	int board[BOARD_WIDTH][BOARD_HEIGHT];

	Board();

	bool isEmptyBlock(int x, int y);
	bool isMove(int x, int y, int type, int rotation);

	void fillPiece(int x, int y, int type, int rotation);

	void deleteLines();

};