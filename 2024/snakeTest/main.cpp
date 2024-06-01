#include "snake.h"
#include <iostream>
using namespace std;


int main() {
    Settings st;
    InitWindow(st.cellSize * st.cellCount, st.cellSize * st.cellCount, "I like turtles");
    SetTargetFPS(60);
    
    Food food;
    Snake snake;

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(st.darkGreen);
        //food.Draw();
        snake.Update();

        EndDrawing();
    }

    // update method for entire game, for individual update methods in one place

    CloseWindow();
    return 0;
}



// Food food = Food(); old way must init