#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool visited[10];
int n = 10;

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isEulerianCycle() {
    int odd = 0;
    for(int i=0; i<n; i++) {
        if(adj[i].size() & 1) {
            odd++;
        }
    }
    if(odd > 2) {
        return false;
    }
    return true;
}

void DFS(int v) {
    visited[v] = true;
    for(int i=0; i<adj[v].size(); i++) {
        if(!visited[adj[v][i]]) {
            DFS(adj[v][i]);
        }
    }
}

bool isConnected() {
    int i;
    for(i=0; i<n; i++) {
        if(adj[i].size() != 0) {
            break;
        }
    }
    if(i == n) {
        return true;
    }
    memset(visited, false, sizeof(visited));
    DFS(i);
    for(i=0; i<n; i++) {
        if(visited[i] == false && adj[i].size() > 0) {
            return false;
        }
    }
    return true;
}

bool isHamiltonianCycle() {
    if(isConnected() == false) {
        return false;
    }
    return isEulerianCycle();
}

int main() {
    int u, v;
    char kitu='-';
    cout << "nhap canh :" << endl;
    for(int i=0; i<10; i++) {
        cin >> u >>kitu>> v;
        addEdge(u, v);
    }

    if(isHamiltonianCycle()) {
        cout << "co chu trinh hamilton" << endl;
    } else {
        cout << "khong co chu trinh hamilton" << endl;
    }

    if(isEulerianCycle()) {
        cout << "co chu trinh euler" << endl;
    } else {
        cout << "khong co chu trinh euler" << endl;
    }

    return 0;
}
