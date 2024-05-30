#pragma once
#include <raylib.h>
#include "settings.h"

class Snake {
public:
	Settings st;
	Vector2 position;

	deque<Vector2> body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
	Vector2 direction = { 1, 0 };

	bool addSegment;

	Snake();
	~Snake();

	void Update();
	void Draw();
	void Move();
	void Death();

private:
	//
};
