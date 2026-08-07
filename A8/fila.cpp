#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> fila(N);
    for (int i = 0; i < N; i++)
        cin >> fila[i];

    int M;
    cin >> M;

    unordered_set<int> saiu;
    for (int i = 0; i < M; i++) {
        int id;
        cin >> id;
        saiu.insert(id);
    }

    bool primeiro = true;
    for (int id : fila) {
        if (saiu.find(id) == saiu.end()) {
            if (!primeiro) cout << ' ';
            cout << id;
            primeiro = false;
        }
    }

    cout << '\n';
    return 0;
}
