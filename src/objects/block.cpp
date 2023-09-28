#include "block.h"

Block::Block() : pos(), size(), color(0.0f, 0.0f, 1.0f) {

}

Block::Block(glm::vec2 pos, glm::vec2 size, glm::vec3 color) : pos(pos), size(size), color(color)
{

}

Block::~Block() {

}

void Block::drawBlock(Sprite& sprite) {
	sprite.drawSprite(this->pos, this->size, 0.0f, this->color);
}