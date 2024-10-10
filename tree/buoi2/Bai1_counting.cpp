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
int depthOfTree(Tree t)
{
    if (t != nullptr)
    {
        if (t->left == nullptr && t->right == nullptr) return 0;
        return 1 + max_(depthOfTree(t->left), depthOfTree(t->right));
    }
    else
    {
        return 0;
    }
}
void countEven(Tree t, int& count)
{
    if (t != nullptr)
    {
        if (t->info % 2 == 0)
        {
            count++;
        }
        countEven(t->left, count);
        countEven(t->right, count);
    }
}
void countOdd(Tree t, int& count)
{
    if (t != nullptr)
    {
        if (t->info %2 != 0)
        {
            count++;
        }
        countOdd(t->left, count);
        countOdd(t->right, count);
    }
}
int countPositive(Tree t)
{
    if (t != nullptr)
    {
        int count = 0;
        if (t->info > 0) count++; 
        return count + countPositive(t->left) + countPositive(t->right);
    }
    else
    {
        return 0;
    }
}
int countNegative(Tree t)
{
    if (t != nullptr)
    {
        int count = 0;
        if (t->info < 0) count++; 
        return count + countNegative(t->left) + countNegative(t->right);
    }
    else
    {
        return 0;
    }
}
int countPrime(Tree t)
{
    if (t != nullptr)
    {
        int count = 0;
        if (is_prime(t->info)) count++; 
        return count + countPrime(t->left) + countPrime(t->right);
    }
    else
    {
        return 0;
    }
}
void listPrime(Tree t)
{   
    if (t != nullptr)
    {
        if (is_prime(t->info)) cout << t->info << ' ';
        listPrime(t->left);
        listPrime(t->right);
    }
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}
