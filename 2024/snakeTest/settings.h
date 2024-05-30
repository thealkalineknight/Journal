#pragma once
#include <iostream>
#include <raylib.h>
#include <deque>
using namespace std;


class Settings {
public:
	Vector2 position;
	Texture2D texture;
	Color darkGreen = Color{ 20, 160, 133, 255 };
	Color green = Color{ 43, 51, 24, 255 };
	Color aColor = Color{ 56, 45, 23, 67 };
	const int screenWidth = 800;
	const int screenHeight = 600;

	int cellSize = 30;
	int cellCount = 25;
	int test = 5;

	Settings();

	double prevTime;
	double currTime;
	bool EventTrigger(double interval);
};
