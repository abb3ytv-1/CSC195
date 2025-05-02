#pragma once
#include <raylib.h>

class Food {
private:
    Vector2 position;
    int cellSize;
    int screenWidth;
    int screenHeight;

public:
    Food(int cellSize, int screenWidth, int screenHeight);
    void Respawn();
    Vector2 GetPosition() const;
    void Draw() const;
};