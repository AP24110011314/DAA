#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};


class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y])
            parent[x] = y;
        else if (rank[x] > rank[y])
            parent[y] = x;
        else {
            parent[y] = x;
            rank[x]++;
        }
    }
};


void kruskal(int n, vector<Edge>& edges) {

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    DSU dsu(n);
    vector<Edge> mst;
    int totalWeight = 0;

    for (auto &edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst.push_back(edge);
            totalWeight += edge.weight;
        }
    }

    cout << "Edges in the Minimum Spanning Tree (MST):\n";
    for (auto &e : mst) {
        cout << e.u << " -- " << e.v << " == " << e.weight << "\n";
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges;
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    kruskal(n, edges);
    return 0;
}