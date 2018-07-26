// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 1
// Problem E Lumberjack Sequencing

# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <stdlib.h>
# include <math.h>
# define SIZE 102	

using namespace std;
int main() {
	int datasets;
	cin  >> datasets;
	cout << "Lumberjacks:" << endl;
	for (int i = 0; i < datasets; i ++) {
		// for each dataset intialise an array
		int arr[10];
		int great = 0;
		int less = 0;
		for (int j = 0; j < 10 ; j ++) {
			// take in ten inputs and put then into an array
			//cout << j << endl;
			int len;
			cin >> len;
			//cout << len << endl;
			arr[j] = len;
			//cout << arr[j] << endl;
		}
		for (int k = 1; k < 10; k ++) {
			//cout << arr[k] << endl;
			if (arr[k -1] < arr[k]) {
				//cout << arr[k -1] <<"<" <<arr[k]<< endl;
				great ++;
			} else if (arr[k -1] > arr[k]) {
				//cout << arr[k -1] <<">" <<arr[k]<< endl;
				less ++;
			} else if (arr[k-1] == arr[k]) {
				//cout << arr[k -1] <<"==" <<arr[k]<< endl;
				great ++;
				less ++;
			}
		}
		//cout << "great" << great << "less" << less << endl;

		if ((great == 9) || (less == 9)) {
			cout << "Ordered" << endl;
		} else {
			cout << "Unordered"<< endl;
		}
	}

	/* code */
	return 0;
}