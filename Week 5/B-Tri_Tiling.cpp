// Taimur Azhar z5116684
// Week 5 Prog Chal
// Problem B - Tri Tiling

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <utility>
#include <string.h>

#define SIZE 33

int fcache[SIZE];
int gcache[SIZE];

using namespace std;
int f(int);
int g(int);

int f(int i) {
	if (i == 0) {
		return 1;
	}
	if (i % 2 != 0) {
		return 0;
	}
	if (fcache[i] != 0) {
		return fcache[i];
	}

	return fcache[i] = f(i - 2) + 2 * g(i - 1);
}
int g(int j) {
	if (j == 0) {
		return 0;
	}
	if (j == 1) {
		return 1;
	}
	if (gcache[j] != 0) {
		return gcache[j];
	}

	return gcache[j] = f(j - 1) + g(j - 2);
}

int main() {
	int tile;
	cin >> tile;
	while (tile != -1) {
		cout << f(tile) << endl;
		cin >> tile;
	}
	return 0;
}