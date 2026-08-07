#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
 
using namespace std; 

int main() {
    string expression;
    while(getline(cin, expression)) {
        stack<char> s;
        bool correct = true;
        
        for(char c : expression) {
            if(c == '(') {
                s.push(c);
                continue;
            }
            if(c == ')') {
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else {
                    correct = false;
                    break;
                }
            }
        }
        
        if(correct && s.empty())
            cout << "correct" << '\n';
        else
            cout << "incorrect" << '\n';
    }
    
    
    return 0;
}
