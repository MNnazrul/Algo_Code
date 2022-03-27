#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define N 100000

int n, edges;
vector <int> adj[N];
int indegree[N];

queue<int> q;

void topo() {
	vector <int> seq;
	while(!q.empty()) {
		int node = q.front();
		seq.push_back(node);
		q.pop();
		for (int child : adj[node]) {
			indegree[child]--;
			if(indegree[child] == 0) q.push(child);
		}
	}
   cout << "Order : ";
	for (int i : seq) cout << i << ' ';
}

int main() {

	cin >> n >> edges;
	for (int i = 0; i < edges; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}

	for (int i = 0; i < n; i++) {
		if(indegree[i] == 0) {q.push(i);}
	}

	topo();


	return 0;
}