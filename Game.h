#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "Snake.h"
#include "Food.h"

class Game
{
private:
    Snake snake;
    Food food;

    Sound eatSound;
    Sound gameOverSound;

    bool gameOver;
    int score;

public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Draw();

    void CheckFoodCollision();
    void CheckWallCollision();
    void CheckTailCollision();

    void GameOver();
    void Reset();

    bool IsGameOver();
    int GetScore();
};

#endif