// Taimur Azhar z5116684
// Week 5 Prog Chal
// Problem C - Zuma

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <utility>
#include <string.h>

#define SIZE 505
#define MAX 2e9

using namespace std;

int a[SIZE];
int cache[SIZE][SIZE];

int f(int l,int r) {
	//cout << "current at indexes " << l  << " and " << r << endl;
	//cout << "current at values " << a[l] << " and " << a[r] << endl;
    if (l >= r) {
    	return 1;
    }
    if (cache[l][r] != -1) {
    	return cache[l][r];
    } 
    cache[l][r] = MAX;
    if (a[l] == a[r]) {
    	cache[l][r] = f(l + 1, r - 1);
    } 
    for (int i = l; i < r; i++) {
        cache[l][r]= min(cache[l][r], f(l, i) + f(i + 1, r));
    }
    return cache[l][r];
}
int main() {

    int num;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cache[i][j] = -1;
		}
	}
	cin >> num;
	for (int i = 0; i < num; ++i) {
		int letter;
		cin >> letter;
		//cout << letter;
		a[i] = letter;
	}
	cout << f(0, num - 1) << endl;

	return 0;
}