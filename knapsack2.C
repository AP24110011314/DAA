#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int knapsackRecursive(int i, int W, vector<int>& weights, vector<int>& values, vector<vector<int>>& dp) {
    
    if (i == 0 || W == 0) {
        return 0;
    }
    
    if (dp[i][W] != -1) {
        return dp[i][W];
    }
    
    if (weights[i-1] > W) {
        dp[i][W] = knapsackRecursive(i-1, W, weights, values, dp);
        return dp[i][W];
    }
    
    int include = values[i-1] + knapsackRecursive(i-1, W - weights[i-1], weights, values, dp);
    int exclude = knapsackRecursive(i-1, W, weights, values, dp);
    
    dp[i][W] = max(include, exclude);
    return dp[i][W];
}

int knapsack(vector<int>& values, vector<int>& weights, int capacity) {
    int n = values.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    
    return knapsackRecursive(n, capacity, weights, values, dp);
}


void printDPTable(const vector<vector<int>>& dp) {
    cout << "DP Table:" << endl;
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            if (dp[i][j] == -1) {
                cout << " - ";
            } else {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;
    
    int maxValue = knapsack(values, weights, capacity);
    cout << "Maximum value: " << maxValue << endl;
    
    
    vector<int> values2 = {1, 2, 3};
    vector<int> weights2 = {4, 5, 1};
    int capacity2 = 4;
    
    int maxValue2 = knapsack(values2, weights2, capacity2);
    cout << "Maximum value 2: " << maxValue2 << endl;
    
    return 0;
}