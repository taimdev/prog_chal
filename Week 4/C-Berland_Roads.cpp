// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 4
// Problem 5 Ancient Berland Roads

# include <iostream>
# include <cstdio>
# include <stdlib.h>
# include <string.h>
# include <cmath>
# include <utility>
# include <string>
# include <vector>
# include <stack>
# include <iterator>
# include <set>
# define SIZE 500000

typedef long long ll;

using namespace std;
struct query_type {
	char type;
	ll arg1;
	ll arg2;
};

std::vector<ll> edges[SIZE];
ll populations[SIZE];
pair <ll, ll> roads[SIZE];
stack <query_type> query_s;
ll seen[SIZE];
ll region[SIZE];
std::multiset<ll> regionpop;
ll exist[SIZE];

ll parent[SIZE];
ll subtree_size[SIZE];

void init (ll n) {
	for (ll i = 1; i <= n; i ++) {
		parent [i] = i; subtree_size [i] = 1;
	}
}
ll root ( ll x) {
	// only roots are their own parents
	// otherwise apply path compression
	return parent [x] == x ? x : parent [x] = root ( parent [x]) ;
}
void join ( ll x, ll y) {
	// size heuristic
	// hang smaller subtree under root of larger subtree
	x = root (x); y = root (y) ;
	if (x == y) return ;
	regionpop.erase(regionpop.find(region[x]));
    regionpop.erase(regionpop.find(region[y]));
    region[x] += region[y];
    parent[y] = x;
    regionpop.insert(region[x]);
}
void bfs(ll root) {
	//cout << "root is " << root << endl;
	seen[root] = 1;
	for (vector<ll>::iterator it = edges[root].begin(); it != edges[root].end(); it++) {
		//cout << " currently at " << root << " gonna go to " << *it << endl;
		join(root, *it);
		if (seen[*it] == 0) {
			bfs(*it);
		}
	}
}

int main() {
	ll cityno, roadno, queryno;
	cin >> cityno >> roadno >> queryno;

	for (ll i = 1; i <= cityno; ++i) {
		ll pop;
		cin >> pop;
		populations[i] = pop;
	}
	for (ll i = 1; i <= roadno; ++i) {
		ll v1, v2;
		cin >> v1 >> v2;
		roads[i] = make_pair(v1, v2);
		exist[i] = 1;
	}
	for (ll i = 1; i <= queryno; ++i) {
		char type;
		cin >> type;
		if (type == 'P') {
			// populations Update
			ll city, newpop;
			cin >> city >> newpop;
			query_type newq = {type, city, populations[city]};
			populations[city] = newpop;
			query_s.push(newq);
		} else {
			// Destroy Road
			ll road;
			cin >> road;
			exist[road] = 0;
			pair <ll, ll> edge = roads[road];
			query_type newq = {type, road, 0};
			query_s.push(newq);
		}
	}
	// At the final stage now,
	// Lets build back up to the solution fuck me
	vector<ll> solution;
	init(cityno);
	// bfs, union find, calculate max region repeat
	//region = {0}
	memset(seen, 0, sizeof(seen));
	//memset(region, 0, sizeof(region));
	copy(begin(populations), end(populations), begin(region));

	for(ll i = 1; i <= cityno; ++i) regionpop.insert(region[i]);

    for (ll i = 1;i <= roadno ;++i){
        if (exist[i] == 1) join(roads[i].first, roads[i].second);
    }

	solution.push_back(*regionpop.rbegin());
	ll counter = 1;
	while (!query_s.empty() && counter != queryno) {
		counter ++;
		query_type curr = query_s.top();
		//cout << "/////////////////////////////////////// Up to the counter " << counter << endl;
		if (curr.type == 'P') {
			//cout << "Population update " << curr.arg1 << " " <<  curr.arg2 << endl;
			regionpop.erase(regionpop.find(region[root(curr.arg1)]));
			region[root(curr.arg1)] += curr.arg2 - populations[curr.arg1];
			populations[curr.arg1] = curr.arg2;
			regionpop.insert(region[root(curr.arg1)]);

		} else {
			//cout << "Road update " << curr.arg1 << endl;
			edges[roads[curr.arg1].first].push_back(roads[curr.arg1].second);
			edges[roads[curr.arg1].second].push_back(roads[curr.arg1].first);
			join(roads[curr.arg1].first, roads[curr.arg1].second);
			// JOINING THE ACTUAL NODES THEMSELVES IS NOT ENOUGH, SOMEHOW HAVE TO JOIN EVERYTHING IDK
		}

		solution.push_back(*regionpop.rbegin());
		query_s.pop();
	}
	for (vector<ll>::reverse_iterator it = solution.rbegin(); it != solution.rend(); ++it)  {
		cout << *it << endl;
	}

}
