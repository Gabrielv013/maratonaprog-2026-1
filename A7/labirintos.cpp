#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9;
 
/**
 * PROBLEMA DO CARTEIRO CHINÊS - Desenho de Labirinto
 * 
 * Problema: Encontrar o menor número de movimentos de caneta para desenhar um labirinto
 * começando e terminando no mesmo nodo, sem levantar a caneta do papel.
 * 
 * Solução: 
 * 1. Se o grafo é Euleriano (todos vértices com grau par): resposta = número de arestas
 * 2. Se não: encontrar emparelhamento mínimo entre vértices de grau ímpar
 *    resposta = número de arestas + custo do emparelhamento
 */
 
/**
 * Floyd-Warshall: calcula distâncias mínimas entre todos os pares de vértices
 */
void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
 
/**
 * Emparelhamento mínimo entre vértices de grau ímpar usando DP com máscara de bits
 * O número de vértices de grau ímpar é sempre par (teorema dos apertos de mão)
 */
int emparelhamentoMinimo(vector<int>& impares, vector<vector<int>>& dist) {
    int n = impares.size();
    if (n == 0) return 0;
    
    vector<int> dp(1 << n, INF);
    dp[0] = 0;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == INF) continue;
        
        // Encontra primeiro vértice ímpar não pareado
        int primeiro = -1;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                primeiro = i;
                break;
            }
        }
        
        if (primeiro == -1) continue;
        
        // Tenta parear com outro vértice ímpar não pareado
        for (int segundo = primeiro + 1; segundo < n; segundo++) {
            if (!(mask & (1 << segundo))) {
                int novoMask = mask | (1 << primeiro) | (1 << segundo);
                int custo = dist[impares[primeiro]][impares[segundo]];
                dp[novoMask] = min(dp[novoMask], dp[mask] + custo);
            }
        }
    }
    
    return dp[(1 << n) - 1];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;  // nodo inicial e final
        cin >> N;
        
        int V, A;  // vértices e arestas
        cin >> V >> A;
        
        // Inicializa matriz de distâncias
        vector<vector<int>> dist(V, vector<int>(V, INF));
        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }
        
        // Grau de cada vértice
        vector<int> grau(V, 0);
        
        // Lê as arestas e constrói matriz de adjacência
        for (int i = 0; i < A; i++) {
            int u, v;
            cin >> u >> v;
            
            grau[u]++;
            grau[v]++;
            
            // Atualiza matriz de distâncias (grafo não ponderado)
            dist[u][v] = 1;
            dist[v][u] = 1;
        }
        
        // Calcula caminhos mínimos entre todos os pares
        floydWarshall(dist, V);
        
        // Encontra vértices com grau ímpar
        vector<int> impares;
        for (int i = 0; i < V; i++) {
            if (grau[i] % 2 == 1) {
                impares.push_back(i);
            }
        }
        
        // Calcula número mínimo de movimentos
        int movimentos = A;  // Todas as arestas devem ser percorridas pelo menos uma vez
        
        // Se há vértices de grau ímpar, precisa duplicar algumas arestas
        if (!impares.empty()) {
            int custoEmparelhamento = emparelhamentoMinimo(impares, dist);
            movimentos += custoEmparelhamento;
        }
        
        cout << movimentos << "\n";
    }
    
    return 0;
}
 
