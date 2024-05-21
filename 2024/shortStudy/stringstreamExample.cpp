#include <sstream>
#include <iostream>
using namespace std;

int main() {
	stringstream ss("23,4,56");
	char ch;
	int a, b, c;
	ss >> a >> ch >> b >> ch >> c;
	cout << a << b << c << ch;

	return 0;
