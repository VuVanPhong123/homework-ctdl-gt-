#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSort(vector<vector<int>>& graph, vector<int>& inDegree, int n) {
    queue<int> q;
    vector<int> result;

    for (int u = 1; u <= n; ++u) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (result.size() == n) {
        for (int i = 0; i < n; ++i) {
            cout << result[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    } else {
        cout << "No valid order exists due to cyclic dependencies." << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> inDegree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    topologicalSort(graph, inDegree, n);

    return 0;
}
