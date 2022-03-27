#include <bits/stdc++.h>
using namespace std;

#define N 1000

int nodes, edges;
int adj[N][N]; // for adjacency list you can use map....
bool visit[N];
vector <int> path, Ham_path;


void HamiltonPath() {
   if(Ham_path.size() == nodes) return;
   if(path.size() == nodes) {
      bool f = true;
      for (int i = 1; i < path.size(); i++) {
         if(!adj[path[i-1]][path[i]]) {
            f = false;
            break;
         }
      }
      if(f) {
         Ham_path = path;
      }
      return;
   }

   for (int i = 0; i < nodes; i++) {
      if(visit[i]) continue;
      path.push_back(i);
      visit[i] = true;
      HamiltonPath();
      visit[i] = false;
      path.pop_back();
   }
}

int main() {
   cin >> nodes >> edges;

   for (int i = 0; i < edges; i++) {
      int u, v; cin >> u >> v;
      adj[u][v] = 1;
      adj[v][u] = 1;
   }

   HamiltonPath();

   if(Ham_path.size() == 0) cout << "NO HAMILTON PATH" << endl;
   else {
      cout << "Hamilton Path = ";
      cout << Ham_path[0];
      for (int i = 1; i < nodes; i++) cout << " -> " << Ham_path[i];
      cout << endl;
   }


   return 0;
}
