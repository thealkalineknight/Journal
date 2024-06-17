#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream ss(str);
    char ch;
    int a;
    vector<int> nums;
    while (ss >> a) {
        nums.push_back(a);
        ss >> ch;
    }
    return nums;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}



/*
Fig1: 1. Must use vec cause func name, and non-fixed len. 2. But unkown len usually calls for a loop. 3. Can ss take vecs?
vector<int> parseInts(string str) {
    stringstream ss(str);
    char ch;
    vector<int> nums;
    ss >> nums >> ch;
    return nums;
}

Fig2: 1. No, ss takes int. 2. Won't this only return 1 number?
vector<int> parseInts(string str) {
    stringstream ss(str);
    char ch;
    vector<int> nums;
    ss >> a >> ch;
    nums.push_back(a);
    return nums;
}

Fig3: 1. Yes, so use a loop. 2. While something exists. 3. While a exists in str.
vector<int> parseInts(string str) {
    stringstream ss(str);
    char ch;
    vector<int> nums;
    while (ss >> a) {  // does action in here while compare
      nums.push_back(a);
      ss >> ch;
    }
    return nums;
}

Missing Concept: Action while true test

Also: can use same concept for counting words in an sstring.
*/
