#ifndef GAME_H
#define GAME_H

#include "shared.h"

#include "objects/piece.h"

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

class Game {
public:
    GameState    State;
    bool         Keys[1024];
    unsigned int Width, Height;

    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();

    // initialize game state (load all shaders/textures/levels)
    void Init();

    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
    void Reset();

    void respawnPiece();
};

#endif