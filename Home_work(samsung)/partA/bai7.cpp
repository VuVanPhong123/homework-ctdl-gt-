
#include<bits/stdc++.h>
using namespace std;

// Biểu diễn ảnh dưới dạng ma trận 2 chiều
vector<vector<int>> image;
// Mảng để kiểm tra xem một điểm ảnh đã được thăm hay chưa
vector<vector<bool>> visited;
// Số hàng và số cột của ảnh
int n, m;

// Hàm để kiểm tra xem một điểm ảnh có nằm trong ảnh hay không
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// Hàm DFS để thực hiện thuật toán floodfill
void dfs(int x, int y, int color) {
    // Đánh dấu điểm ảnh này đã được thăm
    visited[x][y] = true;

    // Xét 8 điểm ảnh xung quanh điểm ảnh hiện tại
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(isValid(newX, newY) && !visited[newX][newY] && image[newX][newY] == color) {
            dfs(newX, newY, color);
        }
    }
}

int main() {
    cin >> n >> m;
    image.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> image[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    dfs(x, y, image[x][y]);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<< visited[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
