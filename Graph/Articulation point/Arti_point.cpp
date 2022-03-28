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
   dfs(1, -1);
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