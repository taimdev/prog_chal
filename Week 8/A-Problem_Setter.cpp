// Taimur Azhar z5116684 Problem Setter

#include <stdlib.h>
#include <iostream>
#include <algorithm>

#define V 1030
#define E 30010

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

bool augment(int u, int t, int f) {
  if (u == t) return true;                     // the path is empty!
  if (seen[u]) return false;
  seen[u] = true;
  for (int e = start[u]; ~e; e = succ[e])
    if (cap[e] >= f && augment(to[e], t, f)) { // if we can reach the end,
      cap[e] -= f;                             // use this edge
      cap[inv(e)] += f;                        // allow "cancelling out"
      return true;
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
  int cno, pno;
  while (cin >> cno >> pno) {
    edge_counter = 0;
    succ[E] = {0};
    cap[E] = {0};
    to[E] = {0};
    seen[V] = {0};
    if ((cno == 0) && (pno == 0)) {
      break;
    }
    int qnum = 0;
    fill(start, start + V, -1);
    for (int i = 1; i <= cno; i++) {
        int catcap;
        cin >> catcap;
        qnum += catcap;
        add_edge(0, i, catcap);
        add_edge(i, 0, 0);
        //cout << "connecting " << 0 << " to " << i << " at " << catcap << endl;
    }
    for (int i = cno + 1; i <= cno + pno; i ++) {
        int catno;
        cin >> catno;
        for (int j = 0; j < catno; j ++) {
            int cat;
            cin >> cat;
            add_edge(i, cat, 0);
            add_edge(cat, i, 1);
            //cout << "connecting " << i << " to " << cat << " at " << 0 <<  endl;
        }
        add_edge(i, cno + pno + 1, 1);
        add_edge(cno + pno + 1, i , 0);
    }
    //cout << "qnu" << qnum << endl;
    if (qnum == max_flow(0, cno + pno + 1) ) {
      cout << "1" << endl;
      for (int i = 1; i <= cno; i++) {
        for (int e = start[i]; ~e; e = succ[e]) {
          if (cap[e] == 0) {
            int ans = to[e] - cno;
            cout <<  ans << " " ;
          }
        }
        cout << endl;
      }
    } else {
      cout << "0" << endl;
    }
  }

  return 0;
}