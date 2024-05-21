#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool duplicateElement(vector<int>& nums) {
		vector<int> nums2 = nums;

		for (int i = 0; i < nums.size(); i++) {
			int index = 0;
			for (int j = 0; j < nums2.size(); j++) {
				if (nums2[j] == nums[i]) {
					index++;
				}
				if (index > 1) return true;
			}
		}
		return false;
	}
};

int main() {
	Solution solution;
	vector<int> array = { 1, 2, 3, 4, 1 };

	cout << solution.duplicateElement(array);

	return 0;
}
