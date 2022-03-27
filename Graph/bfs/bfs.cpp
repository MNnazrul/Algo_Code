#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define mxN 10000

int n, edges;
vector <int> adj[mxN], level;
vector <bool> vis;

void bfs(int source) {
   queue<int> q;
   q.push(source);
   vis[source] = false;

   while(!q.empty()) {
      int cur_node = q.front();
      q.pop();
      for (int child : adj[cur_node]) {
         if(vis[child]) {
            vis[child] = false;
            level[child] = level[cur_node] + 1;
            q.push(child);
         }
      }

   }


}

int main() {
   cin >> n >> edges;
   for (int i = 0; i < edges; i++) {
      int u, v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   level.assign(n + 2, 0);
   vis.assign(n + 2, true);

   int source; cin >> source;
   bfs(source);

   for (int i = 1; i <= n; i++) cout << level[i] << ' ';

   return 0;
}