#include <bits/stdc++.h>
using namespace std;

#define N 1000
#define F first
#define S second

vector <pair<int, int>> graph[N], tree;
bool visit[N]; 
int nodes, edges;
vector <tuple<int, int, int>> ed;
vector <int> par;

int find_group(int u) {
   return par[u] == u ? u : par[u] = find_group(par[u]);
}

void kruskal() {
   int min_cost = 0;
   for (auto[x, u, v] : ed) {
      int p1 = find_group(u);
      int p2 = find_group(v);
      if(p1 == p2) continue;
      min_cost += x;
      par[p1] = p2;
   }

   cout << min_cost << endl;
}

int main() {

   cin >> nodes >> edges;
   for (int i = 0; i < edges; i++) {
      int w, u, v; cin >> u >> v >> w;
      ed.push_back({w, u, v});
   }

   par.assign(nodes + 2, 0);
   for (int i = 0; i <= nodes; i++) par[i] = i;

   sort(ed.begin(), ed.end());

   kruskal();


   return 0;
}