#include<bits/stdc++.h>
using namespace std;
int max(int a, int b) {
    if (a>b)
        return a;
    else return b;
}

int longestCommonSubsequence(vector<int>& a, vector<int>& b) {
    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 4, 6, 8, 10};

    int lcsLength = longestCommonSubsequence(a, b);

    cout << "do dai cua day con chung dai nhat (LCS) la: " << lcsLength << endl;

    return 0;
}
