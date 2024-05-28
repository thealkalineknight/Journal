#pragma once
#include <raylib.h>
#include "settings.h"

class Snake {
public:
	Settings st;
	Vector2 position;

	deque<Vector2> body;
	Vector2 direction;
	bool addSegment;

	Snake();
	~Snake();

	void Draw();
	void Death();

private:
	//
};
