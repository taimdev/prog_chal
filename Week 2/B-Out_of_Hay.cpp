// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 2
// Problem B Out of Hay

# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <stdlib.h>
# include <math.h>
# include <map>
# include <utility>
# define FARMS 2000
using namespace std;

typedef pair<int, int> MyPair;

int parent [FARMS];
int subtree_size [FARMS];

void init (int n) {
	for (int i = 0; i <= n; i ++) {
		parent [i] = i; subtree_size [i] = 1;
	}
}
int root ( int x) {
	// only roots are their own parents
	// otherwise apply path compression
	return parent [x] == x ? x : parent [x] = root ( parent [x]) ;
}
void join ( int x, int y) {
	// size heuristic
	// hang smaller subtree under root of larger subtree
	x = root (x); y = root (y) ;
	if (x == y) return ;
	if ( subtree_size [x] < subtree_size [y]) {
		parent [x] = y;
		subtree_size [y] += subtree_size [x];
	} else {
		parent [y] = x;
		subtree_size [x] += subtree_size [y];
	}
}

int main() {
	int farms, roads;
	cin >> farms >> roads;
	multimap<int, MyPair> edges;

	//Union-find

	
	for (int i = 0; i < roads; i ++) {
		int x, y, dist;
		cin >> x >> y >> dist;
		// Make a pair
		MyPair vertex (x,y);
		// insert into map
		edges.insert(pair <int, MyPair> (dist, vertex));
		init(x);
		init(y);
	}
	int largest = 0;
	for (multimap<int, MyPair>::iterator it = edges.begin(); it != edges.end(); ++it) {
		//cout << "dist" << it->first << endl;
		//cout << "vertex"<< it->second.first << it->second.second << endl;
		int dist = it->first;
		int v1 = it->second.first;
		int v2 = it->second.second;

		if (root(v1) != root(v2)) {
			// then not connected, so conenct
			join(v1, v2);
			if (dist > largest) {
				largest = dist;
			}

		}
	}
	cout << largest << endl;
	return 0;
}
