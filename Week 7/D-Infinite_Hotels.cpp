// Taimur Azhar z5116684
// Prog Chal
// Week 7 Problem D - Infinite Hotel Problem

#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

int main() {
	ll a, sum, n;
	while (cin >> a >> sum) {
		// Solve the quadratic solution
		n = (ll)ceil((- 1 + sqrt(4 * a * a + 8 * sum - 4 * a + 1 )) / 2);
		ll ans = n;
		ll check = (a + ans - 1) * (ans - 1 / 2); 
		//if (sum <= check) {
		//	ans --;
		//}
		cout << ans << endl;

	}

	return 0;
}