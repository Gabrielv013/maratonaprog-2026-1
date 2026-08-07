#include <iostream>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        int P;
        cin >> P;

        vector<int> v(P + 1, 0);

        for (int i = 0; i < N; i++) {
            int t, a;
            cin >> t >> a;

            for (int j = P; j >= a; j--)
                v[j] = max(v[j], v[j - a] + t);
        }

        cout << v[P] << " min." << '\n';
    }

    return 0;
}
