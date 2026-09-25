#include <stdio.h>
#include <iostream>
#include <time.h>
#include <raylib.h>
#include "circle.hpp"
#include "globals.hpp"
#include "spring.hpp"

int main()
{
    srand(time(NULL));

    int numberOfPoints = 2000;

    Spring *points = new Spring[numberOfPoints];

    Circle circle = {0};
    float radius = 160;

    circle.radius = radius;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Spring Simulator");
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        
        Vector2 mouseCoord = GetMousePosition();
        
        circle.positionCenter.x = mouseCoord.x;
        circle.positionCenter.y = mouseCoord.y;
        
        for(int i = 0; i < numberOfPoints; ++i)
        {
            points[i].updateSpring();
        }

        circle.resolveConflict(points, numberOfPoints);

        

        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        DrawCircle(circle.positionCenter.x, circle.positionCenter.y, circle.radius, BLACK);

        for(int i = 0; i < numberOfPoints; ++i)
        {
            DrawCircle(points[i].position.x, points[i].position.y, 10, RED);
        }

        EndDrawing();
    }
    delete[] points;
    CloseWindow();
    return 0;
}