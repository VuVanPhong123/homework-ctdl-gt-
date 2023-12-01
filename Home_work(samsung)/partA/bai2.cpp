#include<bits/stdc++.h>

using namespace std;

// Hàm tính giai thừa
long long factorial(int n) {
    long long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Hàm tính tổ hợp
long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Hàm tính số lượng đồ thị khác nhau
long long countGraphs(int V, int E) {
    int maxEdges = combination(V, 2);
    return combination(maxEdges, E);
}

int main() {
    int V, E;
    cout << "Nhap so luong dinh: ";
    cin >> V;
    cout << "Nhap so luong canh: ";
    cin >> E;
    cout << "So luong do thi khac nhau co the tao ra: " << countGraphs(V, E) << endl;
    return 0;
}
