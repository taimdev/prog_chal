// Taimur Azhar z5116684 Final Exam
// Problem E - 

#include <stdlib.h>
#include <iostream>

#define MAX 2000000000
#define N 20000

using namespace std;
typedef pair<int, int> pt;

// Index of trooper, how many outposts placed
int cache[N + 1][3][N + 1];
pt dist[N];
int predist[N];
int location[3];
int troopno;

int dp(int trop, int stat, int prev) {
   if (cache[trop][stat][prev] != -1) {
      return cache[trop][stat][prev];
   }
   if (stat < 0) {
      return MAX;
   }
   if ((trop == 1) && (stat != 0)) {
      return 0;
   }
   int add = 0;

   if (stat == 2) {
      //dist from current to end
      add = predist[trop - 1] * dist[trop - 1].first;
   } else {
      // added one or two tower, so dist to that tower
      // dist to end
      add = predist[trop - 1] * dist[trop - 1].first;
      // minus dist from tower to end
      add = add - predist[prev] * dist[trop - 1].first;
   }
   if ((trop == 1) && (stat == 0)) {
      return add;
   }

   return cache[trop][stat][prev] = min(dp(trop - 1, stat, prev) + add, dp(trop - 1, stat - 1, trop - 1));
}

int main() {
   cin >> troopno;

   for (int i = 1; i <= troopno; i ++) {
      int f, d;
      cin >> f >> d;
      pt fld(f, d);
      dist[i] = fld;
      for (int j = 1; j <= i; j ++) {
         predist[j] += fld.second;
      }
   }

   for (int i = 0; i <= N; i ++) {
      for (int j = 0; j <= 2; j ++) {
         for (int k = 0; k <= N; k ++) {
            cache[i][j][k] = -1;
         }
      }
   }
   cout << dp(troopno + 1, 2, troopno + 1) << endl;

   return 0;
}