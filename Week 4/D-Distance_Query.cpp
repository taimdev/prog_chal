// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 4
// Problem D Distance Query

# include <iostream>
# include <cstdio>
# include <stdlib.h>
# include <cmath>
# include <utility>
# include <string>
# include <vector>
# define CSIZE 100002
# define KTHPWR 17
# define RSIZE 1000002

using namespace std;


int parent[CSIZE][KTHPWR];
int min_dist[CSIZE][KTHPWR];
int max_dist[CSIZE][KTHPWR];
int depth[CSIZE];
vector <pair<int, int> > edges[CSIZE];

int logof2(int x) {
	if (x == 0) {
		return 0;
	} else {
		return log2(x);
	}
}

void make_tree(int root, int depthno) {
	depth[root] = depthno;
	//cout << "depth of " << root << " is currently " << depthno << endl;
	for (vector<pair<int, int> >::iterator it = edges[root].begin(); it != edges[root].end(); ++it) {
		int leaf = it->first;
		int dist = it->second;
		//remove from edges[leaf], pair(root, dist);
		for (vector<pair<int, int> >::iterator it1 = edges[leaf].begin(); it1 != edges[leaf].end(); ++it1) {
			if (it1->first == root) {
				// Then it is the point pointing back to the root and remove
				edges[leaf].erase(it1);
				break;
			}
		}
		parent[leaf][0] = root;
		min_dist[leaf][0] = dist;
		max_dist[leaf][0] = dist; 
		make_tree(leaf, depthno + 1);
		//cout << "made " << root << " root of " << leaf << endl;
	}
}
int lca (int u, int v) {
	// make sure u is deeper than v
	if ( depth [u] < depth [v]) swap (u,v);
	// log [i] holds the largest k such that 2^k <= i
	for (int i = logof2(depth [u]); i >= 0; i --) {
		// repeatedly raise u by the largest possible power of two until it is the same depth as v
		if ( depth [u] - (1 << i) >= depth [v]) {
			u = parent [u][i];
		}
	}
	if (u == v) return u;
	for (int i = logof2(depth[u]); i >= 0; i --)
		if ( parent [u][i] != -1 && parent [u][i] != parent [v][i]) {
			// raise u and v as much as possible without having them coincide
			// this is important because we ’re looking for the lowest common ancestor , not just any
			u = parent [u][i];
			v = parent [v][i];
	}
	// u and v are now distinct but have the same parent , and that parent is the LCA
	return parent [u][0];
}
int minval(int u, int v) {
	int smol = RSIZE;
	//cout << logof2(depth[u]) << " log of depth "<< depth[u] << " and " << u << endl;
	for (int i = logof2(depth[u]); i >= 0; i --) {
			//cout << "sad " << endl;
		// repeatedly raise u by the largest possible power of two until it is the same depth as v
		if ( depth[u] - (1 << i) >= depth[v]) {
			//cout << min_dist[u][i] << " is the min" << endl;
			smol = min(smol, min_dist[u][i]);
			u = parent [u][i];
		}
	}
	return smol;
}
int maxval(int u, int v) {
	int larg = 0;
	for (int i = int(log2(depth[u])); i >= 0; i --) {
		// repeatedly raise u by the largest possible power of two until it is the same depth as v
		if ( depth[u] - (1 << i) >= depth[v]) {
			larg = max(larg, max_dist[u][i]);
			u = parent [u][i];
		}
	}
	return larg;
}

int main() {
	// An array of a vector of pairs
	int cities;
	cin >> cities;
	for (int i = 0; i < cities - 1; ++i) {
		int v1, v2, dist;
		cin >> v1 >> v2 >> dist;
		//cout << v1 << v2 << dist << endl;
		edges[v1].push_back(make_pair(v2, dist));
		edges[v2].push_back(make_pair(v1, dist));
	}
	for (int i = 1; i <= cities; i ++) {
		// assume parent [i ][0] ( the parent of i) is already filled in
		for (int j = 1; (1 << j) < cities; j ++) {
			parent [i][j] = -1;
			min_dist[i][j] = 3;
			max_dist[i][j] = 2;
		}
	}
	parent[1][0] = 1;
	min_dist[1][0] = RSIZE;
	max_dist[1][0] = 0;
	//cout << "hello" << endl;
	make_tree(1,0);
	//cout << "goodbye" << endl;

	// fill in the parent for each power of two up to n
	for (int j = 1; (1 << j) < cities; j ++) {
		for (int i = 1; i <= cities; i ++) {
			if ( parent [i][j -1] != -1) {
				// the 2^j- th parent is the 2^(j -1) -th parent of the 2^(j -1) -
				parent [i][j] = parent [parent[i][j -1] ][j -1];
				min_dist[i][j] = min(min_dist[parent[i][j-1]][j-1], min_dist[i][j-1]);
				max_dist [i][j] = max(max_dist[parent[i][j-1]][j-1], max_dist[i][j - 1]);
				//printf("%d's 2 to the %d th parent is now %d\n",i, j, parent[i][j]);
			}
		} 	
	}
	int queries;
	cin >> queries;
	for (int i = 0; i < queries; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		int lcaval = lca(v1, v2);
		int smol, larg;
		smol = min(minval(v1, lcaval), minval(v2, lcaval));
		larg = max(maxval(v1, lcaval), maxval(v2, lcaval));
		cout << smol << " " << larg << endl;

	}
}