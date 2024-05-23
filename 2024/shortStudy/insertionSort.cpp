#include <iostream>
#include <vector>
using namespace std;

// check here for Python + explanation: Journal/2023/insertionSort.py

void insertionSort(vector<int>&nums) {
	for (int i = 1; i < nums.size(); i++) {
		int current = nums[i];
		int revJ = i - 1;
		while (revJ >= 0 && nums[revJ] > current) {
			nums[revJ + 1] = nums[revJ];
			revJ -= 1;
		}
		nums[revJ + 1] = current;
	}
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}

int main() {
	int count{};
	cout << "input num count" << '\n';
	cin >> count;

	vector<int> input{};
	cout << "input nums" << '\n';
	for (int i = 0; i < count; i++) {
		int num{};
		cin >> num;
		input.push_back(num);
	}

	insertionSort(input);

	return 0;
}
