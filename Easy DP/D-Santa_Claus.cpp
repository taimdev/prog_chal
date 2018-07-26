// Taimur Azhar z5116684
// Easy Dp Questions
// Week 5 D - Santa Claus

#include <iostream>
#include <stdlib.h>
#include <string.h>

#define SIZE 1004

using namespace std;

int cache[SIZE];
//int prevnums[SIZE][SIZE];

int f(int currnum, int initnum, ) {
	if (currnum == 0) {
		cout << "returning now " << endl;
		return 0;
	}
	if (currnum < 0) {
		cout << "too low " << endl;
		return -1000;
	}
	if (cache[currnum] != -1)  {
		cout << "using a cache" << currnum << cache[currnum] << endl;
		return cache[SIZE];
	}
	int maxno = -1000;
	for (int i = 1; i < initnum; i ++) {
		//cout << "hi" << endl;
		if (prevnums[currnum][i] == -1) {

			cout << "Curr num is " << currnum << endl;
			cout << "looping through " << i << endl;
			prevnums[currnum][i] = 1;
			if (currnum - i >= 0) {
				prevnums[currnum - i][i] = 1;
			}
			maxno = max(maxno, f(currnum - i, initnum));
			cout << "returned from a recurse" << endl;
		}
	}
	cache[currnum] = maxno + 1;
	return cache[currnum];

}
int main() {
	int num;
	cin >> num;

	for (int i = 0; i <= SIZE; ++i) {
		cache[i] = -1;	
	}
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			prevnums[i][j] = -1;
		}
	}
	cout << num << "num"<< endl;
	cout << f(num, num) << endl;


}