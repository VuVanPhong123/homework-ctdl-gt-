#include<bits/stdc++.h>

using namespace std;

class Graph {
private:
    int V; // Số đỉnh của đồ thị
    vector<vector<int>> adjList; // Danh sách kề để lưu trữ đồ thị

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // Thêm một cạnh vào đồ thị
    void addEdge(int u, int v);

    // Phát hiện cạnh song song
    int detectParallelEdges();
};

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int Graph::detectParallelEdges() {
    unordered_set<int> visitedVertices;
    int parallelEdgesCount = 0;

    // Duyệt qua tất cả các đỉnh
    for (int i = 0; i < V; ++i) {
        visitedVertices.clear();

        // Duyệt qua tất cả các đỉnh kề của đỉnh hiện tại
        for (int neighbor : adjList[i]) {
            // Kiểm tra xem đỉnh kề đã được thăm trước đó chưa
            if (visitedVertices.find(neighbor) != visitedVertices.end()) {
                // Nếu đã thăm, có cạnh song song
                ++parallelEdgesCount;
            } else {
                // Nếu chưa thăm, đánh dấu đỉnh kề đã được thăm
                visitedVertices.insert(neighbor);
            }
        }
    }

    return parallelEdgesCount / 2; // Mỗi cạnh song song sẽ được đếm hai lần (một cho mỗi đỉnh kề)
}

int main() {
    // Tạo đồ thị và thêm cạnh
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);
    graph.addEdge(1, 4);
    graph.addEdge(0, 1);

    // Phát hiện và in ra số cạnh song song
    int parallelEdgesCount = graph.detectParallelEdges();
    cout << "Number of parallel edges: " << parallelEdgesCount << endl;

    return 0;
}
