#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int currSum = 0;
		int maxSum = 0;
		for (int i = 0; i < nums.size(); i++) {
			currSum += nums[i];
			if (currSum > maxSum) {
				maxSum = currSum;
			}
			// OR
			// currentSum = max(nums[i], currentSum + nums[i]);
			// maxSum = max(maxSum, currentSum);
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
