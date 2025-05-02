#include "snake.h"
#include <raylib.h>
#include <raymath.h>

Snake::Snake(int cellSize, Vector2 startPos)
    : cellSize(cellSize), shouldGrow(false) {
    body.push_back(startPos);
    direction = { (float)cellSize, 0 };
}

void Snake::ChangeDirection(Vector2 newDir) {
    if (!IsOppositeDirection(newDir)) {
        direction = newDir;
    }
}

bool Snake::IsOppositeDirection(Vector2 newDir) const {
    return Vector2DotProduct(direction, newDir) < 0;
}

void Snake::Move() {
    Vector2 newHead = body.front();
    newHead = Vector2Add(newHead, direction);
    body.insert(body.begin(), newHead);

    if (!shouldGrow) {
        body.pop_back();
    }
    else {
        shouldGrow = false;
    }
}

void Snake::Grow() {
    shouldGrow = true;
}

bool Snake::CheckSelfCollision() const {
    Vector2 head = body.front();
    for (auto it = body.begin() + 1; it != body.end(); ++it) {
        if (Vector2Equals(head, *it)) {
            return true;
        }
    }
    return false;
}

bool Snake::Vector2Equals(Vector2 a, Vector2 b) const {
    return a.x == b.x && a.y == b.y;
}

bool Snake::CheckWallCollision(int screenWidth, int screenHeight) const {
    Vector2 head = body.front();
    return head.x < 0 || head.x >= screenWidth ||
        head.y < 0 || head.y >= screenHeight;
}

bool Snake::CheckFoodCollision(Vector2 foodPos) const {
    return Vector2Equals(body.front(), foodPos);
}

void Snake::Draw() const {
    for (const auto& segment : body) {
        DrawRectangleV(segment, { (float)cellSize, (float)cellSize }, DARKGREEN);
        DrawRectangleLinesEx(
            { segment.x, segment.y, (float)cellSize, (float)cellSize },
            1,
            ColorAlpha(WHITE, 0.3f)
        );
    }
}

Vector2 Snake::GetHeadPosition() const {
    return body.front();
}