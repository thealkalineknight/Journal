#include<iostream>
#include<vector>
using namespace std;

int main() {
    int max{};
    int num{};
    int rem1{};
    int remMin, remMax;
    vector<int> nums;
    cout << "Input max num count." << '\n';
    cin >> max;
    cout << "Input all nums." << '\n';
    for (int i = 0; i < max; i++) {
        cin >> num;
        nums.push_back(num);
    }
    cout << "Input index of one element to remove" << '\n';
    cin >> rem1;
    nums.erase(nums.begin() + rem1 - 1);

    cout << "Input min index, then max to remove." << '\n';
    cin >> remMin; cin >> remMax;
    remMin -= 1;
    int maxItem = nums[remMax];

    for (int i = remMin; i < remMax; i++) {

        nums.erase(nums.begin() + remMin);
    }

    for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    return 0;
}
