#ifndef FOOD_H
#define FOOD_H

#include "raylib.h"
#include <deque>

using namespace std;

class Food
{
private:
    Vector2 position;
    Texture2D texture;

    Vector2 GenerateRandomPosition(deque<Vector2> snakeBody);

public:
    Food(deque<Vector2> snakeBody);
    ~Food();

    void Draw();

    void Respawn(deque<Vector2> snakeBody);

    Vector2 GetPosition();
};

#endif