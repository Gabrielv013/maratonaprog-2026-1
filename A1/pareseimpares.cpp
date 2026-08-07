#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int N = 0;
    cin >> N;

    vector<int> even;
    vector<int> odd;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        if(num % 2 == 0)
            even.push_back(num);
        else
            odd.push_back(num);
    }
    
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());
    
    for(int n : even)
        cout << n << '\n';
    for(int n : odd)
        cout << n << '\n';

    return 0;
}
