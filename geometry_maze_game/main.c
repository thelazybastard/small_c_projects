#include "lib/raylib.h"
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    const int SPEED = 5.0;

    InitWindow(screenWidth, screenHeight, "Geometry Maze Game");

    InitAudioDevice();

    Music music = LoadMusicStream("geometry_game.wav");

    PlayMusicStream(music);

    float timePlayed = 0.0f;

    int num = 0;

    Vector2 ballPosition = {
        (float) screenWidth / 2,
        (float) screenHeight / 2,
    };

    Vector2 collectable0 = {
        (float) 100,
        (float) 100,
    };

    Vector2 collectable1 = {
        (float) 150,
        (float) 150,
    };

    Vector2 collectable2 = {
        (float) 200,
        (float) 150,
    };

    Vector2 collectable3 = {
        (float) 400,
        (float) 400,
    };

    Vector2 collectable4 = {
        (float) 600,
        (float) 600,
    };
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += SPEED;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= SPEED;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= SPEED;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += SPEED;

        UpdateMusicStream(music);

        timePlayed = GetMusicTimePlayed(music) / GetMusicTimePlayed(music);
        if (timePlayed > 1.0f) timePlayed = 1.0f;

        if (CheckCollisionCircles(ballPosition, 50, collectable0, 50)) {
            collectable0.x = 0;
            collectable0.y = 0;
            num++;
        }
        if (CheckCollisionCircles(ballPosition, 50, collectable1, 50)) {
            collectable1.x = 0;
            collectable1.y = 0;
            num++;
        }
        if (CheckCollisionCircles(ballPosition, 50, collectable2, 50)) {
            collectable2.x = 0;
            collectable2.y = 0;
            num++;
        }
        if (CheckCollisionCircles(ballPosition, 50, collectable3, 50)) {
            collectable3.x = 0;
            collectable3.y = 0;
            num++;
        }
        if (CheckCollisionCircles(ballPosition, 50, collectable4, 50)) {
            collectable4.x = 0;
            collectable4.y = 0;
            num++;
        }      
        

        BeginDrawing();

            if (num == 5) {
                DrawText("YOU WIN!!!", screenWidth / 2, screenHeight / 2, 50, BLACK);
            }

            DrawText(TextFormat("%i", num), screenWidth - 20,10, 20, BLACK);
            
            DrawCircleV(collectable0, 50, BLUE);

            DrawCircleV(collectable1, 50, BLUE);

            DrawCircleV(collectable2, 50, BLUE);

            DrawCircleV(collectable3, 50, BLUE);

            DrawCircleV(collectable4, 50, BLUE);


            ClearBackground(RAYWHITE);

            DrawCircleV(ballPosition, 50, BLUE);
            

        EndDrawing();
    }

    CloseWindow();
    
    return EXIT_SUCCESS;
}
