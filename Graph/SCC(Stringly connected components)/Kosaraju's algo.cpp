#include <bits/stdc++.h>
using namespace std;

#define N 10000

vector <int> graph[N], graph1[N], low, disc;
stack <int> s_tak;
int nodes, edges, tim = 0;
bool visit[N];
stack <int> stak;

void dfs(int node) {
   visit[node] = true;
   for (int child : graph[node]) {
      if(!visit[child]) dfs(child);
   }
   stak.push(node);
}

void dfs1(int node) {
   cout << node << ' ';
   visit[node] = false;
   for (int child : graph1[node]) {
      if(visit[child]) dfs1(child);
   }
}

void kosaraju() {

   for (int i = 0; i < nodes; i++) 
      if(!visit[i]) dfs(i);

   while(!stak.empty()) {
      if(visit[stak.top()]) {
         dfs1(stak.top());
         cout << endl;
      } 
      stak.pop();
   }
}

int main() {
   cin >> nodes >> edges;

   for (int i = 0; i < edges; i++) {
      int u, v; cin >> u >> v; // u --> v
      graph[u].push_back(v);
      graph1[v].push_back(u);
   }

   kosaraju();




   return 0;
}

/*

8 10
0 1
2 0
1 2
2 3
3 4
4 5
4 7
6 4
6 7
5 6
*/