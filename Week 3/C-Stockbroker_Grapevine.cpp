// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 3
// Problem C Stockbroker Grapevine

# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <stdlib.h>
# include <utility>
# include <queue>
# include <map>
# define SIZE 100000
using namespace std;

typedef pair<int, int> edge; //(distance, vertex)

int main() {
	int brokers;
	while (cin >> brokers) {
		if (brokers == 0) {	
			return 0;
		}
		long dist[brokers + 1][brokers + 1];
		for (int u = 1; u < brokers + 1; ++u) for ( int v = 0; v < brokers + 1; ++v) {
			dist [u][v] = 2e9;
			//cout << "value " << dist[u][v] << endl;
		}
		for (int i = 1; i < brokers + 1; i ++) {
			int connections;
			cin >> connections;
			for (int j = 0; j < connections; j ++) {
				int connection, time;
				cin >> connection >> time;
				dist[i][connection] = time;
				//cout << "connected" << i << connection << " for " << time << endl;
			}
		}
		for (int u = 1; u < brokers + 1; ++u) dist [u][u] = 0;
		for (int i = 1; i < brokers + 1; i++) {
			for (int u = 1; u < brokers + 1; u ++) {
				for (int v = 1; v < brokers + 1; v ++) {
					// dist [u ][v] is the length of the shortest path from u to v
					// using only 0 to i -1 as intermediate vertices
					// now that we ’re allowed to also use i, the only new path that
					// could be shorter is u -> i -> v
					//cout << "old" << dist[u][v] << "option" << dist[u][i] << " + " << dist[i][v];
					dist [u][v] = min ( dist [u][v] , dist [u][i] + dist [i][v]) ;
					//cout << "new " << dist[u][v] << endl;
				}
			}
		}		
		map<long, int> best_person;
		for (int u = 1; u < brokers + 1; u ++) {
			long curr_max = 0;
			for (int v = 1; v < brokers + 1; v ++) {
				// dist [u ][v] is the length of the shortest path from u to v
				// using only 0 to i -1 as intermediate vertices
				// now that we ’re allowed to also use i, the only new path that
				// could be shorter is u -> i -> v
				//dist [u][v] = min ( dist [u][v] , dist [u][i] + dist [i][v]) ;
			//	cout << "distance for " << u << v << " is " << dist[u][v] << endl;
				if (dist[u][v] > curr_max) {
					curr_max = dist[u][v];
				}
			}
			//cout << "current max " << curr_max << " for " << u << endl;
			best_person.insert(make_pair(curr_max, u));
		}
		map<long, int>::iterator it = best_person.begin();
		if (it->first != 2e9) {
			cout << it->second <<' '<< it->first << endl;
		} else {
			cout << "disjoint" << endl;
		}
	}
	return 0;
}