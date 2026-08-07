#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool walk(int i, int j, int M[][5], bool v[][5]) {
    if(i < 0 || i >= 5 || j < 0 || j >= 5)
        return false;
    if(M[i][j] == 1 || v[i][j] == true)
        return false;
    if(i == 4 && j == 4)
        return true;
    
    v[i][j] = true;
    
    if (walk(i + 1, j, M, v)) return true;
    if (walk(i - 1, j, M, v)) return true;
    if (walk(i, j + 1, M, v)) return true;
    if (walk(i, j - 1, M, v)) return true;

    return false;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int M[5][5];
        bool v[5][5];
        int n;
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++) {
                cin >> n;
                M[i][j] = n;
                v[i][j] = false;
            }
        
        if(walk(0,0,M,v))
            cout << "COPS\n";
        else
            cout << "ROBBERS\n";
                
    }



    return 0;
}

