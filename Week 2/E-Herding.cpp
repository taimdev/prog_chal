// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 2
// Problem E Herding
// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 2

# include <iostream>
# include <cstdio>
# include <stdlib.h>
# include <map>
# include <set>
# include <utility>
# include <algorithm>
# define SIZE 1005
using namespace std;

int traps = 0;
pair <int, int> parent[SIZE][SIZE];
int subtree_size[SIZE][SIZE];
int seen[SIZE][SIZE];
int matrix[SIZE][SIZE];

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
	}
	//return parent[x] == x ? x : parent [x] = root ( parent [x]) ;
}
void join (int y1, int x1, int y2, int x2) {
	// size heuristic
	// hang smaller subtree under root of larger subtree
	pair<int, int> p1 = root(y1, x1); 
	pair<int, int> p2 = root(y2, x2);
	if (p1 == p2)  {
		traps ++;
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

void check(int y, int x, int y_init, int x_init) {
	if (seen[y][x] != 1) {
		seen[y][x] = 1;
	} else {
		return;
	}
	char direction = matrix[y][x];
	//cout << direction<< endl;
	//cout << "checking" << y << x << "and" << direction << endl;
	if (direction == 'N') {
		join(y, x, y - 1, x);
		check(y - 1, x, y_init, x_init);
	} else if (direction == 'E') {
		join(y, x, y, x + 1);
		check(y, x + 1, y_init, x_init); 	
	} else if (direction == 'S') {
		join(y, x, y + 1, x);
		check(y + 1, x, y_init, x_init);
	} else if (direction == 'W') {
		join(y, x, y, x - 1);
		check(y, x - 1, y_init, x_init);	
	}
}

int main() {
	int y_init, x_init;

	cin >> y_init >> x_init;
	for (int i = 0; i < y_init; i ++) {
		for (int j = 0; j < x_init; j ++) {
			char direction;
			cin >> direction;
			matrix[i][j] = direction;
			//cout << direction;	
			init(i, j);
		}
		//cout << endl;
	}

	for (int y = 0; y < y_init; y ++) {
		for (int x = 0; x < x_init; x++) {
			if (seen[y][x] != 1) {
				//seen[y][x] = 1;
				check(y, x, y_init, x_init);
			}
		}
	}

	//int total = x_init * y_init;
	//cout << "total" << total << endl;
	//int ans = total - traps;

	cout << traps << endl;

	return 0;
}
