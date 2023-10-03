#include "game.h"
#include "shared.h"

#include "objects/sprite.h"
#include "objects/block.h"
#include "objects/piece.h"
#include "objects/board.h"

Sprite* sprite;
Piece* piece;
Board* board;

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

glm::vec3 pieceColors[7] = {
    glm::vec3()
};

Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete sprite;
    delete piece;
    delete board;
}

void Game::Init() {
    Shader shader;
    shader.compile("src/shaders/tetris.vs", "src/shaders/tetris.fs");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    shader.use();
    shader.SetMatrix4("projection", projection);
    sprite = new Sprite(shader);

    piece = new Piece(posMatrix, glm::vec3(1.0f, 0.0f, 0.0f));

    board = new Board();

}

void Game::Update(float dt) {
    int x = (static_cast<int>(piece->firstPos.x)) / 30;
    int y = (static_cast<int>(piece->firstPos.y)) / 30;

    if (board->isMove(x, y + 1, piece->type, piece->rotation) == true) { // can piece move down
        piece->moveDown();
    }
    else {
        board->fillPiece(x, y, piece->type, piece->rotation, *sprite, glm::vec3(0.0f, 1.0f, 0.0f));
        // board->deleteLines();
        respawnPiece();
    }
    

}


void Game::ProcessInput(float dt) {
    if (this->State == GAME_ACTIVE) {
        int x = (piece->firstPos.x) / 30;
        int y = (piece->firstPos.y) / 30;
        int type = piece->type;
        int rotation = piece->rotation;

        // horizontal movement
        if (piece->left == false && this->Keys[GLFW_KEY_LEFT] && board->isMove(x - 1, y, type, rotation)) {
            piece->moveLeft();
            piece->left = true;
            piece->right = false;
        }
        if (piece->right == false && this->Keys[GLFW_KEY_RIGHT] && board->isMove(x + 1, y, type, rotation)) {
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
        piece->drawPiece(piece->posMatrix, piece->type, *sprite, glm::vec3(1.0, 0.0, 0.0));
        board->drawBoard(*sprite);
    }
}

void Game::Reset() {

}


void Game::respawnPiece() {
    int randType = (rand() % 7);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            piece->posMatrix[i][j] = posMatrix[i][j];
        }
    }

    piece->getPiece(randType);
    piece->type = randType;
    piece->rotation = 0;
}