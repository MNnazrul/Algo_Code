#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define mxN 100000

int n, edges;
vector<pair<int, int>> adj[mxN];
vector <bool> vis;
vector <int> dis;

void dij(int src) {
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
   pq.push({0, src});

   while(!pq.empty()) {
      int node = pq.top().second;
      int di = pq.top().first;
      pq.pop();
      vis[node] = false;
      for (auto [child, weight] : adj[node]) {
         if(vis[child] && dis[child] > dis[node] + weight) {
            dis[child] = min(dis[child], dis[node] + weight);
            pq.push({dis[child], child});
         }
      }
      
   }

}

int main() {
   cin >> n >> edges;

   for (int i = 0; i < edges; i++) {
      int u, v, w; cin >> u >> v >> w; // here u, v >= 1 and u, v <= n...
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
   }

   int src; cin >> src;

   vis.assign(n + 2, true);
   dis.assign(n + 2, 0);
   for (int i = 1; i <= n; i++) if(i != src) dis[i] = INT_MAX;

   dij(src);

   for (int i = 1; i <= n; i++) cout << i << " " << dis[i] << endl;

   return 0;
}