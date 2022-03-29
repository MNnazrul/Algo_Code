#include <bits/stdc++.h>

using namespace std;

#define N 10000


vector <int> graph[N], disc, low;
vector <pair<int, int>> arti_bridge;
int nodes, edges, tim = 0;

void dfs(int node, int par) {
   disc[node] = low[node] = ++tim;
   for (int child : graph[node]) {
      if(child == par) continue;
      if(low[child] == -1) {
         dfs(child, node);
         low[node] = min(low[node], low[child]);
         if(low[child] > disc[node]) arti_bridge.push_back({node, child});
      } else {
         low[node] = min(low[node], disc[child]);
      }
   }
}

void arti() {
   for (int i = 0; i < nodes; i++)
      if(low[i] == -2) dfs(i, -1);
   
   cout << "Articulation Bridge : " << endl;
   for (auto[x, y] : arti_bridge) cout << x << " --> " << y << endl;

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

   arti();

   return 0;
}

/**
Test Case : 1

5 5
0 2
3 0
0 1
1 2
3 4

Test Case : 2

6 7
0 3
0 1
3 2
2 1
2 4
2 5
4 5


*/