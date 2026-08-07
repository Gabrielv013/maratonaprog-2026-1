#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void dfs(int node, vector<int> adj[], bool visited[]) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m && (n || m)) {
        vector<int> adj[2005];
        
        for (int i = 0; i < m; i++) {
            int v, w, p;
            cin >> v >> w >> p;
            adj[v].push_back(w);
            if (p == 2) {
                adj[w].push_back(v);
            }
        }
        
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            bool visited[2005];
            memset(visited, false, sizeof(visited));
            dfs(i, adj, visited);
            
            for (int j = 1; j <= n; j++) {
                if (!visited[j]) {
                    ok = false;
                    break;
                }
            }
            
            if (!ok) break;
        }
        
        cout << (ok ? 1 : 0) << "\n";
    }
    
    return 0;
}
