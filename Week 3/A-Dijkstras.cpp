// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 3
// Problem A Dijkstras?

# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <stdlib.h>
# include <utility>
# include <queue>
# define SIZE 100000
using namespace std;

typedef pair<int, int> edge; //(distance, vertex)

priority_queue <edge , vector <edge> , greater <edge> > pq;

int main() {
	int vno, eno;
	cin >> vno >> eno;
	//cout << vno << eno << endl;
	// Adjancency List, array of vectors of pairs
	vector<edge> edges[vno + 2];
	/*
	int matrix[vno + 2][vno + 2];

	for (int k = 0; k < vno + 2; k ++) {
		for (int j = 0; j < vno + 2; j ++ ) {
			matrix[k][j] = 0;
		}
	}
	*/

	for (int i = 0; i < eno; i ++) {
		int v1, v2, dist;
		cin >> v1 >> v2 >> dist;
		//cout << v1 << v2 << dist << endl;
		// Make the graph
		edges[v1].push_back(make_pair(dist, v2));
		edges[v2].push_back(make_pair(dist, v1));
		//matrix[v1][v2] = dist;
		//matrix[v2][v1] = dist;
	}
	
	int dist[vno + 2] = {0};
	bool seen[vno + 2] = {false};
	int prev[vno + 2] = {0};
	//cout << "the prev of " << 1 << " is " << prev[1] << endl;
	bool toggle = false;
	// put the source s in the queue
	pq.push(edge (0 , 1)) ;
	while (! pq.empty()) {
		// choose (d, v) so that d is minimal ,
		// i.e. the closest unvisited vertex
		edge cur = pq.top();
		pq.pop();
		int v = cur.second , d = cur.first ;

		if (seen[v]) continue ;
		dist[v] = d;
		seen[v] = true ;
		if (v == vno) {
			toggle = true;
			break;
		}
		// relax all edges from v
		for (vector<edge>::iterator it = edges[v].begin(); it != edges[v].end(); ++ it) {
			edge next = *it;
			int u = next.second , weight = next.first ;
			if (! seen[u]) {
				pq.push( edge (d + weight , u));

				//cout << "before change the prev of " << u << " is " << prev[u] << endl;
				if (prev[u] != 0) {
					// If something exists, we have to keep the 
					// parent which has the smallest distance
					//cout << u << "has a prev," << prev[u] <<  endl;
					int dister = 0;
					for (vector<edge>::iterator it1 = edges[prev[u]].begin(); it1 != edges[prev[u]].end(); ++ it1) {
						edge chek = *it1;
						if (chek.second == u) {
							dister = chek.first;
							break;
						}
					} 
					int first = dist[prev[u]] + dister;
					int last = d + weight;
					//if (((dist[prev[u]] + matrix[prev[u]][v])) > (d + weight))  {
					if (first > last) {
						//cout << dist[prev[u]] << " + " << matrix[prev[u]][u] << "great than" << d <<" + " << weight<< endl;
						prev[u] = v;
					} else {
						//cout << dist[prev[u]] << " + " << matrix[prev[u]][u] << "less than" << d <<" + " << weight<< endl;
						//cout << matrix[prev[u]][v] << "less than" << last << endl;
					}
				} else {
					// if nothing exists, this objects prev is old thing
				//	cout << u << "did not have a prev and was inited" << endl;
					prev[u] = v;
				}
				//cout << "the prev of " << u << " is " << prev[u] << endl;
			} 
		}
	}
	if (toggle == true) {
		int curr = vno;
		std::vector<int> final;
		final.push_back(vno);
		//cout << vno << endl;
		//int x = prev[2];
		//cout << "the prev of " << 1 << " is " << prev[2] << endl;
		//cout << "dist is " << dist[curr] << endl;
		while (prev[curr] != 0) {
			//cout << "second time the prev of " << curr << " is " << prev[curr] << endl;
			final.push_back(prev[curr]);
			curr = prev[curr];
			//cout << curr << " " ;
		}
		//cout << endl;
		for (vector<int>::reverse_iterator rit = final.rbegin(); rit != final.rend(); ++ rit) {
			//if (*it != 0) {
				cout << *rit << ' ';
			//}

		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}

