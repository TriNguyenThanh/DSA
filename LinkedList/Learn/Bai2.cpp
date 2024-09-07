/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
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
void printList(List l){
    Node *p = l.pHead;
    while (p != nullptr){
        cout << p->info << ' ';
        p = p->pNext;
    }
    
}
void input(List &l){
    int x, y;
    Node *p;
    while (1)
    {
        cin >> x;
        if (x == 3) break;
        if (x == 0){
            cin >> y;
            addHead(l, y);
        }else if(x == 1){
            cin >> y;
            addTail(l, y);
        }
    }
    
}
int main(){
    List l;
    l.pHead = l.pTail = nullptr;
    input(l);

    printList(l);
}