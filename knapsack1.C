#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
    
    Item(int v, int w) : value(v), weight(w) {
        ratio = (weight == 0) ? 0 : static_cast<double>(value) / weight;
    }
};
bool compareByRatio(const Item &a, const Item &b) {
    return a.ratio > b.ratio;
}
double fractionalKnapsackRecursive(const vector<Item> &items, int capacity, int index) {
    
    if (index >= items.size() || capacity <= 0) {
        return 0.0;
    }
    
    
    if (items[index].weight <= capacity) {
        return items[index].value + 
               fractionalKnapsackRecursive(items, capacity - items[index].weight, index + 1);
    }
    
    else {
        double fraction = static_cast<double>(capacity) / items[index].weight;
        return fraction * items[index].value;
    }
}


double solveFractionalKnapsack(vector<int> &values, vector<int> &weights, int capacity) {
    int n = values.size();
    if (n == 0 || capacity == 0) return 0.0;
    
    
    vector<Item> items;
    for (int i = 0; i < n; i++) {
        items.emplace_back(values[i], weights[i]);
    }
    
    
    sort(items.begin(), items.end(), compareByRatio);
    
   
    return fractionalKnapsackRecursive(items, capacity, 0);
}

int main() {
    
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;
    
    double maxValue = solveFractionalKnapsack(values, weights, capacity);
    
    cout << "Maximum value in knapsack: " << maxValue << endl;
    
    return 0;
}