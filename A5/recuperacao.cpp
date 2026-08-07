#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* l;
    Node* r;

    Node(int val) : data(val), l(nullptr), r(nullptr) {}
};

void postorder(Node *r) {
    if(r == nullptr) return;
    postorder(r->l);
    postorder(r->r);
    cout << r->data;
}

Node* build(string p, string i) {
    if(p.empty() || i.empty())
        return nullptr;
    
    char c = p[0];
    Node* r = new Node(c);

    int idx = i.find(c);
    
    string lefti = i.substr(0, idx);
    string righti = i.substr(idx + 1);
    
    string leftp = p.substr(1, lefti.size());
    string rightp = p.substr(1 + lefti.size());
    
    r->l = build(leftp, lefti);
    r->r = build(rightp, righti);
    
    return r;
}


int main() {
    string p, i;
    while(cin >> p >> i) {
        Node *r = build(p, i);
        postorder(r);
        cout << '\n';
    }

    return 0;
}
