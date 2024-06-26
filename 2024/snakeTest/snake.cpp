#include "snake.h"

Snake::Snake() {
    bool addSegment = false;
    // assign things to do here, like var = func(), not var = 0 ; watch out above
}

Snake::~Snake() {
}

void Snake::Update() {
    Draw();
    Move();
    Logic();
    Consume();
    Death();
}

void Snake::Draw() {
    for (int i = 0; i < body.size(); i++) {
        int x = body[i].x;
        int y = body[i].y;
        DrawRectangle(x * st.cellSize, y * st.cellSize, st.cellSize, st.cellSize, st.aColor);
    }
    DrawRectangle(fd.position.x * st.cellSize, fd.position.y * st.cellSize, st.cellSize, st.cellSize, st.green);
}

void Snake::Move() {
    if (IsKeyPressed(KEY_LEFT) && direction.x != 1) direction = { -1, 0 };
    if (IsKeyPressed(KEY_RIGHT) && direction.x != -1) direction = { 1, 0 };
    if (IsKeyPressed(KEY_UP) && direction.y != 1) direction = { 0, -1 };
    if (IsKeyPressed(KEY_DOWN) && direction.y != -1) direction = { 0, 1 };
}

void Snake::Logic() {
    if (st.EventTrigger(0.5)) {
        currSeg = { body[0].x, body[0].y };
        body[0].x += direction.x;
        body[0].y += direction.y;
        for (int i = 1; i < body.size(); i++) {
            Vector2 tempSeg = { body[i].x, body[i].y };
            body[i].x = currSeg.x;
            body[i].y = currSeg.y;

            currSeg = { tempSeg.x, tempSeg.y };
        }
        if (addSegment) {
            body.push_back(currSeg);
            fd.position = fd.GenerateRandomCell();
            addSegment = false;
        }
    }
}

bool Snake::Collide() {
    for (int i = 1; i < body.size(); i++) {
        if (body[0].x == body[i].x && body[0].y == body[i].y) return true;
    }
    if (body[0].x <= -1 || body[0].x >= st.cellCount) return true;
    if (body[0].y <= -1 || body[0].y >= st.cellCount) return true;

    return false;
}

void Snake::Consume() {
    if (body[0].x == fd.position.x && body[0].y == fd.position.y) {
        addSegment = true;
    }
}

void Snake::Death() {
    if (Collide()) {
        body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
        direction = { 1, 0 };
    }
}

