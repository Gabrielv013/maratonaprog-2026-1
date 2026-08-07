#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
 
using namespace std; 
 
int main() {
    int N;
    cin >> N;
    int N2 = N;
    unordered_map<int, int> qtd;
    qtd[1] = 0;
    qtd[2] = 0;
    qtd[5] = 0;
    qtd[10] = 0;
    qtd[20] = 0;
    qtd[50] = 0;
    qtd[100] = 0;
    
    while(N > 0) {
        for (const auto& [k, v] : qtd) {
            if(N >= k) {
                N -= k;
                qtd[k]++;
                break;
            }
        }
    }
    
    cout << N2 << endl;
    for (const auto& [k, v] : qtd) {
        cout << v << " nota(s) de R$ " << k << ",00" << endl;
    }
        
    return 0;
}
