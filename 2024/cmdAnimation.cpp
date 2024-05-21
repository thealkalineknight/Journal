#include <Windows.h>
#include <iostream>
#include <cstdio>
#include <chrono>
#include <vector>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
vector<int> xbox;
vector<int> ybox;
vector<vector<int>> cormap;
bool mapInited = false;
bool moveCan = true;


void gotoxy(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void mazeInit2(int x, int y) {
	vector<int> temp;
	temp.push_back(x);
	temp.push_back(y);
	cormap.push_back(temp);
}

void mazeInit() {
	ybox.push_back(0);
	ybox.push_back(20);
	for (int i = 1; i < 20; i++) {
		ybox.push_back(i);
	}
	xbox.push_back(0);
	for (int i = 1; i < 40; i++) {
		xbox.push_back(i);
	}
}

void maze() {
	gotoxy(0, 0); cout << "________________________________________";
	gotoxy(0, 20); cout << "----------------------------------------";
	for (int i = 1; i < 20; i++) {
		gotoxy(0, i); cout << "|";
		gotoxy(39, i); cout << "|";

		if (mapInited == false) {
			mazeInit2(0, 0);
			mazeInit2(0, 20);
			mazeInit2(0, i);
			mazeInit2(39, i);
		}
	}
	mapInited = true;
}

int main() {
	CONSOLE_CURSOR_INFO ci;
	GetConsoleCursorInfo(console, &ci);	//get the old settings
	ci.bVisible = 0;				//changing them
	SetConsoleTextAttribute(console, 0x0C);
	SetConsoleCursorInfo(console, &ci);

	// mazeInit();
	int sx = 1;
	int sy = 1;

	auto start = chrono::high_resolution_clock::now();

	while (true)
	{
		system("cls"); //clear the screen

		auto stop = chrono::high_resolution_clock::now();
		float deltaTime = (chrono::duration_cast<chrono::microseconds>(stop - start)).count() / 1'000'000.0f;
		start = stop;

		static float counter = 0.1; // seconds
		counter -= deltaTime;
		if (counter <= 0)
		{
			if (GetAsyncKeyState('A')) sx -= 1;
			if (GetAsyncKeyState('D')) sx += 1;
			if (GetAsyncKeyState('W')) sy -= 1;
			if (GetAsyncKeyState('S')) sy += 1;

			counter += counter; // seconds
		}

    // Well this was a failure . . .
		moveCan = true;
		for (int i = 0; i < cormap.size(); i++) {
			if (cormap[i][0] == sx && cormap[i][1] == sy) {
				moveCan = false;
			}
		}
		if (sx > 39) {
			moveCan = false;
		}

		if (moveCan = true) {
			gotoxy(sx, sy); 
			cout << "O";
		}
		maze();
	}

	std::cin.get();
	return 0;
}
