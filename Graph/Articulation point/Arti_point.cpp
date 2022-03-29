#include <bits/stdc++.h>

using namespace std;
#define N 1000

vector <int> graph[N], disc, low, arti;
int nodes, edges, tim = 1;

void dfs(int node, int par) {
   disc[node] = low[node] = tim++;
   int chi = 0, mn = 0;
   for (int child : graph[node]) {
      if(child == par) continue;
      if(low[child] == -1) {
         dfs(child, node);
         chi++;
         low[node] = min(low[child], low[node]);
         mn = max(mn, low[child]);
      }
      else low[node] = min(low[node], disc[child]);
   }
   // cout << node << ' ' << mn << endl;
   if(par == -1) {
      if(chi > 1) arti.push_back(node);
   } else {
      if(disc[node] <= mn) arti.push_back(node);
   }
}

void arti_point() {
   for (int i = 0; i < nodes; i++) 
      if(low[i] == -1) dfs(i, -1);
   // dfs(1, -1);
   // sort(arti.begin(), arti.end());
   cout << "Articulation points : ";
   for (int i : arti) cout << i << "  "; cout << endl;
}

int main() {
   cin >> nodes >> edges;

   disc.assign(nodes + 5, -1);
   low.assign(nodes + 5, -1);

   for (int i = 0; i < edges; i++) {
      int x, y; cin >> x >> y;
      graph[x].push_back(y);
      graph[y].push_back(x);
   }

   arti_point();


   return 0;
}

/**
Test Case : 1- 
6 7
0 3
0 1
3 2
2 1
2 4
2 5
4 5

Test Case : 2
4 5
1 2
1 0
0 2
0 3
3 4
Test Case : 3
7 8
0 2
0 1
1 2
1 6
1 3
1 4
4 5
3 5

*/