// Taimur Azhar z5116684
// Prog Chal
// Week 7 Problem A - Plant

#include <stdlib.h>
#include <iostream>
#include <math.h>

#define LIM 1000000007

using namespace std;

typedef long long ll;

ll exponent(ll x, ll k) {
	if (k == 0) {
		return 1;
	}
	ll a = exponent(x, k / 2) % LIM;
	a = (a * a) % LIM;
  	if (k % 2 == 1) {
  		a = (a * x) % LIM;
  	}	
  return a;
}


int main() {
	ll years;
	cin >> years;
	if (years == 0) {
		cout << 1 << endl;
		return 0;
	}
	ll first = exponent(2, years);
	ll sum = ((first + 1) * (first / 2)) % LIM;
	cout << sum << endl;
	return 0;
}