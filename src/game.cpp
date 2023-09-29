#include "game.h"
#include "shared.h"

#include "objects/sprite.h"
#include "objects/block.h"
#include "objects/piece.h"

Sprite* sprite;
Block* block;
Piece* piece;

//T Square[5][5] = {
//        {T(0, glm::vec2(0.0, 0.0)), T(0, glm::vec2(30.0, 0.0)), T(0, glm::vec2(60.0, 0.0)), T(0, glm::vec2(90.0, 0.0)), T(0, glm::vec2(120.0, 0.0))},
//        {T(0, glm::vec2(0.0, 30.0)), T(0, glm::vec2(30.0, 30.0)), T(0, glm::vec2(60.0, 30.0)), T(0, glm::vec2(90.0, 30.0)), T(0, glm::vec2(120.0, 30.0))},
//        {T(0, glm::vec2(0.0, 60.0)), T(0, glm::vec2(30.0, 60.0)), T(1, glm::vec2(60.0, 60.0)), T(1, glm::vec2(90.0, 60.0)), T(0, glm::vec2(120.0, 60.0))},
//        {T(0, glm::vec2(0.0, 90.0)), T(0, glm::vec2(30.0, 90.0)), T(1, glm::vec2(60.0, 90.0)), T(1, glm::vec2(90.0, 90.0)), T(0, glm::vec2(120.0, 90.0))},
//        {T(0, glm::vec2(0.0, 120.0)), T(0, glm::vec2(30.0, 120.0)), T(0, glm::vec2(60.0, 120.0)), T(0, glm::vec2(90.0, 120.0)), T(0, glm::vec2(120.0, 120.0))}
//};
//
//T L[5][5] = {
//        {T(0, glm::vec2(0.0, 0.0)), T(0, glm::vec2(30.0, 0.0)), T(0, glm::vec2(60.0, 0.0)), T(0, glm::vec2(90.0, 0.0)), T(0, glm::vec2(120.0, 0.0))},
//        {T(0, glm::vec2(0.0, 30.0)), T(0, glm::vec2(30.0, 30.0)), T(1, glm::vec2(60.0, 30.0)), T(0, glm::vec2(90.0, 30.0)), T(0, glm::vec2(120.0, 30.0))},
//        {T(0, glm::vec2(0.0, 60.0)), T(0, glm::vec2(30.0, 60.0)), T(1, glm::vec2(60.0, 60.0)), T(0, glm::vec2(90.0, 60.0)), T(0, glm::vec2(120.0, 60.0))},
//        {T(0, glm::vec2(0.0, 90.0)), T(0, glm::vec2(30.0, 90.0)), T(1, glm::vec2(60.0, 90.0)), T(1, glm::vec2(90.0, 90.0)), T(0, glm::vec2(120.0, 90.0))},
//        {T(0, glm::vec2(0.0, 120.0)), T(0, glm::vec2(30.0, 120.0)), T(0, glm::vec2(60.0, 120.0)), T(0, glm::vec2(90.0, 120.0)), T(0, glm::vec2(120.0, 120.0))}
//};

// initial posMatrix
glm::vec2 posMatrix[5][5] = {
        {glm::vec2(0.0, 0.0), glm::vec2(30.0, 0.0), glm::vec2(60.0, 0.0), glm::vec2(90.0, 0.0), glm::vec2(120.0, 0.0)},
        {glm::vec2(0.0, 30.0), glm::vec2(30.0, 30.0), glm::vec2(60.0, 30.0), glm::vec2(90.0, 30.0), glm::vec2(120.0, 30.0)},
        {glm::vec2(0.0, 60.0), glm::vec2(30.0, 60.0), glm::vec2(60.0, 60.0), glm::vec2(90.0, 60.0), glm::vec2(120.0, 60.0)},
        {glm::vec2(0.0, 90.0), glm::vec2(30.0, 90.0), glm::vec2(60.0, 90.0), glm::vec2(90.0, 90.0), glm::vec2(120.0, 90.0)},
        {glm::vec2(0.0, 120.0), glm::vec2(30.0, 120.0), glm::vec2(60.0, 120.0), glm::vec2(90.0, 120.0), glm::vec2(120.0, 120.0)}
};


Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete sprite;
    delete block;
    delete piece;
}

void Game::Init() {
    Shader shader;
    shader.compile("src/shaders/tetris.vs", "src/shaders/tetris.fs");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    shader.use();
    shader.SetMatrix4("projection", projection);
    sprite = new Sprite(shader);

    block = new Block(glm::vec2(60.0f, 210.0f), glm::vec2(BLOCK_SIZE, BLOCK_SIZE), glm::vec3(0.0f, 0.0f, 1.0f));

    piece = new Piece(posMatrix, glm::vec3(1.0f, 0.0f, 0.0f));

}

void Game::Update(float dt) {
    
}


void Game::ProcessInput(float dt) {
    if (this->State == GAME_ACTIVE) {

        // horizontal movement
        if (piece->left == false && this->Keys[GLFW_KEY_LEFT]) {
            piece->moveLeft();
            piece->left = true;
            piece->right = false;
        }
        if (piece->right == false && this->Keys[GLFW_KEY_RIGHT]) {
            piece->moveRight();
            piece->right = true;
            piece->left = false;
        }

        if (!(this->Keys[GLFW_KEY_LEFT]) && !(this->Keys[GLFW_KEY_RIGHT])) {
            piece->left = false;
            piece->right = false;
        }

        // rotation
        if (piece->rotated == false && this->Keys[GLFW_KEY_UP]) {
            piece->rotatePiece();
            piece->rotated = true;
        }

        if (!(this->Keys[GLFW_KEY_UP])) {
            piece->rotated = false;
        }
        

    }
}

void Game::Render() {
    if (this->State == GAME_ACTIVE) {
        block->drawBlock(*sprite);
        piece->drawPiece(piece->posMatrix, 0, *sprite, glm::vec3(1.0, 0.0, 0.0));
    }
}

void Game::Reset() {

}