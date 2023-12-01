#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
vector<int> result;
int in[100001], out[100001];
int n, m;

void findEulerPath(int u) {
    while(out[u] > 0) {
        int v = adj[u][--out[u]];
        findEulerPath(v);
    }
    result.push_back(u);
}

bool checkEuler() {
    int start = 0, end = 0;
    for(int i = 1; i <= n; i++) {
        if(in[i] - out[i] > 1 || out[i] - in[i] > 1) {
            return false;
        }
        if(out[i] - in[i] == 1) {
            start++;
        }
        if(in[i] - out[i] == 1) {
            end++;
        }
    }
    return (start == 0 && end == 0) || (start == 1 && end == 1);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        out[u]++;
        in[v]++;
    }
    if(checkEuler()) {
        findEulerPath(1);
        for(int i = result.size() - 1; i >= 0; i--) {
            cout << result[i] << " ";
        }
    } else {
        cout << "No Eulerian cycle exists";
    }
    return 0;
}
