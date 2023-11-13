#include<bits/stdc++.h>

using namespace std;

struct Artifact {
    int weight;
    int value;
};

bool compare(Artifact a, Artifact b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int knapsackGreedy(int capacity, vector<Artifact>& artifacts) {
    sort(artifacts.begin(), artifacts.end(), compare);

    int totalValue = 0;
    int currentWeight = 0;

    for (const auto& artifact : artifacts) {
        if (currentWeight + artifact.weight <= capacity) {
            currentWeight += artifact.weight;
            totalValue += artifact.value;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 15;
    vector<Artifact> artifacts = {{2, 10}, {3, 5}, {5, 15}, {7, 7}, {1, 8}, {4, 9}, {1, 4}}; // Example artifacts with weight and value

    int result = knapsackGreedy(capacity, artifacts);

    cout << "Maximum value that can be stolen: " << result << endl;

    return 0;
}
