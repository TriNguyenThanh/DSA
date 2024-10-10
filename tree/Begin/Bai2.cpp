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
void LNR(Tree t){
    if (!t) return;
    LNR(t->left);
    cout << t->info << ' ';
    LNR(t->right);
}
void inputTree(Tree &t){
	int n, x; cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x;
		insertTree(t, x);
	}
}
Node* Search(Tree t, int x){
    if (t == NULL) return nullptr;
    if (t->info == x) return t;
    else{
        if (x < t->info)
            return Search(t->left, x);
        else
            return Search(t->right, x);
    }
}
int minValue(Tree t){
    Node *p = t;
    while (p->left != nullptr)
    {
        p = p->left;
    }
    return p->info;
}
int maxValue(Tree t){
    Node *p = t;
    while (p->right != nullptr){
        p = p->right;
    }
    return p->info;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;
    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);
	return 0;
}
