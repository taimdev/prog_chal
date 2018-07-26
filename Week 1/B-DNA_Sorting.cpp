// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 1
// Problem B DNA Sorting
# include <iostream>
# include <cstdio>
# include <vector>
# include <map>
# include <algorithm>
// allow us to make it easy to just use cin and cout
using namespace std;

bool mycomp(const pair<int, string> &a , const pair <int, string> &b) {
	return a.first < b.first;
}

int main () {
	// initialise vars
	int dataNum;
	int length;
	int lines;
	int i = 0;
	cin >> dataNum;


	for (int i = 0; i < dataNum; i ++)  {
		// For the amount of datasets
		cin >> length >> lines;
		// Read in the length and lines
		pair<int, string> arr[lines];
		std::multimap<int, string> dnamap;

		for (int j = 0; j < lines; j ++) {
			// For the amount of lines, create a string 
			char dnastr[length];
			// Read into string
			cin >> dnastr;
			// Find the unsortedness of the string
			int sortedness = 0;
			for (int k = 0; k < length; k ++) {
				if (dnastr[k] == 'A') continue;
				for (int l = k; l < length; l ++) {
					if (dnastr[l] == 'T') continue;
					if (dnastr[k] > dnastr[l]) {
						sortedness ++;
					}
				}
			}
			// Put into map
			dnamap.insert(pair <int, string> (sortedness, dnastr));
			// Put into array
			pair <int, string> comb;
			comb.first = sortedness;
			comb.second = dnastr;
			arr[j] = comb;
			//cout << sortedness << endl;
			//cout << dnastr << endl;
		}

		// Print directly from the sorted map
		for (std::map<int, string>::iterator it = dnamap.begin(); it != dnamap.end(); ++it) {
			cout << it->second << endl;
		}
		//cout << endl;
		// Stable sort the array containing the pairs
		//std::stable_sort(arr, arr + lines, mycomp);
		// Print
		//for (int m = 0; m < lines; m ++) {
		//	cout << arr[m].second << endl;
		//}

		if (i == dataNum - 1) {
			
		} else {
			cout << endl;
		}
	}



	// dont forget to return zero, or might fail
	return 0;
}

	