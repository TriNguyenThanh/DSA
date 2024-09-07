/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
struct Node{
    int info;
    Node *pNext;
};
struct List{
    Node *pHead, *pTail;
};

Node * getNode(int x){
    Node *p = new Node;
    p->info = x;
    p->pNext = nullptr;

    return p;
}
void addHead(List &l, int x){
    Node *p = getNode(x);
    if (l.pHead == nullptr) l.pHead = l.pTail = p;
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void addTail(List &l, int x){
    Node *p = getNode(x);
    if(l.pHead == nullptr) l.pHead = l.pTail = p;
    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void removeHead(List &l){
    if (l.pHead == nullptr) return;
    if (l.pHead == l.pTail){
        l.pTail = nullptr;
    }
    Node *p = l.pHead;
    l.pHead = l.pHead->pNext;
    p->pNext = nullptr;
    delete p;
}
Node *findElement(List l, int x){
    Node *p = l.pHead;
    while(p != nullptr){
        if (p->info == x) return p;
        p = p->pNext;
    }
    return p;
}
void addAfter(List &l, int a, int b){
    Node *p = l.pHead;
    Node *new_ptr = getNode(b);
    Node *pre_ptr = findElement(l, a);
    if (pre_ptr == l.pTail) addTail(l, b);
    else if (pre_ptr){
        new_ptr->pNext = pre_ptr->pNext;
        pre_ptr->pNext = new_ptr;
    }else addHead(l, b);
}
void printList(List l){
    Node *p = l.pHead;
    if (l.pHead == nullptr){
        cout << "blank";
        return;
    }
    while (p != nullptr){
        cout << p->info << ' ';
        p = p->pNext;
    }
}
void inputList(List &l){
    int x, a, b;
    Node *p = l.pHead;
    while(true){
        cin >> x;
        if (x == 0) {
            cin >> a;
            addHead(l, a);
        }
        else if(x == 1){
            cin >> a;
            addTail(l, a);
        }
        else if (x == 2){
            cin >> a >> b;
            addAfter(l, a, b);
        }else if (x == 5)
            removeHead(l);
        else if (x == 6) return;
    }
        p = p->pNext;
}
int main(){
    List l;
    l.pHead = l.pTail = nullptr;

    inputList(l);
    printList(l);

    return 0;
}