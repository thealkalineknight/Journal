#include <iostream>
#include <Windows.h>
#include <cctype>
using namespace std;


int main() {  // nonsensical output when A is pressed
	while (true) {
		for (int i = 0; i < 256; i++) {
			if (GetAsyncKeyState('A')) {  //&0b1
				if (std::isupper(i)) {
					cout << (char)i;
				}
				else if (i == VK_ESCAPE) {
					cout << "esc";
				}
				// etc
			}
		}
	}
	std::cin.get();
	return 0;
}
