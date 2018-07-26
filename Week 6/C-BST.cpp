// Taimur Azhar z5116684
// Prog Chal
// Week 6 Problem C - BST

#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

int min(int, int);
int max(int, int);

int highpow2(int n) {
   int p = (int)log2(n);
   return (int)pow(2, p); 
}
int min(int root, int level) {
	if (root % 2 == 1) {
		return root;
	} else {
		return min(root - (level / 2), level / 2 );
	}
}
int max(int root, int level) {
	if (root % 2 == 1) {
		return root;
	} else {
		return max(root + (level / 2), level / 2 );
	}
}

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; ++i) {
		int x;
		cin >> x;
		// The largest power of 2 less than x
		int lim = highpow2(x);
		int div = lim;

		while (div != 1) {
			if (x % div == 0) {
				break;
			} else {
				div = div / 2;
			}
		}
		cout << min(x, div) << " " << max(x, div) << endl;

	}

	return 0;
}