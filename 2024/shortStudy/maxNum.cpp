#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d) {
	int box[4] = { a, b, c, d };
	int sol = box[0];
	int temp{};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (box[i] < box[j]) temp = box[j];
		}
		if (sol < temp) sol = temp;
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
