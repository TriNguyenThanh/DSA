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
node *findElementFromEnd(List l, int i){
    if (l.pHead == nullptr){
        cout << "List is empty";
        return nullptr;
    }
    int n = 0;
    node *p = l.pHead;
    while(p != nullptr){
        n++;
        p = p->pNext;
    }
    if (i == 0 || i > n){
        cout << "The index is invalid";
        return nullptr;
    }
    
    else{
        node *ptr  = new node;
        ptr->pNext = l.pHead;
        int j = 0;
        do{
            j++;
            ptr = ptr->pNext;
        }while(j != n - i + 1);
        return ptr;
    }
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

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<" (from the end of L): ";
    node *p = findElementFromEnd(L,i);
    if(p) cout<<p->info;


    return 0;
}
