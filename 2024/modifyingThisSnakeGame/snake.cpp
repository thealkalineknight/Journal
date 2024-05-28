#include "snake.h"

Snake::Snake() {
    deque<Vector2> body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
    Vector2 direction = { 1, 0 };
    bool addSegment = false;
}

Snake::~Snake() {
}

void Snake::Draw() {
}

void Snake::Death() {
    body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
    direction = { 1, 0 };
}


// move
// pop
// consume
// die
// score
