// Taimur Azhar z5116684
// Easy Dp Questions
// Week 5 B - Knapsack Problem

#include <iostream>
#include <stdlib.h>
#include <string.h>

#define SIZE 2000

using namespace std;

pair <int , int> s[SIZE];
int cache[SIZE][SIZE];

int f(int i, int space, int itemno) {
	//cout << " up to item " << i << " space " << space << endl;
	if (space < 0) {
		return -100000;
	}
	if ((i >= itemno) || (space == 0)) {
		// up to the last item or no space left
		return 0;
	}
	if (cache[i][space] != -1) return cache[i][space];

	cache [i][space] = max(f(i + 1, space - s[i].first, itemno) + s[i].second, f(i + 1, space, itemno));f(i + 1, space, temno) << endl;
	return cache[i][space];
}
int main() {
	int bag, itemno;
	cin >> bag >> itemno;

	for (int i = 0; i < SIZE; i ++) {
		for (int j = 0; j < SIZE; j ++) {
			cache[i][j] = -1;
		}
	}

	for (int i = 0; i < itemno; ++i) {
		int size, value;
		cin >> size >> value;
		s[i] = make_pair(size, value);
	}
	cout << f(0, bag, itemno) << endl;
}