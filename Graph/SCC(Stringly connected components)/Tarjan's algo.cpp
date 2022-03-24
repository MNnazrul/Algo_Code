#include <bits/stdc++.h>
using namespace std;

#define N 10000

vector <int> graph[N], low, disc;
stack <int> s_tak;
int nodes, edges, tim = 0;
bool visit[N];

void find_compo(int node) {
   visit[node] = true;
   s_tak.push(node);
   low[node] = disc[node] = tim++;
   for (int child : graph[node]) {
      if(disc[child] == -1) {
         find_compo(child);
      }
      low[node] = min(low[node], low[child]);
   }

   if(low[node] == disc[node]) {
      while(1) {
         int nd = s_tak.top();
         cout << nd << ' ';
         s_tak.pop();
         if(nd == node) {cout << endl; break;} 
      }
   }

}

void tarjan() {
   for (int i = 0; i < nodes; i++)
      if(!visit[i]) find_compo(1);
}

int main() {
   cin >> nodes >> edges;
   
   low.assign(nodes + 2, -1);
   disc.assign(nodes + 2, -1);

   for (int i = 0; i < edges; i++) {
      int u, v; cin >> u >> v; // u --> v
      graph[u].push_back(v);
   }

   tarjan();

   return 0;
}

/*

9 10
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