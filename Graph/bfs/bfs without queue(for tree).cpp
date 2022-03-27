#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define mxN 10000

int n, edges;
vector <int> adj[mxN], level;
vector<bool> vis;


void dfs(int node) {
   for (int child : adj[node]) {
      if(vis[child]) {
         vis[child] = false;
         level[child] = level[node] + 1;
         dfs(child);
      }

   }
}

int main() {
   cin >> n;
   for (int i = 0; i < n - 1; i++) { // n - 1 edges...
      int u, v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   level.assign(n + 2, 0);
   vis.assign(n + 2, true);
   int root; cin >> root;

   // cout << root << endl;
   vis[root] = false;
   dfs(root);

   for (int i = 1; i <= n; i++) cout << level[i] << ' ';

   return 0;
}