// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 4
// Problem B Ice Skating

# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <stdlib.h>
# include <utility>
# include <queue>
# include <set>
# include <map>
# define SIZE 100
# define GRID 1001 
using namespace std;

pair <int, int> parent[GRID][GRID];
int subtree_size[GRID][GRID];
int largest = 0;
int matrix[GRID][GRID];
int seen[GRID][GRID];

void init (int y, int x) {
	pair <int, int> median = make_pair(y,x);
	parent[y][x] = median; 
	subtree_size[y][x] = 1;
}
pair<int,int> root (int y, int x) {
	// only roots are their own parents
	// otherwise apply path compression
	if (parent[y][x] == make_pair(y, x)) {
		return make_pair(y, x);
	} else {
		parent[y][x] = root(parent[y][x].first, parent[y][x].second);
		return parent[y][x];
	}
	//return parent[x] == x ? x : parent [x] = root ( parent [x]) ;
}
void join (int y1, int x1, int y2, int x2) {
	// size heuristic
	// hang smaller subtree under root of larger subtree
	pair<int, int> p1 = root(y1, x1); 
	pair<int, int> p2 = root(y2, x2);
	if (p1 == p2)  {
		//traps ++;
		//cout << "the parent of " << y1 << << << << 
		return ;
	}
	//cout << "traps is now" << traps<<" at " << y1 << x1 <<"poitn"<< y2 << x2 << endl;
	if (subtree_size[y1][x1] < subtree_size[y2][x2]) {
		parent[y1][x1] = p2;
		subtree_size[y2][x2] += subtree_size[y1][x1];
	} else {
		parent[y2][x2] = p1;
		subtree_size[y1][x1] += subtree_size[y2][x2];
	}
}
void something(int origx, int origy) {
	for (int x = 0; x <= largest; x ++) {
		//cout << "going through" << x << origy << endl;
		if ((matrix[x][origy] == 1) && (seen[x][origy] == 0)) {
			join(origy, origx, origy, x);
			seen[x][origy] = 1;
			//cout << x << origy << " set at " << components << endl;
			something(x,origy);
		}
	}
	for (int y = 0; y <= largest; y ++) {
		//cout << "going through" << origx << y << endl;
		if ((matrix[origx][y] == 1) && (seen[origx][y] == 0)) {
			join(origy, origx, y, origx);
			seen[origx][y] = 1;
			//cout << origx << y<< " set at " << components << endl;
			something(origx,y);
		}
	}
}

int main() {
	int driftno;
	cin >> driftno;
	//int set2[GRID][GRID];
	map<int, pair<int, int> > storage;
	//return 0;
	//int largest = 0;
	for (int i = 0; i < driftno; ++i) {
		int x, y;
		cin >> x >> y;
		//cout << x << y << endl;
		matrix[x][y] = 1;
		init(y,x);
		pair<int, int> currpair (x, y);
		storage.insert(pair<int, pair<int,int> > (i, currpair));
		if (x > largest) {
			largest = x;
		}
		if (y > largest) {
			largest = y;
		}
	}
	largest += 1;

	for (map<int, pair<int, int> >::iterator it = storage.begin(); it != storage.end(); ++it) {
		//pair<int, int>  mypair = *it;
		//cout << it->first << it->second.first << it->second.second << endl;
		int origx = it->second.first;
		int origy = it->second.second;
		//cout << "currently at" << origx << origy << endl;
		//seen[origx][origy] = 1;
		//components ++;
		if (seen[origx][origy] == 0) {
			something(origx, origy);
		}
	}

	//cout << "new" << endl << endl;
		int components = 0;
	for (map<int, pair<int, int> >::iterator it = storage.begin(); it != storage.end(); ++it) {
		//pair<int, int>  mypair = *it;
		//cout << it->first << it->second.first << it->second.second << endl;
		int origx = it->second.first;
		int origy = it->second.second;
		//cout << "currently at" << origx << origy << endl;
		if (root(origy,origx) == make_pair(origy, origx)) {
			//cout << "is its own root" << origx << origy << endl;
			components ++;
		}
	}


	int ans = components - 1;
	cout << ans << endl;
}