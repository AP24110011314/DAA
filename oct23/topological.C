#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(int N, vector<vector<int>>& edges) {
    
    vector<vector<int>> adj(N);
    vector<int> indegree(N, 0);
    
    
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);
        
        
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    
    if (topoOrder.size() != N) {
        cout << "Graph has a cycle! Topological sort not possible." << endl;
        return {};
    }
    
    return topoOrder;
}

int main() {
   
    int N = 6;
    
   
    vector<vector<int>> edges = {
        {5, 2}, {5, 0}, 
        {4, 0}, {4, 1}, 
        {2, 3}, {3, 1}
    };
    
    vector<int> result = topologicalSort(N, edges);
    
    if (!result.empty()) {
        cout << "Topological Order: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}