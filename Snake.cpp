#include "Snake.h"

const int CELL_SIZE = 30;

Snake::Snake()
{
    Reset();
}

void Snake::Reset()
{
    body.clear();

    body.push_back({10, 10});
    body.push_back({9, 10});
    body.push_back({8, 10});

    direction = {1, 0};
}

void Snake::Draw()
{
    for (size_t i = 0; i < body.size(); i++)
    {
        float x = body[i].x;
        float y = body[i].y;

        Rectangle segment =
        {
            x * CELL_SIZE,
            y * CELL_SIZE,
            CELL_SIZE - 2,
            CELL_SIZE - 2
        };

        if (i == 0)
        {
            DrawRectangleRounded(
                segment,
                0.3f,
                5,
                DARKGREEN
            );
        }
        else
        {
            DrawRectangleRounded(
                segment,
                0.3f,
                5,
                GREEN
            );
        }
    }
}

void Snake::Move()
{
    float headX = body.front().x;
    float headY = body.front().y;

    float directionX = direction.x;
    float directionY = direction.y;

    Vector2 newHead =
    {
        headX + directionX,
        headY + directionY
    };

    body.push_front(newHead);

    body.pop_back();
}

void Snake::Grow()
{
    float tailX = body.back().x;
    float tailY = body.back().y;

    Vector2 newTail =
    {
        tailX,
        tailY
    };

    body.push_back(newTail);
}

void Snake::SetDirection(Vector2 newDirection)
{
    direction = newDirection;
}

Vector2 Snake::GetHead()
{
    return body.front();
}

Vector2 Snake::GetDirection()
{
    return direction;
}

deque<Vector2> Snake::GetBody()
{
    return body;
}