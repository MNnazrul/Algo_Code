#include <iostream>
#include <vector>

using namespace std;
#define N 1000

vector <int> indg;
int n, edges;
vector <vector<int>> adj;
vector <pair<int, int>> path;

int findSrc() {
   int cn = 0, cp = -1;
   for (int i = 0; i < n; i++) {
      if(indg[i]&1) {
         cn++;
         cp = i;
      }
      else if(cn == 0) cp = i;
   }
   if(cn > 2) return -2;
   return cp;
}

void delEdge(int u, int v) {
   adj[u][v] = 0;
   adj[v][u] = 0;
   indg[u]--;
   indg[v]--;
}

bool isBridge(int u, int v) {
   if(indg[v] > 1) return false;
   return true;
}

void doEulerTraverse(int u) {
   vector <int> bridge;
   for (int v = 0; v <= n; v++) {
      if(adj[u][v] == 0) continue;
      if(isBridge(u, v)) bridge.push_back(v);
      else {
         delEdge(u, v);
         path.push_back({u, v});
         doEulerTraverse(v);
         return;
      }
   }
   if(bridge.size() == 0) return;
   int v = bridge[0];
   delEdge(u, v);
   path.push_back({u, v});
   doEulerTraverse(v);

}

int main () {
   cin >> n >> edges;

   indg.assign(n + 2, 0);
   adj.assign(n + 2, vector<int> (n + 2, 0));
   for (int i = 0; i < edges; i++) {
      int u, v; cin >> u >> v;
      adj[u][v] = 1;
      adj[v][u] = 1;
      indg[u]++; indg[v]++;
   }

   int src = findSrc();

   if(src < 0) {
      cout << "DON'T exist euler path" << endl;
      return 0;
   }

   doEulerTraverse(src);

   cout << "Euler path : ";
   cout << path[0].first << "," << path[0].second;
   for (int i = 1; i < path.size(); i++) 
      cout << " -> " << path[i].first << "," << path[i].second;

   return 0;
}