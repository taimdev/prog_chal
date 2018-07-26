// Taimur Azhar z5116684 Final Exam
// Problem A - 

#include <stdlib.h>
#include <iostream>
#include <string.h>

#define V 2007
#define E 1000007

using namespace std;

// the index of the first outgoing edge for each vertex, initialised to -1
int start[V];
//fill(start, start + V, -1);

// if e is an outgoing edge from u, succ[e] is another one, or -1
// cap[e] is the capacity/weight of the e
// to[e] is the destination vertex of e
int succ[E], cap[E], to[E];

int edge_counter = 0;
void add_edge(int u, int v, int c) {
   // set the properties of the new edge
   cap[edge_counter] = c, to[edge_counter] = v;
   // insert this edge at the start of u's linked list of edges
   succ[edge_counter] = start[u];
   start[u] = edge_counter;
   ++edge_counter;
}
// easily iterate through all of u's outgoing edges (~(-1) == 0)
//for (int e = start[u]; ~e; e = succ[e]) /* do something */;
/*
 * ford fulkerson
 */

// assumes the residual graph is constructed as in the previous section

int seen[V];

int inv(int e) { return e ^ 1; }

bool augment(int u, int t, int f) {
   if (u == t) return true;                     // the path is empty!
   if (seen[u]) return false;
   seen[u] = true;
   for (int e = start[u]; ~e; e = succ[e]) {
      if (cap[e] >= f && augment(to[e], t, f)) { // if we can reach the end,
         cap[e] -= f;                             // use this edge
         cap[inv(e)] += f;                        // allow "cancelling out"
         return true;
      }
   }
   return false;
}

int max_flow(int s, int t) {
   int res = 0;
   fill(seen, seen + V, 0);
   while (augment(s, t, 1)) {
   	fill(seen, seen + V, 0);
      res += 1;
   }
   return res;
}
int main() {
	int csnum, sengnum;
	cin >> csnum >> sengnum;
	int source = 0;
	int sink = csnum + sengnum + 1;

memset(start, -1, sizeof(start));
	for (int i = 1; i <= csnum; i ++) {
   	int ass;
   	cin >> ass;
   	// Source is zero, connect to all cs
   	add_edge(source, i, ass);
   	add_edge(i, source, 0);	
   	//cout << "connnected " << source << " to " << i << " for " << ass << endl;	
	}
	for (int i = 1; i <= sengnum; i ++) {
   	int ass;
   	cin >> ass;
   	// Source is zero, connect to all seng
   	add_edge(i + csnum, sink, ass);
   	add_edge(sink, i + csnum, 0);	
   	//cout << "connnected " << i + csnum << " to " << sink << " for " << ass << endl;	
	}

	for (int i = 1; i <= csnum; i ++) {
		int conns;
		cin >> conns;
		for (int j = 0; j < conns; j ++) {
			int sengstu;
			cin >> sengstu;
			add_edge(i, sengstu + csnum, 1);
   		add_edge(sengstu + csnum, i, 0);
   		//cout << "connnected " << i << " to " << sengstu + csnum << " for " << 1 << endl;	
	
		}
	}

	cout << max_flow(source, sink) << endl;



   return 0;
}