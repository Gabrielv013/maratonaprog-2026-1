#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
 
using namespace std; 

int main() {
    string line;
    bool first = true;
    while(getline(cin, line)) {
        if(first)
            first = false;
        else
            cout << '\n';
        
        map<char, int> m;
        for(char c : line) {
            if(m.contains(c))
                m[c] = m[c]+1;
            else
                m[c] = 1;
        }
        vector<pair<char, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            if(a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        });
        
        for(const auto& i : v)
            cout << (int)i.first << " " << i.second << '\n';

    }
    
    return 0;
}
