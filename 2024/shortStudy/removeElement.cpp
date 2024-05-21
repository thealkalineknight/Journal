#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void removeElement(vector<int>& nums, int val) {
		int index = 0;
		const int lim = 6;
		int box[lim]{};
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val) {
				box[index] = nums[i];
				index++;
			}
		}
		for (int i = 0; i < index; i++) cout << box[i] << " ";
	}
};

int main() {
	Solution solution;
	vector<int> array = { 1, 2, 3, 4, 1 };
	int num = 1;

	// cout << solution.removeElement(array, num);
	solution.removeElement(array, num);

	return 0;
}
