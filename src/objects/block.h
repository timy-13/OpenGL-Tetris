#ifndef BLOCK_H
#define BLOCK_H

#include "../shared.h"

#include "sprite.h"



class Block {
public:

	glm::vec2 pos;
	glm::vec2 size = glm::vec2(BLOCK_SIZE, BLOCK_SIZE);
	glm::vec3 color;

	Block();
	Block(glm::vec2 pos, glm::vec2 size, glm::vec3 color);
	~Block();

	void drawBlock(Sprite& sprite);

};

#endif