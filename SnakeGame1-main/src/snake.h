#pragma once
#include <raylib.h>
#include <vector>
#include <stdexcept> 

class Snake {
private:
    std::vector<Vector2> body;
    Vector2 direction;
    int cellSize;
    bool shouldGrow;

    bool IsOppositeDirection(Vector2 newDir) const;
    bool Vector2Equals(Vector2 a, Vector2 b) const;

public:
    Snake(int cellSize, Vector2 startPos);
    void ChangeDirection(Vector2 newDir);
    void Move();
    void Grow();
    bool CheckSelfCollision() const;
    bool CheckWallCollision(int screenWidth, int screenHeight) const;
    bool CheckFoodCollision(Vector2 foodPos) const;
    void Draw() const;

    Vector2 GetHeadPosition() const;
    int GetCellSize() const { return cellSize; }
    size_t GetLength() const { return body.size(); }
};