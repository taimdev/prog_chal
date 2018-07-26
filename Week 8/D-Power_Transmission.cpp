// Taimur Azhar z5116684 Power Transmission

#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>

#define V 300
#define E 100200
#define INF 100000007

using namespace std;
/*
 * edge list representation
 */
int start[V];
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
// edges are in pairs so we can easily go between residuals & originals
int inv(int e) { return e ^ 1; }
int seen[V];
/*
 * edmonds karp
 */

int augment(int s, int t) {
  // This is a BFS, shortest path means by edge count not capacity
  queue<int> q;
  int path[V] ;//= which edge we used from to reach v
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
        //cout << "added" << e << endl;
      }
    }
  }
  if (path[t] == -1) return 0; // can't reach the sink
  int res = INF;
  //int e;
  // walk over the path backwards to find the minimum edge
  for (int e = path[t]; e != -2; e = path[to[inv(e)]]) {
    res = min(res, cap[e]);
    //cout << "res" << res << endl;
  }
  // do it again to subtract that from the capacities
  for (int e = path[t]; e != -2; e = path[to[inv(e)]]) {
    //cout << "residue" << res << endl ;
    cap[e] -= res;
    cap[inv(e)] += res;
  }
  return res;
}

int max_flow(int s, int t) {
  int res = 0;
  fill(seen, seen + V, 0);
  while (1) {
    int med = augment(s, t);
    if (med == 0) return res;
    fill(seen, seen + V, 0);
    res += med;
  }
  return res;
}



int main() {

  // Store capacity info first
  int regno;
  while(cin >> regno) {
    //cout << regno << endl;
    edge_counter = 0;
    fill(succ, succ + E, 0);
    fill(cap, cap + E, 0);
    fill(to, to + E, 0);
    fill(start, start + V, -1);
    for (int i = 1; i <= regno; i ++) {
      // reg in is i, and out is i + regno
      int cap;
      cin >> cap;
      add_edge(i, i + regno, cap);
      add_edge(i + regno, i, 0);
      //cout << i << " connected " << i + regno << " cap " << cap << endl;
      //cout << i + regno << " connected " << i  << " cap " << 0 << endl;
    }

    // Connect all the links
    int linkno;
    cin >> linkno;
    for (int i = 0; i < linkno; i ++) {
      int in, out, cap;
      // in is incremented by regno, out is the same
      cin >> in >> out >> cap;
      add_edge(in + regno, out, cap);
      add_edge(out , in + regno, 0);
      //cout << in + regno << " connected " << out << " cap " << cap << endl;
      //cout << out << " connected " << in + regno << " cap " << 0 << endl;
    }

    // Connect supersourcesink
    int B, D;
    cin >> B >> D;
    for (int i = 0; i < B + D; i ++) {
      int index;
      cin >> index;
      if (i < B) {
        // connect to source
        add_edge(0, index, INF);
        add_edge(index, 0, 0);
        //cout << 0 << " connected " << index << " cap " << INF << endl;
        //cout << index << " connected " << 0 << " cap " << 0 << endl;
      } else {
        // connect to sink
        //cout << "connected" << endl;
        add_edge(index + regno, (regno + 1) * 2, INF);
        add_edge((regno + 1) * 2, index + regno, 0);
        //cout << index + regno << " connected " << (regno + 1) * 2 << " cap " << INF << endl;
        //cout << (regno + 1) * 2 << " connected " << index + regno << " cap " << 0 << endl;
      }
    }
    //cout << "dasds" << endl;
    int ans = max_flow(0, (regno + 1) * 2);

    cout << ans << endl;
  }


  return 0;
}