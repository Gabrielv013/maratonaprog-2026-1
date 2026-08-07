#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k == 1) {
            cout << n << '\n';
            continue;
        }

        long long ans = 0;
        while (n > 0) {
            ans += n % k;
            n /= k;
        }

        cout << ans << '\n';
    }

    return 0;
}
