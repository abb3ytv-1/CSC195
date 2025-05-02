#include "resource_dir.h"
#include <raylib.h>
#include "snake.h"
#include "food.h"

int main() {
    // Game settings
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int cellSize = 20;
    int score = 0;
    bool gameOver = false;
    float moveInterval = 0.15f;
    float lastMoveTime = 0;

    // Initialize window
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetTargetFPS(60);
    SearchAndSetResourceDir("resources");

    // Initialize game objects
    Snake snake(cellSize, { screenWidth / 2.0f, screenHeight / 2.0f });
    Food food(cellSize, screenWidth, screenHeight);

    // Main game loop
    while (!WindowShouldClose()) {
        // Handle input
        if (IsKeyPressed(KEY_UP)) snake.ChangeDirection({ 0, -cellSize });
        if (IsKeyPressed(KEY_DOWN)) snake.ChangeDirection({ 0, cellSize });
        if (IsKeyPressed(KEY_LEFT)) snake.ChangeDirection({ -cellSize, 0 });
        if (IsKeyPressed(KEY_RIGHT)) snake.ChangeDirection({ cellSize, 0 });

        if (gameOver && IsKeyPressed(KEY_SPACE)) {
            // Reset game
            snake = Snake(cellSize, { screenWidth / 2.0f, screenHeight / 2.0f });
            food.Respawn();
            score = 0;
            gameOver = false;
        }

        // Update game state
        if (!gameOver) {
            float currentTime = GetTime();
            if (currentTime - lastMoveTime >= moveInterval) {
                snake.Move();
                lastMoveTime = currentTime;

                if (snake.CheckFoodCollision(food.GetPosition())) {
                    snake.Grow();
                    food.Respawn();
                    score++;
                }

                gameOver = snake.CheckSelfCollision() ||
                    snake.CheckWallCollision(screenWidth, screenHeight);
            }
        }

        // Draw frame
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw grid
        const Color gridColor = ColorAlpha(GRAY, 0.3f);
        const float lineThickness = 1.5f;

        for (int x = 0; x < screenWidth; x += cellSize) {
            DrawLineEx(
                { (float)x, 0 },
                { (float)x, (float)screenHeight },
                lineThickness,
                gridColor
            );
        }

        for (int y = 0; y < screenHeight; y += cellSize) {
            DrawLineEx(
                { 0, (float)y },
                { (float)screenWidth, (float)y },
                lineThickness,
                gridColor
            );
        }

        snake.Draw();
        food.Draw();

        // Draw UI
        DrawText(TextFormat("Score: %d", score), 10, 10, 20, DARKGRAY);
        if (gameOver) {
            DrawText("GAME OVER!", screenWidth / 2 - 80, screenHeight / 2 - 20, 40, RED);
            DrawText("Press SPACE to restart", screenWidth / 2 - 120, screenHeight / 2 + 30, 20, DARKGRAY);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}