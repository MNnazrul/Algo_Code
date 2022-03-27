#include <bits/stdc++.h>
using namespace std;

#define N 1000
#define F first
#define S second

vector <pair<int, int>> graph[N], tree;
bool visit[N]; 
int nodes, edges;

void primes() {
   int min_cost = 0;
   priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({0, 1});
   
   while(!pq.empty()) {
      int nd = pq.top().S;
      int w = pq.top().F;
      pq.pop();
      if(visit[nd]) continue;
      min_cost += w;
      visit[nd] = true;
      for (auto [we, u] : graph[nd]) {
         if(visit[u]) continue;
         pq.push({we, u});
      }
   }

   cout << min_cost << endl;
}

int main() {
   cin >> nodes >> edges;
   for (int i = 0; i < edges; i++) {
      int u, v, w; cin >> u >> v >> w;
      graph[u].push_back({w, v});
      graph[v].push_back({w, u});
   }

   primes();


   return 0;
}