#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* l;
    Node* r;

    Node(int val) : data(val), l(nullptr), r(nullptr) {}
};

Node* insert(Node* r, int v) {
    if(r == nullptr)
        r = new Node(v);
    
    if(r && v < r->data) {
        r->l = insert(r->l, v);
    }
    if(r && v > r->data) {
        r->r = insert(r->r, v);
    }
    
    return r;
}

void preorder(Node *r) {
    if(r == nullptr) return;
    cout << " " << r->data;
    preorder(r->l);
    preorder(r->r);
}
void inorder(Node *r) {
    if(r == nullptr) return;
    inorder(r->l);
    cout << " " << r->data;
    inorder(r->r);
}
void postorder(Node *r) {
    if(r == nullptr) return;
    postorder(r->l);
    postorder(r->r);
    cout << " " << r->data;
}


int main() {
    int C;
    cin >> C;
    for(int i = 0; i < C; i++) {
        int N, v;
        Node* t = nullptr;
        cin >> N;
        for(int j = 0; j < N; j++) {
            cin >> v;
            t = insert(t, v);
        }
        
        cout << "Case " << i+1 << ":";
        cout << "\nPre.:";
        preorder(t);
        cout << "\nIn..:";
        inorder(t);
        cout << "\nPost:";
        postorder(t);
        cout << "\n\n";
        
    }

    return 0;
}
