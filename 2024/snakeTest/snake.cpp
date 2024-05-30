#include "snake.h"

Snake::Snake() {
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
        body[0].x += direction.x;
        body[0].y += direction.y;
        for (int i = 1; i < body.size(); i++) {
            Vector2 currSeg = { body[i].x, body[i].y };
            body[i].x = body[0].x - i * direction.x;
            body[i].y = body[0].y - i * direction.y;
        }
    }
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
