#include <raylib.h>
#include "settings.h"
#include "food.h"
#include <iostream>
using namespace std;


int main() {
    Settings st;
    InitWindow(st.cellSize * st.cellCount, st.cellSize * st.cellCount, "I like turtles");
    SetTargetFPS(60);
    
    Food food;

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(st.darkGreen);
        food.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}



// Food food = Food(); old way must init
