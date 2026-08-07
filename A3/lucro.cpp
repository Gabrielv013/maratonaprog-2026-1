#include <iostream>

using namespace std;

int main() {

    int N, cost, r;
    while(cin >> N) {
        cin >> cost;
        int curr, best;
        curr = best = 0;
        for(int i = 0; i < N; i++) {
            cin >> r;
            r -= cost;
            curr = max(r, curr+r);
            best = max(best, curr);
        }
        cout << best << '\n';
    }
    
    return 0;
}
