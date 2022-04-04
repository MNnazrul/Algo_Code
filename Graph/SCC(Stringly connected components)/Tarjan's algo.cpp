#include <bits/stdc++.h>
using namespace std;

#define N 10000

int nodes, edges;
vector <int> graph[N], disc, low;
int timer = 1;
stack<int> st;
int ii = 1;
bool vis[N];


void find_compo(int node) {
    disc[node] = low[node] = timer++;
    st.push(node);
    for (int child : graph[node]) {
        if(disc[child] == -1) {
            find_compo(child);
            low[node] = min(low[node], low[child]);
        }
        else if(!vis[child]) low[node] = min(low[node], low[child]);
    }
    if(disc[node] == low[node]) {
        cout << "SCC #" << ii++ << " : ";
        while(!st.empty()) {
            int c = st.top();
            cout << c << ' ';
            vis[c] = true;
            st.pop();
            if(c == node) break;
        }
        cout << endl;
    }
}

void tarzan() {
    for (int i = 0; i < nodes; i++) {
        if(disc[i] == -1) find_compo(i);
    }
}

int main() {

    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
    }
    disc.assign(nodes + 5, -1);
    low.assign(nodes + 5, -1);

    tarzan();

    return 0;
}
/**

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
