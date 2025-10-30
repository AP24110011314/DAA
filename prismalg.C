#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};


void primMST(int n, vector<vector<Edge>>& graph) {
    vector<int> key(n, INT_MAX);     
    vector<int> parent(n, -1);       
    vector<bool> inMST(n, false);    

    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        
        for (auto edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    
    cout << "Edges in the Minimum Spanning Tree:\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "  (weight: " << key[i] << ")\n";
        totalWeight += key[i];
    }
    cout << "Total weight of MST = " << totalWeight << endl;
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<Edge>> graph(n);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(Edge(v, w));
        graph[v].push_back(Edge(u, w)); 
    }

    primMST(n, graph);

    return 0;
}