/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multi_set
map
unordered_map
include
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Customer{
    int order;
    string food;
};

struct Node{
    Customer info;
    Node *pNext;
};
struct List{
    Node *pHead, *pTail;
};

Node * getNode(Customer x){
    Node *p = new Node;
    p->info = x;
    p->pNext = nullptr;

    return p;
}

void addTail(List &l, Customer x){
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

void printList(List l){
    Node *p = l.pHead;
    if (p == nullptr){
        cout << "Tiem qua e, khong co khach nao";
        return;
    }
    while (p != nullptr){
        cout << p->info.order << ' ' << p->info.food << '\n';
        p = p->pNext;
    }
}
void input(List &l){
    int i = 1, x;
    Customer cus;
    while(true){
        cin >> x;
        cin.ignore();
        if (x == -1) break;
        if (x == 0){
            cin >> cus.food;
            cus.order = i++;
            addTail(l, cus);
        }else if(x == 1){
            removeHead(l); 
        }
    }
}

int main(){
    List l;
    l.pHead = l.pTail = nullptr;
    input(l);
    printList(l);
    return 0;
}
