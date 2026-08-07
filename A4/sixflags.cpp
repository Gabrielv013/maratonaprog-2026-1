#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int H = 1;
    while(true) {
        int N, T;
        cin >> N;
        if(N == 0)
            break;
        cin >> T;
        
        vector<int> v(T+1, 0);
        
        int D, P;
        for(int i = 0; i < N; i++) {
            cin >> D >> P;
            for(int j = D; j <= T; j++)
                v[j] = max(v[j], v[j-D] + P);
        }
        
        cout << "Instancia " << H++ << '\n';
        cout << v[T] << "\n\n";
    }

    return 0;
}
