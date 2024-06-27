#include<iostream>
#include<vector>
using namespace std;

// This is the version for HackerRank. 
// Difference with the other one is no cout messages, of course, no final size output,
// and max size 4 removes 3rd element (while min 2 removes index 2, which I thought was bizzare, but I may be odd).

int main() {
    int max{};
    int num{};
    int rem1{};
    int remMin, remMax;
    vector<int> nums;

    cin >> max;
    for (int i = 0; i < max; i++) {
        cin >> num;
        nums.push_back(num);
    }

    cin >> rem1;
    nums.erase(nums.begin() + rem1 - 1);

    cin >> remMin; cin >> remMax;
    remMin -= 1; remMax -= 1;
    int maxItem = nums[remMax];

    for (int i = remMin; i < remMax; i++) {
        nums.erase(nums.begin() + remMin);
    }

    cout << nums.size() << "\n";

    for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    return 0;
}
