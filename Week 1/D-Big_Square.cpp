// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 1
// Problem D Herd Sums

# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <stdlib.h>
# include <math.h>
# define SIZE 102	

using namespace std;

int main() {
	// Size of grid
	int gridsize = 0;
	cin >> gridsize;

	if (gridsize == 0) {
		cout << '0'<< endl;
		return 0;
	}
	// Implement a 2d array / grid
	int gridarr[SIZE][SIZE];

	for (int y = 0; y < gridsize; y ++) {
		// init a var to store the line as an array
		char line[SIZE];
		cin >> line;
		for (int x = 0; x < gridsize; x ++) {
			if (line[x] == 'B') {
				gridarr[x][y] = -2;
			} else if (line[x] == 'J') {
				gridarr[x][y] = 1;
			} else {
				gridarr[x][y] = 0;
			}
		}
	}


	int maxarea = 0;
	for (int y0 = 0; y0 < gridsize; y0 ++) {
		for (int x0 = 0; x0 < gridsize; x0 ++) {
			for (int y1 = gridsize - 1; y1 >= y0; y1 --) {
				for (int x1 = gridsize - 1; x1 >= 0; x1 --) {
					// for every two points
					// if the area formed is larger than the old area

					if (maxarea >= ((gridsize - y0 - 1) * (gridsize - y0 - 1))) {
						cout << maxarea << endl;
						return 0;
					}
					if ((x0 == x1) && (y0 == y1)) {
						continue;
					}
					if (gridarr[x0][y0] + gridarr[x1][y1] < 1 ) {
						continue;
					}
					int newarea = int(pow(float(x0 - x1), 2) + pow(float(y0 - y1), 2))/2;
					//cout << "debug" << newarea << endl;
					//cout << '|' << x0 << y0 << '|' << x1 << y1 << '|'<< endl; 
					if (newarea > maxarea) {
						//cout << "debug" << newarea << endl;
						//cout << '|' << x0 << y0 << '|' << x1 << y1 << '|'<< endl; 
						// check if the other two points work
						// the current line is the left most line of the square

						// to find the middle points from stack overflow
						double xc, yc, xd, yd, fx2, fy2, fx3, fy3;

						xc = float(x0 + x1)/2  ;  yc = float(y0 + y1)/2  ;    // Center point
						xd = float(x0 - x1)/2  ;  yd = float(y0 - y1)/2  ;    // Half-diagonal
						//cout << xc <<endl;
						fx2 = xc - yd  ;  fy2 = yc + xd;    // Third corner
						fx3 = xc + yd  ;  fy3 = yc - xd;    // Fourth corner

						int x2, y2, x3, y3;

						x2 = fx2;
						y2 = fy2;
						x3 = fx3;
						y3 = fy3;

						if ((x2 != fx2) || (y2 != fy2) || (x3 != fx3) || (y3 != fy3)) {
							continue;
						}
						// Check validity of points
						if ((x2 >= gridsize) || (y2 >= gridsize)|| (x3 >= gridsize)||(y3 >= gridsize) 
							|| (x2 < 0) || (y2 < 0) || (x3 < 0) || (y3 < 0))  {
							continue;
						}
						if (((x0 == x2) & (y0 == y2)) || ((x0 == x3) && (y0 == y3)) || ((x1 == x2) && (y1 == y2)) || ((x1 == x3) && (y1 == y3))) {
							continue;
						}
						//cout << "debug" << newarea << endl;
						//cout << '|' << x0 << y0 << '|' << x1 << y1 << '|' << x2 << y2 << '|' << x3 << y3<< endl; 
						

						if (gridarr[x0][y0] + gridarr[x1][y1] + gridarr[x2][y2] + gridarr[x3][y3] >= 3) {
							// This means that they are either all J's or 3 J's and one asterisk
							//cout << "mid" << xc << yc << xd << yd << endl;
							//cout << "floats" << fx2 << fy2 << fx3 << fy3 << endl;
							//cout << "debug" << newarea << endl;
							//cout << '|' << x0 << y0 << '|' << x1 << y1 << '|' << x2 << y2 << '|' << x3 << y3<< endl; 
							//cout << gridarr[x0][y0] << gridarr[x1][y1] << gridarr[x2][y2] << gridarr[x3][y3]<<endl; 
							maxarea = newarea;
						}	
					}
				}
			}
		}
	}
	cout << maxarea << endl;
	
	/*for (int y = 0; y < gridsize; y ++) {
		for (int x = 0; x < gridsize; x ++) {
			cout << '('<< x<<','<<y<<')'<<gridarr[x][y];
		}
		cout << endl;
	}
	cout <<gridarr[2][4];
	*/

	return 0;



}