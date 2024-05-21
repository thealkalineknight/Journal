#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int prevNum = 0;
		int maxSum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (prevNum + nums[i] > maxSum) {
				// store values?
				maxSum = prevNum + nums[i];
			}
			prevNum = nums[i];
		}
		return maxSum;
	}
};

int main() {
	Solution solution;
	vector<int> array = { 1, 2, 3, 4, 1 };

	cout << solution.maxSubArray(array);

	return 0;
}
