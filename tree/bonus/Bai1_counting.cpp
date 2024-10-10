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
int max_(int a, int b)
{
    return (a < b) ? b: a;
}
bool is_prime(int n)
{   
    if (n <= 1) return 0;
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0) return 0;
    }
    return 1;
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
int countNodes(Tree t)
{
    if (t != nullptr)
    {
        return (1 + countNodes(t->left) + countNodes(t->right));
    }
    else
    {
        return 0;
    }
}
int countLeafs(Tree t)
{
	if (t != nullptr)
    {
		if (t->left == nullptr && t->right == nullptr) return 1;
        return (countLeafs(t->left) + countLeafs(t->right));
    }
    else
    {
        return 0;
    }
}
int countInternalNodes(Tree t)
{
	return countNodes(t) - countLeafs(t) - 1;
}
int countOneChild(Tree t)
{
	if (t != nullptr)
    {
		int count = 0;
		if (t->left == nullptr && t->right == nullptr) return 0;
		if (t->left == nullptr || t->right == nullptr) count++;
        return (count + countOneChild(t->left) + countOneChild(t->right));
    }
    else
    {
        return 0;
    }
}
int countTwoChildren(Tree t)
{
	if (t != nullptr)
    {
		int count = 0;
		if (t->left != nullptr && t->right != nullptr) count++;
        return (count + countTwoChildren(t->left) + countTwoChildren(t->right));
    }
    else
    {
        return 0;
    }
}
int countLess(Tree t, int x)
{
	if (t != nullptr)
    {
		int count = 0;
		if (t->info < x) count++;
        return (count + countLess(t->left, x) + countLess(t->right, x));
    }
    else
    {
        return 0;
    }
}
int countBetweenValues(Tree t, int x, int y)
{
	if (t != nullptr)
    {
		int count = 0;
		if (t->info > x && t->info < y) count++;
        return (count + countBetweenValues(t->left,x,y) + countBetweenValues(t->right,x,y));
    }
    else
    {
        return 0;
    }
}
int main()
{
	Tree T = NULL;
	inputTree(T);

    cout<<"Number of nodes: " << countNodes(T)<<endl;
	cout<<"Number of leaf nodes: " << countLeafs(T)<<endl;
	cout<<"Number of internal nodes: "<< countInternalNodes(T)<<endl;
	cout<<"Number of nodes with one child: "<< countOneChild(T)<<endl;
	cout<<"Number of nodes with two children: "<< countTwoChildren(T)<<endl;

	int x;cout<<"Enter x: ";cin>>x;
	cout<<"\nNumber of nodes less than "<<x<<": "<< countLess(T,x)<<endl;
	int y; cout<<"Enter x,y: ";cin>>x>>y;
	cout<<"\nNumber of nodes greater than "<<x<<" and less than "<<y<<": "<< countBetweenValues(T,x,y)<<endl;

	return 0;
}
