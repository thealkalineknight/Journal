#include <iostream>
#include <vector>
using namespace std;


int main() {
	int maxA{};
	int queNum{};
	cout << "maxA + queries" << "\n";
	cin >> maxA >> queNum;

	vector<vector<int>> array;

	for (int i = 0; i < maxA; i++) {
		int maxB{};
		cout << "maxB" << "\n";
		cin >> maxB;

		vector<int> temp;

		for (int j = 0; j < maxB; j++) {
			int num{};
			cout << "num" << "\n";
			cin >> num;

			temp.push_back(num);
		}
		array.push_back(temp);
	}

	vector<int> results;

	for (int i = 0; i < queNum; i++) {
		int inA{};
		int inB{};
		cout << "indexA + indexB" << "\n";
		cin >> inA >> inB;

		results.push_back(array[inA][inB]);
	}

	for (int i = 0; i < results.size(); i++) cout << "Query " << i << ": " << results[i]  << "\n";
	return 0;
}
