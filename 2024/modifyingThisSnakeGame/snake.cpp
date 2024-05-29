#include "snake.h"

Snake::Snake() {
    Vector2 direction = { 1, 0 };
    bool addSegment = false;
}

Snake::~Snake() {
}
// https://github.com/educ8s/Cpp-Retro-Snake-Game-with-raylib/blob/main/main.cpp
void Snake::Update() {
    Move();
    Draw();  // evemt of death?
}

void Snake::Draw() {
    for (int i = 0; i < body.size(); i++) {
        int x = body[i].x;
        int y = body[i].y;
        DrawRectangle(x * st.cellSize, y * st.cellSize, st.cellSize, st.cellSize, st.aColor);
    }
}

void Snake::Move() {
    if (IsKeyPressed(KEY_LEFT) && direction.x != 1) {
        direction = { -1, 0 };
    }
    if (IsKeyPressed(KEY_RIGHT) && direction.x != -1) {
        direction = { 1, 0 };
    }
    if (IsKeyPressed(KEY_UP) && direction.y != 1) {
       direction = { 0, -1 };
    }
    if (IsKeyPressed(KEY_DOWN) && direction.y != -1) {
        direction = { 0, 1 };
    }
}

void Snake::Death() {
    body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
    direction = { 1, 0 };
}


// move
// popf
// consume
// die
// score
