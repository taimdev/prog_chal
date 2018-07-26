// Taimur Azhar z5116684
// Easy Dp Questions
// Week 5 A - Maximum Increase

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
	int digits;
	cin >> digits;

	int input_arr[digits];
	int max_arr[digits];
	memset(max_arr, 0, sizeof(max_arr));

	for (int i = 0; i < digits; ++i) {
		int num;
		cin >> num;
		input_arr[i] = num;
	}

	for (int i = 0; i < digits; ++i) {
		if (i == 0) {
			continue;
		} else {
			if (input_arr[i - 1] < input_arr[i]) {
				max_arr[i] = max_arr[i - 1] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < digits; ++i) {
		if (max_arr[i] >= max) {
			max = max_arr[i];

		}

	}
	max++;
	cout << max << endl;


	return EXIT_SUCCESS;
}