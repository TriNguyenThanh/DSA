/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -
struct node{
    int info;
    node *pNext;
};

struct List{
    node *pHead, *pTail;
};

node * getnode(int x){
    node *p = new node;
    p->info = x;
    p->pNext = nullptr;

    return p;
}
void Init(List &l){
    l.pHead = l.pTail = nullptr;
}

void addHead(List &l, int x){
    node *p = getnode(x);
    if (l.pHead == nullptr) l.pHead = l.pTail = p;
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void addTail(List &l, int x){
    node *p = getnode(x);
    if(l.pHead == nullptr) l.pHead = l.pTail = p;
    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void inputList(List &l, int n){
    int x;
    for(int i = 0; i < n; ++i){
        cin >> x;
        addTail(l, x);
    }
}
void outputList(List l){
    node *p = l.pHead;
    if (l.pHead == nullptr){
        cout << "List is empty";
        return;
    }
    while (p != nullptr){
        cout << p->info << ' ';
        p = p->pNext;
    }
}
node *findMax(List l){
    if (l.pHead == nullptr){
        cout << "List is empty";
        return nullptr;
    }
    int max = l.pHead->info;
    node *p = l.pHead;
    node *p_max = p;
    while (p != nullptr){
        if (p->info > max){
            p_max = p;
            max = p->info;
        }
        p = p->pNext;
    }
    return p_max;
}
int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);


    cout<<"\nThe maximum value: ";
    node *p = findMax(L);
    if(p) cout<<p->info;

    return 0;
}
