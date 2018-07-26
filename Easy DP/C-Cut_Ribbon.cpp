// Taimur Azhar z5116684
// Easy Dp Questions
// Week 5 C - Cut Ribbon

#include <iostream>
#include <stdlib.h>
#include <string.h>

#define SIZE 4004

using namespace std;

int cache[SIZE];

int length, a , b, c;

int f(int currlen) {
	//cout <<" current length " << currlen << endl;
	if (currlen == 0) {
		return 0;
	} 
	if (currlen < 0) {
		return -100000;
	}

	if (cache[currlen] != -1) return cache[currlen];

	int val = f(currlen - a);
	val = max(val, f(currlen - b));
	val = max(val, f(currlen - c));

	return cache[currlen] = val + 1;
}
int main() {
	cin >> length >> a >> b >> c ;
	//memset(cache, -1, sizeof(cache));
	for (int i; i <= SIZE; i++) {
		cache[i] = -1;
	}
	cout << f(length) << endl;

}