#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
vector<int> topo;
bool visited[100001];
int n, m;

void dfs(int u) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
    topo.push_back(u);
}

bool checkUniqueTopo() {
    for(int i = 0; i < n - 1; i++) {
        bool found = false;
        for(int v : adj[topo[i]]) {
            if(v == topo[i + 1]) {
                found = true;
                break;
            }
        }
        if(!found) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());
    if(checkUniqueTopo()) {
        cout << "The graph has a unique topological order";
    } else {
        cout << "The graph does not have a unique topological order";
    }
    return 0;
}
