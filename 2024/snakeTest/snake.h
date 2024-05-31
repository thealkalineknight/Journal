#pragma once
#include <raylib.h>
#include "settings.h"
#include "food.h"

class Snake {
public:
	Settings st;
	Food fd;

	deque<Vector2> body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
	Vector2 direction = { 1, 0 };
	Vector2 currSeg;

	bool addSegment;

	Snake();
	~Snake();

	void Update();
	void Draw();
	void Move();
	void Consume();
	void Death();

private:
	//
};