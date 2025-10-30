#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
vector<int> adj[MAX]; 
bool visited[MAX];
bool hasCycle = false;

void dfs(int v, int parent) {
    visited[v] = true;
    
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, v);
        }
        else if (neighbor != parent) {
            hasCycle = true;
        }
    }
}

int main() {
    int n, edges;
    
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> edges;
    
    
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    
    cout << "Enter edges (vertex pairs):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1); 
        }
    }
    
    
    if (hasCycle) {
        cout << "Cycle found in the graph." << endl;
    } else {
        cout << "No cycle in the graph." << endl;
    }
    
    return 0;
}