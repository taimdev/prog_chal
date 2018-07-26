// Taimur Azhar z5116684
// Prog Chal
// Week 6 Problem B - Factorial

#include <stdlib.h>
#include <iostream>
#include <math.h>

#define ll long long;

using namespace std;

ll highpow5(ll n) {
   ll p = ((ll)log(n))/((ll)log(5));
   return (ll)pow(5, p); 
}

int main() {
	ll num;
	cin >> num;

	for (ll i = 0; i < num; ++i) {
		ll x;
		cin >> x;
		// The largest power of 5 less than x
		ll lim = highpow5(x);
		ll div = lim;

		ll zeroes = 0;
		while (div != 1) {
			zeroes += (ll)(x / div);
			div = div / 5;
		}
		cout << zeroes << endl;
	}

	return 0;
}