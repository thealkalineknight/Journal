#include <iostream>

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;

		int temp = x;
		int reversed{};

		while (temp != 0) {
			int num = temp % 10;
			reversed = reversed * 10 + num;
			temp /= 10;
		}
		return (reversed == x);
	}
};

int main() {
	Solution solution;
	std::cout << solution.isPalindrome(868) << '\n';

	return 0;
}
