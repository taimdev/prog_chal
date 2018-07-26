// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 2
// Problem A Is it a Tree

# include <iostream>
# include <cstdio>
# include <vector>
# include <set>
# include <stdlib.h>
# include <cstring>
# define SIZE 1100

using namespace std;
//(&array)[rows][cols]
void dfs (int u, int (&matrix)[SIZE][SIZE], bool *seen) {
	if ( seen [u]) return ;
	seen [u] = true ;
	for (int v = 0; v < SIZE; v ++) {
		if (matrix[u][v]  == 1) { 
			//cout << "dfs from " << u <<"to" << v<< endl;
			dfs (v, matrix, seen);
		}
	} 
}
int main() {
	int v1, v2;

	bool seen [SIZE] = {false};
	int matrix[SIZE][SIZE];
	int arr[SIZE] = {0};
	int max = 0;
	int min = SIZE;
	int dataset = 0;
	set<int> vertex;
	while (cin) {
		cin >> v1 >> v2;
		if (v1 > 0) {
			// update the highest vertex number we reach as we go
			vertex.insert(v1);
			vertex.insert(v2);
			matrix[v1][v2] = 1;

			//cout << "connected" <<v1 << v2 << endl;
			if (v1 > max) {
				max = v1;
			} else if (v2 > max) {
				max = v2;
			}
			if (v1 < min) {
				min = v1;
			} else if (v2 < min) {
				min = v2;
			}
			// increment the amount of edges going into a certain vertex
			arr[v2] ++;
		} else if (v1 == 0) {
			// finished dataset
			dataset ++;
			int flag = 0;
			int root = 0;
			int rootv = 0;
			set<int>::iterator it;
			for (it = vertex.begin(); it != vertex.end(); ++ it) {
				int i = *it;
				//cout << i << endl;
				if (arr[i] > 1) {
					// more than one edge pointing to this vertex therefore not a tree
					//cout << "this vertex has mroe than one edge" << i << endl;
					flag = 1; 
					break;
				} else if (arr[i] == 0) {
					// If no edges in, it is a root 
					// this is the root vertex
					rootv = i;
					root ++;
					if (root > 1) {
						// more than one root implies somethings wrong
						//cout << "this vertex is another root" << i << endl;
						flag = 1; 
						break;
					}
				}
			}
			if (root == 0) {
				// No root found then still wrong
				flag = 1;
			} else if (root == 1) {
				dfs(rootv, matrix, seen);
				for (it = vertex.begin(); it != vertex.end(); ++ it) {
					int i = *it;
					//cout << i << endl;
					if (!seen[i]) {
						flag = 1;
					}
				}
			}
			if (vertex.empty()) {
				flag = 0;	
			}


			if (flag == 1) {
				cout << "Case "<<dataset<<" is not a tree." << endl;
			} else {
				cout << "Case "<<dataset<<" is a tree." << endl;
			}
			std::fill(arr, arr+SIZE, 0);
			std::fill(seen, seen+SIZE, 0);
			max = 0;
			min = SIZE;
			vertex.clear();
			memset(matrix, 0, sizeof(matrix[0][0]) * SIZE * SIZE);
			continue;
		} else {
			return 0 ;
		}
	}
	return 0;
}