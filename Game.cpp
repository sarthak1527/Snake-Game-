#include "Game.h"

const int GRID_SIZE = 20;

Game::Game()
    : snake(),
      food(snake.GetBody())
{
    InitAudioDevice();

    eatSound = LoadSound("Sounds/eat.mp3");
    gameOverSound = LoadSound("Sounds/gameover.mp3");

    gameOver = false;
    score = 0;
}

Game::~Game()
{
    UnloadSound(eatSound);
    UnloadSound(gameOverSound);

    CloseAudioDevice();
}

void Game::HandleInput()
{
    if (gameOver)
    {
        return;
    }

    Vector2 direction = snake.GetDirection();

    float directionX = direction.x;
    float directionY = direction.y;

    if (IsKeyPressed(KEY_UP))
    {
        if (directionY != 1)
        {
            snake.SetDirection({0, -1});
        }
    }

    if (IsKeyPressed(KEY_DOWN))
    {
        if (directionY != -1)
        {
            snake.SetDirection({0, 1});
        }
    }

    if (IsKeyPressed(KEY_LEFT))
    {
        if (directionX != 1)
        {
            snake.SetDirection({-1, 0});
        }
    }

    if (IsKeyPressed(KEY_RIGHT))
    {
        if (directionX != -1)
        {
            snake.SetDirection({1, 0});
        }
    }
}

void Game::Update()
{
    if (gameOver)
    {
        return;
    }

    snake.Move();

    CheckFoodCollision();
    CheckWallCollision();
    CheckTailCollision();
}

void Game::CheckFoodCollision()
{
    Vector2 head = snake.GetHead();
    Vector2 foodPosition = food.GetPosition();

    float headX = head.x;
    float headY = head.y;

    float foodX = foodPosition.x;
    float foodY = foodPosition.y;

    if (headX == foodX &&
        headY == foodY)
    {
        score++;

        snake.Grow();

        food.Respawn(snake.GetBody());

        PlaySound(eatSound);
    }
}

void Game::CheckWallCollision()
{
    Vector2 head = snake.GetHead();

    float headX = head.x;
    float headY = head.y;

    if (headX < 0 ||
        headX >= GRID_SIZE ||
        headY < 0 ||
        headY >= GRID_SIZE)
    {
        GameOver();
    }
}

void Game::CheckTailCollision()
{
    Vector2 head = snake.GetHead();

    float headX = head.x;
    float headY = head.y;

    deque<Vector2> body = snake.GetBody();

    for (size_t i = 1; i < body.size(); i++)
    {
        float bodyX = body[i].x;
        float bodyY = body[i].y;

        if (headX == bodyX &&
            headY == bodyY)
        {
            GameOver();
            return;
        }
    }
}

void Game::GameOver()
{
    gameOver = true;

    PlaySound(gameOverSound);
}

void Game::Reset()
{
    snake.Reset();

    food.Respawn(snake.GetBody());

    score = 0;

    gameOver = false;
}

bool Game::IsGameOver()
{
    return gameOver;
}

int Game::GetScore()
{
    return score;
}

void Game::Draw()
{
    food.Draw();
    snake.Draw();
}