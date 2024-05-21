#include <Windows.h>
#include <fstream>
#include <cctype>

// outputs message boxes based on input keys

int work() {
	if (GetAsyncKeyState('A') & 0b1) return 2;
	if (GetAsyncKeyState('S') & 0b1) return 3;
}


int WinMain(
	HINSTANCE hInstance, // instance handle
	HINSTANCE hPrevInstance,  // unused
	LPSTR     lpCmdLine,  // cmd
	int       nShowCmd  // how to open
)
{
	int num = work();

	if (num == 2) {
		MessageBox(0, L"case A", L"", MB_OK);
	}
	if (num == 3) {
		MessageBox(0, L"case S", L"", MB_OK);
	}

	return 0;
}
