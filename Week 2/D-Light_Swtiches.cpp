// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 2
// Problem D Hit the light switches
// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 2

# include <iostream>
# include <cstdio>
# include <cstring>
# include <stdlib.h>
# include <map>
# include <set>
# include <utility>
# include <algorithm>
# include <vector>
# include <stack>
# define SIZE 10010
using namespace std;


vector <int> edges[SIZE]; // each vertex has a list of connectionaryed vertices
vector <int> newedges[SIZE];
void add(int u, int v) {
	// add from u to v
	if (u != v) {
		edges[u].push_back(v);
	}
}
void new_addition_t(int u, int v) {
	// add from u to v
	if (u != v) {
		newedges[u].push_back(v);
	}
}

// we will number the vertices in the order we see them in the DFS
int dfs_index [SIZE];
// for each vertex , store the smallest number of any vertex we see
// in its DFS subtree
int lowlink [SIZE];
// explicit stack
stack <int> stacko; // # include <stack >
bool in_stack [SIZE];
// arbitrarily number the SCCs and remember which one things are in
int scc_counter ;
int which_scc [SIZE];
int counterific = 1;


void connectionary ( int v) {
	
	// set the number for this vertex
	// the smallest numbered thing it can see so far is itself
	lowlink [v] = dfs_index [v] = counterific ++;
	stacko.push (v);
	in_stack [v] = true ;
	// continued
	for (vector <int>::iterator it3 = edges[v].begin (); it3 != edges[v].end (); ++ it3) { // for each edge v -> w
		int w = *it3;
		if (! dfs_index [w]) { // w hasn ’t been visited yet
			connectionary (w);
			// if w can see something , v can too
			//cout << lowlink[w] << "lowlink1" << endl;
			lowlink [v] = min ( lowlink [v], lowlink [w]) ;
			//cout << lowlink[w] << "lowlink2" << endl;
		} else if ( in_stack [w]) {
			// w is already in the stack , but we can see it
			// this means v and w are in the same SCC
			lowlink [v] = min ( lowlink [v], dfs_index [w]) ;
		}
	}
	// v is the root of an SCC
	if ( lowlink [v] == dfs_index [v]) {
		++ scc_counter ;
		int w;
		do {
			w = stacko. top () ; stacko. pop () ;
			in_stack [w] = false ;
			which_scc [w] = scc_counter;
		} while (w != v) ;
	}
}
int main() {
	int test_cases;
	cin >> test_cases;

	for (int i = 1; i <= test_cases; i ++) {
		int lights, lines;
		cin >> lights >> lines;
		// reset the old graph

		memset(edges, 0, sizeof(edges));
		memset(newedges, 0, sizeof(newedges));
		memset(dfs_index, 0 , sizeof(dfs_index));
		memset(lowlink, 0, sizeof(lowlink));
		memset(which_scc, 0, sizeof(which_scc));
		counterific = 1;
		scc_counter = 0;
		// set to store the things
		set<int> graph;
		set<int> done;

		for (int j = 0; j < lines; j ++) {
			int v1, v2;
			cin >> v1 >> v2;
			add(v1, v2);
			graph.insert(v1);
			graph.insert(v2);	
		}
		scc_counter = 0;
		for (set<int>::iterator it1 = graph.begin(); it1 != graph.end(); ++ it1) {
			int u = *it1;
			if (! dfs_index[u]) connectionary(u);
		}

		for (set<int>::iterator it1 = graph.begin(); it1 != graph.end(); ++ it1) {
			int u = *it1;
				for (vector <int>::iterator it2 = edges[u].begin (); it2 != edges[u].end (); ++ it2) {
					int v = *it2;
					new_addition_t(which_scc[u], which_scc[v]);
				}
		}
		for (set<int>::iterator it1 = graph.begin(); it1 != graph.end(); ++ it1) {
			int u = *it1;
			for (vector <int>::iterator it2 = newedges[u].begin (); it2 != newedges[u].end (); ++ it2) {
				int v = *it2;
				done.insert(v);
				//cout << u << " edge " << v <<  endl;
			}	
		}
		int ans = scc_counter - done.size();
		//cout << "counter" << scc_counter << endl;
		//cout << "size" << done.size() << endl;
		if (lines == 0) {
			cout << "Case " << i << ": "<< lights << endl;
		} else {
			cout << "Case " << i << ": "<<ans << endl;
		}

		graph.clear();
		done.clear();
		
	}
	return 0;
}