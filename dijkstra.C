#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, weight;
    Edge(int _to, int _weight) {
        to = _to;
        weight = _weight;
    }
};

void dijkstra(int n, vector<vector<Edge>>& graph, int source) {
    vector<int> dist(n, INF);
    dist[source] = 0;

    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue; 

        for (auto &edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            cout << "Node " << i << " is unreachable\n";
        else
            cout << "Distance to node " << i << " = " << dist[i] << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(Edge(v, w));
        graph[v].push_back(Edge(u, w)); 
        
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(n, graph, source);

    return 0;
}