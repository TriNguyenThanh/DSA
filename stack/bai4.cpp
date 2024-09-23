/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

/*Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct Stack
{
	List L;
};

Cach 2: Cai dat lai Stack tu dau, giong nhu List
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};*/

//###INSERT CODE HERE -
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead;
};

node* getNode(int x){
    node* new_node = new node;
    new_node->info = x;
    new_node->next = nullptr;
    return new_node;
}

void Init(Stack &s){
    s.pHead = NULL;
}

bool isEmpty(Stack s){
    return s.pHead == NULL;
}

void Push(Stack &s, int x){
    node* NODE = getNode(x);
    if (s.pHead == NULL){
        s.pHead = NODE;
        return;
    }
    NODE->next = s.pHead;
    s.pHead = NODE;
}

void printStack(Stack s){
    if (isEmpty(s)){
        cout << "0";
        return;
    }
    node *p = s.pHead;
    while (p != nullptr)
    {
        cout << p->info;
        p = p->next;
    }
    
    
}
void DecimaltoBinary1(int x, Stack &s){
    int du = x;
    while(true){
        if (du == 0) return;
        else if (du == 1){
            Push(s, 1);
            return;
        }
        else if (du >= 2){
            Push(s, du%2);
            du /= 2;
        }
    }
}
int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}

