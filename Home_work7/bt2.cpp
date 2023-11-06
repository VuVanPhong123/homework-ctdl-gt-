
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, d;
    Edge(int _u, int _v, int _d) : u(_u), v(_v), d(_d) {}
    bool operator<(const Edge& other) const {
        return d < other.d;
    }
};

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
        return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    parent.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        edges.push_back(Edge(u, v, d));
    }

    sort(edges.begin(), edges.end());

    int total_cost = 0;
    vector<Edge> mst_edges;

    for (const Edge& edge : edges) {
        if (unite(edge.u, edge.v)) {
            total_cost += edge.d;
            mst_edges.push_back(edge);
        }
    }

    cout << total_cost << endl;

    for (const Edge& edge : mst_edges) {
        cout << edge.u << " " << edge.v << " " << edge.d << endl;
    }

    return 0;
}
