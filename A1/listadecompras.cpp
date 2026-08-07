#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N = 0;
    cin >> N;
    cin.ignore();

    for(int i = 0; i < N; i++) {
        string list;
        getline(cin, list);

        stringstream ss(list);
        string item;
        set<string> items;

        while(ss >> item)
            items.insert(item);
        
        bool first = true;
        for(string word : items) {
            if(!first)
                cout << " ";
            cout << word;
            first = false;
        }
        cout << '\n';
    }

    return 0;
}
