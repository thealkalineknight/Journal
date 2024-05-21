#include <Windows.h>
#include <iostream>

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	const char* data = "hello world";
	DWORD characters = 0; //characters written

	HANDLE consolebuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr,
		CONSOLE_TEXTMODE_BUFFER, 0);
	SetConsoleActiveScreenBuffer(consolebuffer);

	WriteConsoleOutputCharacter(h, L"hello world", strlen(data), {}, &characters);


	// std::cin.get();
	// const char* data = "hello world";  // versus
	// char* p = (char*)"abc";
	return 0;
}
