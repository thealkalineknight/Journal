#include <iostream>
#include <list>

int main() {
	std::list<int> mylist = { 0, 1, 2, 3, 4 };
	for (auto v : mylist)  // automatically inits v as int
		std::cout << v << " ";
	return 0;
}
