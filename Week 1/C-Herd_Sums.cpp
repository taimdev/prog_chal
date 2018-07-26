// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 1
// Problem C Herd Sums

# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int main() {
	int cows;
	cin >> cows;

	// init vars
	int sum = 0;
	std::vector<int> arr;
	int numSum = 1;
	int discard;
	int i = 1;

	while (i <= cows) {
		if (sum < cows) {
			sum += i;
			arr.insert(arr.begin(), i);
			//cout << i << endl;
			i ++;
			continue;
		} else if (sum == cows) {
			numSum ++;
			discard = arr[arr.size() - 1];
			arr.pop_back();
			sum -= discard;
			//cout << "equal"<< numSum <<" " << discard <<" "<< sum << endl;
		} else {
			discard = arr[arr.size() - 1];
			arr.pop_back();
			sum -= discard;
			//cout << "larger" << numSum<<" " << discard<<" " << sum << endl;
		}

		if (discard >= cows / 2) {
			cout << numSum << endl;
			return 0;
		}
	}

	return 0;
}