// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 3
// Problem B Haunted Graveyard

# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>
# include <stdlib.h>
# include <utility>
# include <queue>
# include <map>
# define INF 100000

using namespace std;

typedef pair<int, int> coord;

struct edge {
	coord u, v;
	int w;
	edge ( coord _u , coord _v , int _w) : u(_u) , v(_v) , w(_w) {}
};
map <coord, int> dist;
vector <edge> edges ;

// global relaxation : try to relax every edge in the graph
bool relax () {
	bool relaxed = false ;
	for (vector<edge>::iterator it = edges.begin() ; it != edges.end () ; ++it) {
		edge e = *it;
	// we don ’t want to relax an edge from an unreachable vertex
		if (dist.find(e.v) == dist.end()) {
			if (dist.find(e.u) != dist.end()) {
				dist[e.v] = dist[e.u] + e.w;
				relaxed = true;
				//cout << "dist init for " << e.v.first << e.v.second << " to " << e.w << endl;
			}
		} else  if (dist[e.v] > dist[e.u] + e.w) {
			relaxed = true ;
			dist [e.v] = dist [e.u] + e.w;
			//cout << "dist ichanged for " << e.v.first << e.v.second << " to " << e.w << endl;
		}
	}
	return relaxed ; // did this relaxation result in any improvements ?
}
// puts distances from source (n -1) in dist , returns the list of
//vertices for which dist is wrong due to negative cycles
// only detects negative cycles which are REACHABLE from the source
// to detect all negative cycles , make everything reachable by adding
//0 - weight edges from the source

bool check_neg_cycle (int vertices) {
	//fill (dist.begin () , dist.end () , INF);
	// |V| -1 global relaxations
	dist[make_pair(0,0)] = 0;
	for (int i = 0; i < vertices - 1; i ++)  {
		bool cut_early = relax();
		if (cut_early == false) {
			return false;
		}
	}
	queue <coord> q;
	map<coord, bool> seen;
	seen.clear();
	//q.pop_all();
	// any edges that can be relaxed further are part of negative cycles
	for (vector<edge>::iterator it = edges.begin () ; it != edges.end () ; ++it) {
		// don ’t duplicate the vertices that we put in the queue
		edge e = *it;
		if ((dist.find(e.v) != dist.end()) && ! seen[e.v] && dist[e.v] > dist[e.u] + e.w) {
			return true;
		}
	}
	return false;
}

int main() {
	int width, height;
	while (cin >> width >> height) {
		if ((width == 0) && (height == 0)) {
			break;
		}
		int graveno = 0;
		cin >> graveno;
		map<coord, int> tombstone;
		//memset(edges, 0, sizeof(edges));
		//memset(dist, INF, sizeof(dist));
		dist.clear();
		edges.clear();
		tombstone.clear();
		for (int i = 0; i < graveno; i ++) {
			int gx, gy;
			cin >> gx >> gy;
			tombstone.insert(pair<coord, int>(make_pair(gx, gy), 1));
			//tombstone[make_pair(gx,gy)] = 1;
		//	cout << gx << gy << endl;
		}
		//cout <<"fin"<< endl;
		int holeno;
		cin >> holeno;
		for (int i = 0; i < holeno; i ++) {
			int x1, y1, x2, y2, dist;
			cin >> x1 >> y1 >> x2 >> y2 >> dist;
			edge holeedge = edge(make_pair(x1, y1), make_pair(x2, y2), dist);
			edges.push_back(holeedge);
			//cout << "magic hole" << x1 << y1 << x2 << y2 << dist << endl;
		}
		for (int y = 0; y < height; y ++) {
			for (int x = 0; x < width; x ++) {
				coord curr = make_pair(x, y);
				if (tombstone.find(curr) != tombstone.end()) {
					//cout << "rip" <<curr.first << curr.second << endl;
					continue;
				} else {
					// sanity check if right and top are doable
					if ((x + 1) < width) {
						// in bounds
						coord next = make_pair(x + 1, y);
						if (tombstone.find(next) != tombstone.end()) {
							//cout << "normal" <<next.first << next.second << endl;
							continue;
						} else {
							// good connection
							edge connect1 = edge(make_pair(x, y), make_pair(x + 1, y), 1);
							//edge connect2 = edge(make_pair(x + 1, y), make_pair(x, y), 1);
							edges.push_back(connect1);
							//edges.push_back(connect2);
						}

					}
					if ((y + 1) < height) {
						// in bounds
						coord next = make_pair(x, y + 1);
						if (tombstone.find(next) != tombstone.end()) {
							//cout << "normal" <<next.first << next.second << endl;
							continue;
						} else {
							// good connection
							edge connect1 = edge(make_pair(x, y), make_pair(x, y + 1), 1);
							edge connect2 = edge(make_pair(x, y + 1), make_pair(x, y), 1);
							edges.push_back(connect1);
							edges.push_back(connect2);
						}
					}
				}
			}
		}
		if (check_neg_cycle(width * height)) {
			cout << "Never" << endl;
		} else {
			if (dist.find(make_pair(width - 1, height - 1)) != dist.end()) {
				//cout << "dist" << endl;
				cout << dist[make_pair(width - 1, height - 1)] << endl;
			} else {
				cout << "Impossible" << endl;
			}
		}
		//cout << "done" << endl;

	}
}



