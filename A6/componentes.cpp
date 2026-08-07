#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(char u,
         unordered_map<char, vector<char>>& adj,
         unordered_map<char, bool>& visited,
         vector<char>& comp) {
    
    visited[u] = true;

    comp.push_back(u);

    for (char v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, comp);
        }
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int V, E;
        cin >> V >> E;
        unordered_map<char, vector<char>> adj;
        unordered_map<char, bool> visited;

        for (char c = 'a'; c <= 'a'+V; c++) {
            adj[c] = {};
            visited[c] = false;
        }

        for (int j = 0; j < E; j++) {
            char u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int connected = 0;
        cout << "Case #" << i+1 << ":\n";
        for (int j = 0; j < V; j++) {
            char c = 'a' + j;

            if (!visited[c]) {
                vector<char> comp;
                dfs(c, adj, visited, comp);
                sort(comp.begin(), comp.end());
                for (char v : comp)
                    cout << v << ",";
                
                cout << endl;
                connected++;
            }
        }

        cout << connected << " connected components\n\n";
    }



    return 0;
}

