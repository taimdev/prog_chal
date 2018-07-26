// Taimur Azhar z5116684 Power Transmission

#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define V 600
#define E 2020

using namespace std;
typedef long long ll;
ll INF = 40000010;

/*
 * edge list representation
 */
// the index of the first outgoing edge for each vertex, initialised to -1
int start[V];
int succ[E], to[E];
ll cap[E];

int edge_counter = 0;
void add_edge(int u, int v, ll c) {
  // set the properties of the new edge
  cap[edge_counter] = c, to[edge_counter] = v;
  // insert this edge at the start of u's linked list of edges
  succ[edge_counter] = start[u];
  start[u] = edge_counter;
  ++edge_counter;
}
// edges are in pairs so we can easily go between residuals & originals
int inv(int e) { return e ^ 1; }
// easily iterate through all of u's outgoing edges (~(-1) == 0)
//for (int e = start[u]; ~e; e = succ[e]) /* do something */;
/*
 * edmonds karp
 */
ll augment(int s, int t) {
  // This is a BFS, shortest path means by edge count not capacity
  queue<int> q;
  int path[V];// = which edge we used from to reach v
  fill(path, path + V, -1);
  for (q.push(s), path[s] = -2; !q.empty(); q.pop()) {
    int u = q.front();
    for (int e = start[u]; ~e; e = succ[e]) {
      // if we can use e and we haven't already visited v, do it
      if (cap[e] <= 0) continue;
      int v = to[e];
      if (path[v] == -1) {
        path[v] = e;
        q.push(v);
      }
    }
  }
  if (path[t] == -1) return 0; // can't reach the sink
  ll res = INF;
  // walk over the path backwards to find the minimum edge
  for (int e = path[t]; e != -2; e = path[to[inv(e)]])
    res = min(res, cap[e]);
  // do it again to subtract that from the capacities
  for (int e = path[t]; e != -2; e = path[to[inv(e)]]) {
    cap[e] -= res;
    cap[inv(e)] += res;
  }
  return res;
}
int seen[V];
void max_flow(int s, int t) {
  fill(seen, seen + V, 0);
  while (augment(s, t)) {
    fill(seen, seen + V, 0);
  }
 
}
/*
 * get min cut
 */
void check_reach(int u) {
  if (seen[u]) return;
  seen[u] = true;
  for (int e = start[u]; ~e; e = succ[e]) {
    if (cap[e] > 0) check_reach(to[e]);
  }
}

int main() {

  int citno, conno;
  while(1) {
    cin >> citno >> conno;
    if (citno == 0 && conno == 0) return 0;
    edge_counter = 0;
    fill(start, start + V, -1);
    fill(succ, succ + E, 0);
    fill(cap, cap + E, 0);
    fill(to, to + E, 0);

    for (int i = 0; i < conno; i ++) {
      int c1, c2;
      ll cap;
      cin >> c1 >> c2 >> cap;
      add_edge(c1, c2, cap);
      add_edge(c2, c1, 0);
      add_edge(c2, c1, cap);
      add_edge(c1, c2, 0);
    }

    /*
    vector<int> ans = min_cut(1, 2);
    //cout <<  << endl;
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it ++) {
      cout << to[*it] << " " << to[inv(*it)] << endl;
      it ++;

    }
    ans = min_cut(2, 1);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it ++) {
      cout << to[*it] << " " << to[inv(*it)] << endl;
      it ++;

    }
    */
    max_flow(1, 2);
    fill(seen, seen + V, 0);
    check_reach(1);

    for (int e = 0; e < edge_counter; e +=2) {
      if (!seen[to[e]] && seen[to[inv(e)]]) {
        //if (to[e] == 0) break;
        cout << to[e] << " " << to[inv(e)] << endl;
      }
    }
    cout << endl;

  }


  return 0;
}