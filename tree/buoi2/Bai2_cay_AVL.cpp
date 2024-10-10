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
int max_(int a, int b)
{
    return (a < b) ? b: a;
}
int depthOfTree(Tree t)
{
    if (t != nullptr)
    {
        if (t->left == nullptr && t->right == nullptr) return 1;
        return 1 + max_(depthOfTree(t->left), depthOfTree(t->right));
    }
    else
    {
        return 0;
    }
}
int isAVL(Tree t)
{
	if (!t) return 1;
	if (isAVL(t->left) == 0) return 0;
	if (isAVL(t->right) == 0) return 0;

	int left = depthOfTree(t->left);
	int right = depthOfTree(t->right);
	int higher = max_(left, right);
	int lower = (left + right - higher);

	if (higher - lower > 1)
		return 0;
	return 1;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<isAVL(T);
	return 0;
}
