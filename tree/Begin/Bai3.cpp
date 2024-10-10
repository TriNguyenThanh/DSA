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
void listLeafs(Tree t){
	if (t->left == nullptr && t->right == nullptr){
		cout << t->info << ' ';
		return;
	}else if (t->left != nullptr && t->right != nullptr){
		listLeafs(t->left);
		listLeafs(t->right);
	}else if (t->left != nullptr){
		listLeafs(t->left);
	}else
		listLeafs(t->right);
}
void listInternalNodes(Tree t, int x){
	if (x == 0){
		listInternalNodes(t->left, ++x);
		listInternalNodes(t->right, ++x);
	}else{
		if (t->left != nullptr || t->right != nullptr){
			cout << t->info << ' ';
		}
		if (t->left != nullptr)
			listInternalNodes(t->left, ++x);
		if (t->right != nullptr)
			listInternalNodes(t->right, ++x);
	}
}
void listNodesWithOneChild(Tree t){
	if (t->left == nullptr && t->right == nullptr) return;
	else if (t->left != nullptr && t->right == nullptr){
		cout << t->info << ' ';
		listNodesWithOneChild(t->left);
	}
	else if (t->right != nullptr && t->left == nullptr){
		cout << t->info << ' ';
		listNodesWithOneChild(t->right);
	}
}
void listNodesWithTwoChildren(Tree t){
	if (t->left == nullptr || t->right == nullptr) return;
	else{
		cout << t->info << ' ';
		listNodesWithTwoChildren(t->left);
		listNodesWithTwoChildren(t->right);
	}
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	cout<<"\nLeaf nodes: "; listLeafs(T);
	cout<<"\nInternal nodes: "; listInternalNodes(T,0);
	cout<<"\nNodes with one child: "; listNodesWithOneChild(T);
	cout<<"\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}
