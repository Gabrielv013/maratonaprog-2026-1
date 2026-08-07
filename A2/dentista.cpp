#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for(int i = 0; i < N; i++) {
        int s;
        int e;
        cin >> s >> e;
        v.push_back({s,e});
    }
    
    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;   
    });
    

    
    int count = 1;
    int etime = v[0].second;
    for(int i = 1; i < N; i++) {
        if(v[i].first >= etime) {
            etime = v[i].second;
            count++;
        }
    }
    
    cout << count << endl;

    return 0;
}
