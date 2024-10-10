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
void inputTree(Tree &t)
{
    int n, x; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        insertTree(t, x);
    }
}
void NLR(Tree t){
    if (!t) return;
    cout << t->info << ' ';
    NLR(t->left);
    NLR(t->right);
    
}
void rotateLeft(Tree& t)
{
    Tree p = t->right;
    t->right = p->left;
    p->left = t;
    t = p;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    cout << "NLR: ";NLR(T);
    if (T == nullptr)
    {
        cout<< "\nKhong the xoay vi cay rong";
    }
    else if (T->right == nullptr)
    {
        cout<< "\nKhong the xoay trai vi khong co nut con ben phai";
    }
    else
    {
        rotateLeft(T);
    }
    cout << "\nNLR: ";NLR(T);
	return 0;
}