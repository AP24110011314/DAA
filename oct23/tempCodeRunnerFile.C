#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;

vector<int> adj[MAX]; 
bool visited[MAX];

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";
    
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
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
    
    
    cout << "Enter edges (format: u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    
    int component_count = 0;
    
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            component_count++;
            cout << "Component " << component_count << ": ";
            dfs(i);
            cout << endl;
        }
    }
    
    cout << "Total Connected Components = " << component_count << endl;
    
    return 0;
}