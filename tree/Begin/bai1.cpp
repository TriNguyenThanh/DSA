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
void NLR(Tree t){
    if (!t) return;
    cout << t->info << ' ';
    NLR(t->left);
    NLR(t->right);
    
}
void LNR(Tree t){
    if (!t) return;
    LNR(t->left);
    cout << t->info << ' ';
    LNR(t->right);
}
void LRN(Tree t){
    if (!t) return;
    LRN(t->left);
    LRN(t->right);
    cout << t->info << ' ';
}

void inputTree(Tree &t){
	int n, x; cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x;
		insertTree(t, x);
	}
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	return 0;
}
