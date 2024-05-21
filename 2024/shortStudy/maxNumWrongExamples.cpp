#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d) {
	int box[4] = { a, b, c, d };
	// int sol{};  //prob 1
	int sol = box[0];

	for (int i = 1, j = 0; i < 4; i++, j++) {
		if (box[j] < box[i]) sol = box[i];
	}
	return sol;
}

int main() {
	int a{}, b{}, c{}, d{};
	cin >> a >> b >> c >> d;
	int ans = max_of_four(a, b, c, d);
	cout << ans;

	return 0;
}

// prob 1: cases like 6666 or 5666 ignored until sol not init as 0
// prob 2: 7116 ignored because each element only compared to neighbor
