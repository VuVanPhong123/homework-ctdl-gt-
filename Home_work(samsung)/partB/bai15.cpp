#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int indegree[100001];
int n, m;

void topologicalSort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    topologicalSort();
    return 0;
}
