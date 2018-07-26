// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 2
// Problem C Dark Roads
// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 2

# include <iostream>
# include <cstdio>
# include <stdlib.h>
# include <map>
# include <utility>
# include <algorithm>
# define JUNCT 200000
using namespace std;

typedef pair<int, int> MyPair;
int parent [JUNCT];
int subtree_size [JUNCT];

struct edge {
	int u, v, w;
};
bool operator < ( const edge & a, const edge & b) {
	//cout << a.w << b.w << "sort"<< endl;
	return a.w < b.w;
}

void init (int n) {
	parent [n] = n; subtree_size [n] = 1;
	
}
int root ( int x) {
	// only roots are their own parents
	// otherwise apply path compression
	return parent [x] == x ? x : parent [x] = root ( parent [x]) ;
}
void join ( int x, int y) {
	// size heuristic
	// hang smaller subtree under root of larger subtree
	//cout << "ehl"<< endl;
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
	int junct, roads;
	while (cin >> junct >> roads) {
		//cout << junct << roads << endl;
		if ((junct == roads) && (junct == 0)) {
			//cout << "continue" << endl;
			continue;
		}
		//cout << junct << roads << endl;
		if (roads == 0) {
			cout << 0 << endl;
			continue;
		}
		int total_weight = 0;
		edge edges[roads];
		int seen = junct - 1;

		for (int j = 0; j < roads; j ++) {
			//cout << j << endl;
			int x, y, dist;
			cin >> x >> y >> dist;
			// Make an edge
			edge e;
			e.u = x;
			e.v = y;
			e.w = dist;
			edges[j] = e;
			init(x);
			init(y);
			total_weight += dist;
		}

		sort (edges , edges + roads) ; // sort by increasing weight
		int min_weight = 0;
		for (int i = 0; i < roads; i ++) {
			edge & e = edges [i];
			// if the endpoints are in different trees , join them
			//cout << e.u << " to "<<e.v<<" for "<<e.w<< endl;
			if (root (e.u) != root (e.v)) {
				//cout << e.u << " to "<<e.v<<" for "<<e.w<< endl;
				min_weight += e.w;	
				join (e.u, e.v);
				seen --;
				//cout << "seen" << seen<<endl;
				if (seen == 0) {
					int ans = total_weight - min_weight;
					cout << ans << endl;
					break;
				}
			}
		}
	}
	return 0;
}




