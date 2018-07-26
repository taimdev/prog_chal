// Taimur Azhar z5116684 Collectors Problem

#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
  
using namespace std;
  
#define INF 1e9;
#define N = 10010;

struct Edge{
  int to,nxt,c;
}e[N];
int q[500100],head[N],cur[N],dis[N],cnt[50][50];
int L,R,S,T,tot = 1;

inline char nc() {
  static char buf[100000],*p1 = buf,*p2 = buf;
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read() {
  int x = 0,f = 1;char ch = nc();
  for (; ch<'0'||ch>'9'; ch = nc()) if (ch=='-') f = -1;
for (; ch>='0'&&ch<='9'; ch = nc()) x = x * 10 + ch - '0';
  return x * f;
}
inline void init() {
  tot = 1;memset(head,0,sizeof(head));
memset(cnt,0,sizeof(cnt));
}
inline void add_edge(int u,int v,int w) {
 e[++tot].to = v,e[tot].c = w,e[tot].nxt = head[u],head[u] = tot;
  e[++tot].to = u,e[tot].c = 0,e[tot].nxt = head[v],head[v] = tot;
}
bool bfs() {
  for (int i=1; i<=T; ++i) {
      cur[i] = head[i];dis[i] = -1;
  }
  L = 1;R = 0;
  q[++R] = S;
  dis[S] = 0;
  while (L <= R) {
      int u = q[L++];
      for (int i=head[u]; i; i=e[i].nxt) {
          int v = e[i].to,c = e[i].c;
          if (dis[v]==-1&&c>0) {
              dis[v] = dis[u] + 1;
              q[++R] = v;
              if (v==T) return true;
          }
      }
  }
  return false;
}
int dfs(int u,int flow) {
  if (u==T) return flow;
  int used = 0;
for (int &i=cur[u]; i; i=e[i].nxt) {
    int v = e[i].to,c = e[i].c;
      if (dis[v]==dis[u]+1 && c>0) {
          int tmp = dfs(v,min(c,flow-used));
         if (tmp > 0) {
              e[i].c -= tmp;e[i^1].c += tmp;
              used += tmp;
              if (used==flow) break;
          }
      }
  }
  if (used!=flow) dis[u] = -1;
  return used;
}
inline int dinic() {
  int ans = 0;
  while (bfs()) ans += dfs(S,INF);
  return ans;
}
int main() {
  int sum_case = read();
  for (int Case=1; Case<=sum_case; Case++) {
      init();
      int n = read(),m = read();
      S = 1;T = n + m + 1;
      for (int i=1; i<=m; ++i) add_edge(i+n,T,1);
      for (int i=1; i<=n; ++i) {
          int k = read();
          for (int a,j=1; j<=k; ++j) {
              a = read();cnt[i][a]++;
          }
      }
      for (int i=1; i<=m; ++i) 
          if (cnt[1][i]) add_edge(S,i+n,cnt[1][i]);
      for (int i=2; i<=n; ++i) {
          for (int j=1; j<=m; ++j) {
              if (cnt[i][j] > 1) add_edge(i,j+n,cnt[i][j]-1);
              else if (cnt[i][j]==0) add_edge(j+n,i,1);
          }
      }
      printf("Case #%d: %d\n",Case,dinic());        
 }
return 0;
}