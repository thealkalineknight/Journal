#include <iostream>
#include <cstdio>
using namespace std;

void update(int* a, int* b) {
	int aSave = *a;
	*a = *a + *b;
	*b = (aSave - *b);
	if (*b < 0) *b = *b * -1;

}  // lesson: remember to use equal sign, dumnut

int main() {
	int a{4};
	int b{5};
	int* pa = &a;
	int* pb = &b;
	update(pa, pb);

	cout << a << " " << b;  
	return 0; //notice how no need point within og func
