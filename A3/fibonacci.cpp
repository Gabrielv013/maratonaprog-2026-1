#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <long long> v(61, 0);
    v[0] = 0;
    v[1] = 1;
    int pos = 1;
    long long fib;
    
    int N, x;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x;
        
        if(x <= pos)
            fib = v[x];
        else {
            while(pos < x) {
                pos++;
                v[pos] = v[pos-1] + v[pos-2];
            }
            fib = v[pos];
        }
        
        cout << "Fib(" << x << ") = " << fib << '\n';
    }
    
    return 0;
}
