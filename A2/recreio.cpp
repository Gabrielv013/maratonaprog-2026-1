#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
 
using namespace std; 
 
int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int M;
        cin >> M;
        vector<int> v1;
        for(int j = 0; j < M; j++) {
            int g;
            cin >> g;
            v1.push_back(g);
        }
        
        vector<int> v2 = v1;
        sort(v2.begin(), v2.end(), greater<int>());
        int stay = 0;
        for(int j = 0; j < M; j++)
            if(v1[j] == v2[j])
                stay++;
        cout << stay << '\n';
    }
 
    return 0;
}
