// Taimur Azhar z5116684 Oil Spill

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define LIM 1010
#define GRID 610

using namespace std;

char map[GRID][GRID];
int flow[GRID][GRID];
int graph[LIM][LIM];
int path[LIM];
bool seen[LIM];
int spills;

bool dfs(int u) {
   for (int v = 0; v < spills; v++) {
      if ((graph[u][v]) && (!seen[v])) {
         seen[v]=true;
         if ((path[v]==-1) || (dfs(path[v]))) {
             path[v] = u;
             return true;
         }    
      }  
   }
   return false;  
}   

int max_flow() {
   int res = 0;
   memset(path,-1,sizeof(path));

   for (int u = 0; u < spills; u ++){
      memset(seen, 0, sizeof(seen));
      if (dfs(u)) res++;
   } 
   return res;   
}  

int main() {
   int testCases;
   cin >> testCases;
   for (int caseNo = 1; caseNo <= testCases; caseNo ++) {
      int gsize;
      cin >> gsize;
       
      int spillno=0;
      for (int i = 0; i < gsize; i ++) {
         scanf("%s",&map[i]);
         for (int j = 0; j < gsize; j++) {
            if (map[i][j]=='#') flow[i][j] = spillno ++;
         }
      }   

      memset(graph,0,sizeof(graph));

      spills = spillno;
      for (int i = 0; i < gsize; i ++) {
         for (int j = 0; j < gsize; j ++) {
            if (map[i][j]!='#') continue;
            // check up left right down
            if ((i > 0) && (map[i - 1][j] == '#')) {
              graph[flow[i][j]][flow[i - 1][j]] = 1;
            }
            if ((i < gsize - 1) && (map[i + 1][j] == '#')) {
              graph[flow[i][j]][flow[i + 1][j]] = 1;
            }
            if ((j > 0) && (map[i][j - 1] == '#')) {
              graph[flow[i][j]][flow[i][j - 1]] = 1;
            }
            if ((j < gsize -1) && (map[i][j + 1] == '#')) {
              graph[flow[i][j]][flow[i][j + 1]] = 1;
            }
         } 
      }    
        
      int res=max_flow();
      cout << "Case " << caseNo << ": " << res / 2 << endl;
   }    
   return 0;
}    