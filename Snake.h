#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"
#include <deque>

using namespace std;

class Snake
{
private:
    deque<Vector2> body;
    Vector2 direction;

public:
    Snake();

    void Draw();
    void Move();
    void Grow();
    void Reset();

    void SetDirection(Vector2 newDirection);

    Vector2 GetHead();
    Vector2 GetDirection();

    deque<Vector2> GetBody();
};

#endif