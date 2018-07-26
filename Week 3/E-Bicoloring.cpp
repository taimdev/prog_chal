// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 3
// Problem E - Bicoloring

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <vector>
# include <algorithm>
# include <stdlib.h>
# include <utility>
# include <queue>
# include <map>
# define SIZE 202

using namespace std;

bool seen [SIZE];
vector<int> edges[SIZE];
int color[SIZE];
bool doable;


void dfs (int u, int col) {
	if (seen [u])  {
		if (col == color[u]) {
			doable = false;
		}
		return ;
	}
	seen [u] = true;
	color[u] = -col;
	for (vector<int>::iterator it = edges[u].begin(); it != edges[u].end(); ++it) {
		dfs (*it, -col);
	}
} 
int main() {
	int nodes;
	while (cin >> nodes) {
		if (nodes == 0) {
			return 0;
		}
		int edgeno;
		cin >> edgeno;
		memset(seen, false, sizeof(seen));
		memset(color, 0, sizeof(color));
		doable = true;
		for (int j = 0; j < SIZE; j ++) {
			edges[j].clear();
		}
		//edges.clear();
		for (int i = 0; i < edgeno; ++i) {
			int v1, v2;
			cin >> v1 >> v2;
			edges[v1].push_back(v2);
		}
		dfs(0, 1);

		if (doable == false) {
			cout << "NOT BICOLORABLE." << endl;
		} else {
			cout << "BICOLORABLE." << endl;
		}
	}
	return 0;
}
