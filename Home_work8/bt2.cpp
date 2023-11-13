#include<bits/stdc++.h>

using namespace std;

int knapsackDynamic(int capacity, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity = 15;
    vector<int> weights = {2, 3,5,7,1,4,1 };
    vector<int> values = {10,5,15,7,8,9,4};

    int result = knapsackDynamic(capacity, weights, values);

    cout << "Maximum value that can be stolen: " << result << endl;

    return 0;
}
