#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

#define N 100000

int n, edges, cn = 0;
vector <int> adj[N], order;
int indegree[N];
bool visit[N];

queue<int> q;


void topo(vector <int> &pa1) {
   if(pa1.size() == n) {
      for (int j : pa1) cout << j << ' '; cout << endl;
      return;
   }

   for (int i = 0; i < n; i++) {
      if(!visit[i] && indegree[i] == 0)  {
         visit[i] = true;
         for (int j : adj[i]) {
            --indegree[j];
         }

         pa1.push_back(i);
         topo(pa1);

         for (int j : adj[i]) {indegree[j]++;}
         visit[i] = false;
         pa1.pop_back();
      }
   }

}

int main() {

	cin >> n >> edges;

   memset(visit, false, sizeof(visit));

	for (int i = 0; i < edges; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}
   vector <int> pa;

	topo(pa);


	return 0;
}