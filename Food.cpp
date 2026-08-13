#include "Food.h"

const int CELL_SIZE = 30;
const int GRID_SIZE = 20;

Food::Food(deque<Vector2> snakeBody)
{
    Image image = LoadImage("Graphics/food.jpg");

    texture = LoadTextureFromImage(image);

    UnloadImage(image);

    position = GenerateRandomPosition(snakeBody);
}

Food::~Food()
{
    UnloadTexture(texture);
}

Vector2 Food::GenerateRandomPosition(deque<Vector2> snakeBody)
{
    Vector2 newPosition;

    bool valid = false;

    while (!valid)
    {
        int randomX = GetRandomValue(0, GRID_SIZE - 1);
        int randomY = GetRandomValue(0, GRID_SIZE - 1);

        newPosition.x = randomX;
        newPosition.y = randomY;

        valid = true;

        for (auto part : snakeBody)
        {
            float foodX = newPosition.x;
            float foodY = newPosition.y;

            float snakeX = part.x;
            float snakeY = part.y;

            if (foodX == snakeX &&
                foodY == snakeY)
            {
                valid = false;
                break;
            }
        }
    }

    return newPosition;
}

void Food::Respawn(deque<Vector2> snakeBody)
{
    position = GenerateRandomPosition(snakeBody);
}

Vector2 Food::GetPosition()
{
    return position;
}

void Food::Draw()
{
    float x = position.x * CELL_SIZE;
    float y = position.y * CELL_SIZE;

    Rectangle source =
    {
        0,
        0,
        (float)texture.width,
        (float)texture.height
    };

    Rectangle destination =
    {
        x,
        y,
        CELL_SIZE,
        CELL_SIZE
    };

    DrawTexturePro(
        texture,
        source,
        destination,
        {0, 0},
        0,
        WHITE
    );
}