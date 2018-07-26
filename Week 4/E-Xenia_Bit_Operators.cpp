// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 4
// Problem E Bit operations

# include <iostream>
# include <cstdio>
# include <stdlib.h>
# include <stack>
# include <queue>
# include <map>
# include <math.h>
# include <string>
# define MAX_N 131072
using namespace std;

// the number of additional nodes created can be as high as the next power of two up from MAX_N (131 ,072)
int tree [266666];
// a is the index in the array . 0 - or 1 - based doesn ’t matter here , as
// long as it is nonnegative and less than MAX_N .
// v is the value the a-th element will be updated to.
// i is the index in the tree , rooted at 1 so children are 2i and 2i +1.
// instead of storing each node ’s range of responsibility , we calculate it on the way down .
// the root node is responsible for [0 , MAX_N )
void update ( int a, int v, int power, int i = 1, int start = 0, int end = MAX_N) {
	// this node ’s range of r e s p o n s i b i l i t y is 1 , so it is a leaf
	if ( end - start == 1) {
		tree [i] = v;
		return ;
	}
	// figure out which child is responsible for the index (a) being updated
	int mid = ( start + end ) / 2;
	if (a < mid ) update (a, v, power + 1, i * 2, start , mid);
	else update (a, v, power + 1, i * 2 + 1, mid , end);
	// once we have updated the correct child , recalculate our stored value .
	//cout << "power is" << power << endl;
	if (power % 2 == 1) {
		tree [i] = tree [i *2]|tree [i *2+1];
		//cout <<" i is " << i << " value is " << tree[i] << " OR" << endl; 
	} else {
		tree [i] = tree [i *2]^tree [i *2+1];
		//cout <<" i is " << i << " value is " << tree[i] << " XOR " << endl; 
	}
}
int main() {
	int power, queries;
	cin >> power >> queries;
	int size = pow(2,power) + 1;
	for (int i = 1; i < size; i++) {
		int digit;
		cin >> digit;
		update(i, digit, power, 1, 1, size);
	}
	for (int i = 0; i < queries; i++) {
		int index, val;
		cin >> index >> val;
		update(index, val, power, 1, 1, size);
		cout << tree[1] << endl;

	}
}

