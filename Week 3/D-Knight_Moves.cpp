// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 3
// Problem D Knight Moves

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
# define SIZE 100000
using namespace std;

typedef pair<int, string> edge; //(distance, vertex)
string int_to_char(int i) {
	string letter;
	if (i == 1) {
		letter = 'a';
	} else if (i == 2)  {
		letter = 'b';
	} else if (i == 3)  {
		letter = 'c';	
	} else if (i == 4)  {
		letter = 'd';
	} else if (i == 5)  {
		letter = 'e';
	} else if (i == 6)  {
		letter = 'f';
	} else if (i == 7)  {
		letter = 'g';
	} else if (i == 8)  {
		letter = 'h';
	}
	return letter;
}
int main() {
	std::map<string, vector<string> > edges;
	string letter1;
	string letter2;
	for (int y = 1; y < 9; y ++) {
		for (int x = 1; x < 9; x ++) {
			letter1 = int_to_char(x);
			char c [2];
			sprintf(c,"%d",y);
			string m1 = letter1 + c;
			if ((x + 1 < 9) && (y - 2 > 0)) {
				letter1 = int_to_char(x + 1);
				sprintf(c,"%d",y - 2);
				string m2 = letter1 + c;
				edges[m1].push_back(m2);
			} if ((x + 2 < 9) && (y - 1 > 0)) {
				letter1 = int_to_char(x + 2);
				sprintf(c,"%d",y - 1);
				string m2 = letter1 + c;
				edges[m1].push_back(m2);
			} if ((x + 1 < 9) && (y + 2 < 9)) {
				letter1 = int_to_char(x + 1);
				sprintf(c,"%d",y + 2);
				string m2 = letter1 + c;
				edges[m1].push_back(m2);
			} if ((x + 2 < 9) && (y + 1 < 9)) {
				letter1 = int_to_char(x + 2);
				sprintf(c,"%d",y + 1);
				string m2 = letter1 + c;
				edges[m1].push_back(m2);	
			} if ((x - 1 > 0) && (y - 2 > 0)) {
				letter1 = int_to_char(x - 1);
				sprintf(c,"%d",y - 2);
				string m2 = letter1 + c;
				edges[m1].push_back(m2);	
			} if ((x - 2 > 0) && (y - 1 > 0)) {
				letter1 = int_to_char(x - 2);
				sprintf(c,"%d",y - 1);
				string m2 = letter1 + c;
				edges[m1].push_back(m2);	
			} if ((x - 1 > 0) && (y + 2 < 9)) {
				letter1 = int_to_char(x - 1);
				sprintf(c,"%d",y + 2);
				string m2 = letter1 + c;
				edges[m1].push_back(m2);	
			} if ((x - 2 > 0) && (y + 1 < 9)) {
				letter1 = int_to_char(x - 2);
				sprintf(c,"%d",y + 1);
				string m2 = letter1 + c;
				edges[m1].push_back(m2);	
			}
		} 
	}
	string start, end;
	while (cin >> start >> end) {
		//cout << start << end << endl;

		priority_queue <edge , vector <edge>, greater <edge> > pq;
		map<string, int> dist;
		map<string, bool> seen;
		dist.clear();
		seen.clear();
		// put the source s in the queue
		//cout << start << "is start" << endl;
		pq.push(edge(0, start));
		//cout << v << "is queue" << endl;
		while (!pq.empty() ) {
			// choose (d, v) so that d is minimal ,
			// i.e. the closest unvisited vertex
			edge v = pq.top () ;
			pq.pop() ;
			if (seen.find(v.second) != seen.end()) continue ;
			dist[v.second] = v.first;
			//cout << "dist updated for " << v.second << " to " << dist[v.second] << endl;
			seen[v.second] = true ;
			//if 
			if (v.second == end) {
				cout << "To get from " << start << " to " << end << " takes " << dist[v.second] <<" knight moves."<< endl;
				break;
			}
			// relax all edges from v.second
			for (vector<string>::iterator it = edges[v.second].begin(); it != edges[v.second].end(); ++ it) {
				string u = *it;
				//string u = next;
				
				if (seen.find(u) == seen.end()) {
					pq.push(edge(1 + dist[v.second], u));
					//cout << "pushed " << u <<" from  " << v.second << " at cost " << dist[v.second] << endl;
				}
			}
		}
	}

}



