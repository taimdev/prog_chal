// Taimur Azhar z5116684
// Week 5 Prog Chal
// Problem A - Piggy Bank

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <utility>
#include <string.h>

#define MAXVAL 50002
#define MAXWEIGHT 10002
#define MAXCOIN 502
#define INF 2e7

using namespace std;

int cache[MAXWEIGHT][MAXCOIN];
pair <int, int> mapping[MAXCOIN];
int itemlim;


int f(int curr_weight, int item) {
	//cout << " current length is " << curr_weight << " up to item " << item << endl;  
	if (curr_weight < 0) {
		//cout << "overshot" << endl; 
		return INF;
	}
	if ((item >= itemlim) && (curr_weight != 0)) {
		//cout << " reached itemlim without low weight" << endl;
		return INF;
	}
	if (curr_weight == 0) {
		//cout << "perfect" << endl;
		return 0;
	}

	if (cache[curr_weight][item] != -1)  {
		//cout << "returning cache" << endl;
		//cout << " cachce is " << cache[curr_weight] << endl;
		return cache[curr_weight][item];
	}
	int w, v;
	w = mapping[item].second;
	v = mapping[item].first;
	return cache[curr_weight][item] = min(f(curr_weight - w, item) + v, f(curr_weight, item + 1));
} 

int main() {
	int test_cases;
	cin >> test_cases;

	for (int i = 0; i < test_cases; ++i) {
		int pig_w, coin_pig_w;
		cin >> pig_w >> coin_pig_w;
		int coin_w = coin_pig_w - pig_w;

		int coinno;
		cin >> coinno;
		for (int i = 0; i < coinno; ++i) {
			int val, weight;
			cin >> val >> weight;
			mapping[i] = make_pair(val, weight);
			//cout << "the weight is " << mapping[i].second << endl;
		}
		itemlim = coinno;
		for (int i = 0; i <= coin_w; ++i) {
			for (int j = 0; j <= coinno; ++j) {
				cache[i][j] = -1;
			}
		}
		int ans = f(coin_w, 0);

		if (ans == INF) {
			cout << "This is impossible." << endl;
		} else {
			printf("The minimum amount of money in the piggy-bank is %d.\n",ans);
		}

	}
	return 0;
}