/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
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
Tree rotateRight(Tree t)
{
    Tree p = t->left;
    t->left = p->right;
    p->right = t;
    t = p;

	return t;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	T=rotateRight(T);
	cout<<"\nUpdated Tree: \n";
	cout<<"NLR: "; NLR(T);
	return 0;
}



