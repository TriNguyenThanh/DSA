/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
struct Node
{
    int info;
    Node *pNext;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

Node* getNode(int x){
    Node *ptr = new Node;
    if (ptr != nullptr){
        ptr->info = x;
        ptr->pNext = nullptr;
    }

    return ptr;
}

void init(List &l){
    l.pHead = l.pTail = nullptr;
}
void addHead(List &l, int x){
    Node *p = getNode(x);
    if (p == nullptr) return;
    if (l.pHead == nullptr){
        l.pHead = l.pTail = p;
    }else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void removeHead(List &l){
    Node *p = l.pHead;
    if (l.pHead == nullptr) return;
    if (l.pHead == l.pTail){
        l.pHead = l.pTail = nullptr;
        delete p;
        p = nullptr;
    }else{
        l.pHead = l.pHead->pNext;
        p->pNext = nullptr;
        delete p;
        p = nullptr;
    }
}
void addTail(List &l, int x){
    Node *p = getNode(x);
    if (p == nullptr) return;
    if (l.pHead == nullptr){
        l.pHead = l.pTail = p;
    }else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void removeTail(List &l){
    Node *p = l.pHead;
    if (l.pHead == nullptr) return;
    if (l.pHead == l.pTail){
        l.pHead = l.pTail = nullptr;
        delete p;
        p = nullptr;
    }else{
        while(p->pNext != l.pTail){
            p = p->pNext;
        }
        delete l.pTail;
        p->pNext = nullptr;
        l.pTail = p;
    }
}
void input(List &l){
    int n; cin >> n;
    char a, b; int x;
    for (int i = 0; i<n; ++i){
        cin >> a >> b >> x;
        if (a == '+'){
            if (b == 'H') addHead(l, x);
            else if (b == 'T') addTail(l, x);
        }else if (a == '-'){
            if (b == 'H') removeHead(l);
            else if (b == 'T') removeTail(l);
        }
    }
}
void output(List l){
    Node *p = l.pHead;
    while(p != nullptr){
        cout << p->info << ' ';
        p = p->pNext;
    }
}

int main(){
    List l;
    init(l);
    input(l);
    output(l);

    return 0;
}