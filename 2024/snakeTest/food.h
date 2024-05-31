#pragma once
#include "settings.h"

class Food {
public:
	Settings st;
	Vector2 position;
	Texture2D texture;

	Food();
	~Food();

	void Draw();
	Vector2 GenerateRandomCell();

private:
	//
};