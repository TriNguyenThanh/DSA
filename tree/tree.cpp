#include <iostream>
using namespace std;

struct Node{
    int info;
    Node *left, *right;
};
typedef Node* Tree; 

Node* getNode(int x){
    Node* newNode = new Node;
    newNode->info = x;
    newNode->left = newNode->right = NULL;
    
    return newNode;
}
void insertTree(Tree &t, int x){
    if (t != nullptr){
        if(t->info == x){}
        else if (x<t->info){
            insertTree(t->left, x);
        }else{
            insertTree(t->right, x);
        }
    }else{
        t = getNode(x);
    }
}
void LNR(Tree t){
    if (!t) return;
    LNR(t->left);
    cout << t->info << ' ';
    LNR(t->right);
}
void NLR(Tree t){
    if (!t) return;
    cout << t->info << ' ';
    NLR(t->left);
    NLR(t->right);
    
}
void LRN(Tree t){
    if (!t) return;
    LRN(t->left);
    LRN(t->right);
    cout << t->info << ' ';
}

int main(){
    Tree t = nullptr;
    cout << "Nhap n:";
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        insertTree(t,x);
    }
    cout << "NLR: "; NLR(t); cout << '\n';
    cout << "LNR: "; LNR(t); cout << '\n';
    cout << "LRN: "; LRN(t); cout << '\n';
    return 0;
}