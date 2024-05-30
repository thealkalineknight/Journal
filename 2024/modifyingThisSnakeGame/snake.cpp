#include "snake.h"

Snake::Snake() {
    Vector2 direction = { 1, 0 };
    bool addSegment = false;
    // assign things to do here, like var = func(), not var = 0 ; watch out above
}

Snake::~Snake() {
}

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

    if (st.EventTrigger(0.05)) {
        for (int i = 0; i < body.size(); i++) {
            //if (st.EventTrigger(0.05)) {
            body[i].x += direction.x;
            body[i].y += direction.y;
            //}
        }
    }

    // problem: keydown seems to be not responsive all the time : cant go in opposite direction = fine, but why?
}

void Snake::Death() {
    body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
    direction = { 1, 0 };
}

// timer func for all use
// move
// pop
// consume
// die
// score
