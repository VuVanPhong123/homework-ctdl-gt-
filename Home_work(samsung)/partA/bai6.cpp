#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int visited[100001], in[100001], low[100001];
int timer;

void dfs(int node, int par) {
    visited[node] = 1;
    in[node] = low[node] = timer;
    timer++;
    for(int child : adj[node]) {
        if(child == par) continue;
        if(visited[child] == 1) {
            // this means that this node has already been visited and this edge is a back edge
            low[node] = min(low[node], in[child]);
        } else {
            // this is a forward edge so we can call dfs over it
            dfs(child, node);
            if(low[child] > in[node]) {
                cout << "This graph is not edge connected\n";
                return;
            }
            // after returning from dfs we will try to minimize low[node]
            low[node] = min(low[node], low[child]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << "This graph is edge connected\n";
    return 0;
}
