#include "raylib.h"
#include "Game.h"

const int CELL_SIZE = 30;
const int GRID_SIZE = 20;

const int SCREEN_WIDTH = CELL_SIZE * GRID_SIZE;
const int SCREEN_HEIGHT = CELL_SIZE * GRID_SIZE;

const float MOVE_INTERVAL = 0.15f;

int main()
{
    // Create window
    InitWindow(
        SCREEN_WIDTH,
        SCREEN_HEIGHT + 70,
        "C++ Snake Game"
    );

    SetTargetFPS(60);

    // Create game
    Game game;

    float timer = 0.0f;

    while (!WindowShouldClose())
    {
        // -------------------------
        // INPUT
        // -------------------------

        game.HandleInput();

        if (game.IsGameOver() &&
            IsKeyPressed(KEY_ENTER))
        {
            game.Reset();
            timer = 0;
        }

        // -------------------------
        // UPDATE
        // -------------------------

        timer += GetFrameTime();

        if (timer >= MOVE_INTERVAL)
        {
            timer = 0;

            game.Update();
        }

        // -------------------------
        // DRAW
        // -------------------------

        BeginDrawing();

        ClearBackground(
            Color{190, 220, 150, 255}
        );

        // Draw grid
        for (int x = 0; x <= GRID_SIZE; x++)
        {
            DrawLine(
                x * CELL_SIZE,
                0,
                x * CELL_SIZE,
                SCREEN_HEIGHT,
                Color{170, 200, 130, 255}
            );
        }

        for (int y = 0; y <= GRID_SIZE; y++)
        {
            DrawLine(
                0,
                y * CELL_SIZE,
                SCREEN_WIDTH,
                y * CELL_SIZE,
                Color{170, 200, 130, 255}
            );
        }

        // Draw game
        game.Draw();

        // Bottom bar
        DrawRectangle(
            0,
            SCREEN_HEIGHT,
            SCREEN_WIDTH,
            70,
            DARKGREEN
        );

        // Score
        DrawText(
            TextFormat(
                "Score: %d",
                game.GetScore()
            ),
            20,
            SCREEN_HEIGHT + 20,
            25,
            WHITE
        );

        // Game over
        if (game.IsGameOver())
        {
            DrawRectangle(
                0,
                0,
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                Fade(BLACK, 0.4f)
            );

            DrawText(
                "GAME OVER",
                SCREEN_WIDTH / 2 - 110,
                SCREEN_HEIGHT / 2 - 40,
                40,
                RED
            );

            DrawText(
                "Press ENTER to restart",
                SCREEN_WIDTH / 2 - 120,
                SCREEN_HEIGHT / 2 + 20,
                20,
                WHITE
            );
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}