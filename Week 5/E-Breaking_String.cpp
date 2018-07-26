// Taimur Azhar z5116684
// Week 5 Prog Chal
// Problem E - Breaking String

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <utility>
#include <string.h>

#define LENGTH 10000005
#define INF 2e9
#define BREAKMAX 1005

using namespace std;

int divarr[BREAKMAX];
int f[BREAKMAX][BREAKMAX];
int a[BREAKMAX][BREAKMAX];

int main() {
	int strlen, breaks;
	while (cin >> strlen >> breaks) {
		for (int i = 1; i <= breaks; ++i) {
			cin >> divarr[i];
		}
		divarr[0] = 0;
		divarr[breaks + 1] = strlen;
		// shorter intervals should be processed before longer intervals
		// length is the number of breaking points strictly between i and j
		for (int length = 0; length <= breaks; length ++) {
			//cout << "length is " <<length <<  endl;
			for (int i = 0 , j = length + 1; j <= breaks + 1; i++ , j ++) {
			// base case
				if (length == 0)  {
					f[i][j] = 0;
				}
				else if (length == 1) {
					a[i][j] = i + 1;
					f[i][j] = divarr[j] - divarr[i];

				} else {
					f[i][j] = INF;         
					for (int k = a[i][j - 1]; k <= a[i + 1][j]; k ++) {
						// cost returns p_j - p_i , the cost of cutting this segment
						//cout << "lol same " << i << " and " << j << endl;
						//cout << "the stuff is " << a[i][j - 1] << " f " <<  a[i + 1][j] << endl;
						//cout << "count is up to " << k << endl;
						//cout << "dab " << f[i][k] << " and " << f[k][j]<< endl;
						if (f[i][j] > f[i][k] + f[k][j] + divarr[j] - divarr[i]) {
							f[i][j] = f[i][k] + f[k][j] + divarr[j] - divarr[i];
							a[i][j] = k;
						}
						//f[i][j] = min(f[i][j], f[i][k] + f[k][j] + divarr[j] - divarr[i]);
					}
				}
			}
		}
		cout << f[0][breaks + 1] << endl;
		//cin >> strlen >> breaks;
	}


	return 0;
}