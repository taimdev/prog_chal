// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 1
// Problem A Hangover
# include <iostream>
# include <cstdio>
// allow us to make it easy to just use cin and cout
using namespace std;

int main () {
	// initialise vars
	double lim;

	// read input
	while (cin) {
		cin >> lim;
		//printf("%f\n",lim);
		int ans = 0;
		double sum = 0.00;
		while (sum < lim) {
			ans += 1;
			sum += (1.0/(ans + 1));
			//printf("%f\n",sum );
		}

		if (ans == 0) {
			cout << endl;
			return 0;
		}

		cout << ans << " card(s)" << endl;
	}
	// dont forget to return zero, or might fail
	return 0;
}