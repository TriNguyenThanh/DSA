/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
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
void addAfter(List &l, int a, int b){
    node *p = l.pHead;
    node *new_ptr = getnode(b);
    while(p != nullptr){
        if (p->info == a){
            if (p->pNext ==nullptr){
                addTail(l, b);
                return;
            }
            new_ptr->pNext = p->pNext;
            p->pNext = new_ptr;
            return;
        }
        p = p->pNext;
    }
    addHead(l, b);
}
node *findElement(List l, int x){
    if (l.pHead == nullptr) return nullptr;
    node *p = l.pHead;
    while(p != nullptr){
        if (p->info == x) return p;
        p = p->pNext;
    }
    return p;
}
void removeHead(List &l){
    if (l.pHead == nullptr) return;
    if (l.pHead == l.pTail){
        l.pTail = nullptr;
    }
    node *p = l.pHead;
    l.pHead = l.pHead->pNext;
    p->pNext = nullptr;
    delete p;
}
void remove(List &l, int x){
    if (l.pHead == nullptr) return;
    node* rm = l.pHead;
    node* p = nullptr;
    while(rm != nullptr){
        if (rm->info == x){
            if (rm == l.pHead){
                removeHead(l);
            }
            else if (rm == l.pTail){
                p->pNext = nullptr;
                l.pTail = p;

                delete rm;
                rm = nullptr;
            }
            else {
                p->pNext = rm->pNext;
                rm->pNext = nullptr;
                delete rm;
                rm = nullptr;
            }
            return;
        }
        p = rm;
        rm = rm->pNext;
    }
}
void multiRemove(List &l, int x){
    if (l.pHead == nullptr) return;
    node *p = l.pHead;
    while(findElement(l, x) != nullptr){
        remove(l, x);
    }
}
void inputList(List &l){
    int x, y, a, b;
    while (1)
    {
        cin >> x;
        switch (x)
        {
        case 0:
            cin >> y;
            addHead(l, y);
            break;
        case 1:
            cin >> y;
            addTail(l, y);
            break;
        case 2:
            cin >> a >> b;
            addAfter(l, a, b);
            break;
        case 3:
            cin >> y;
            remove(l, y);
            break;
        case 4:
            cin >> y;
            multiRemove(l, y);
            break;
        case 5:
            removeHead(l);
            break;
        case 6:
            return;
        }
    }
}
void outputList(List l){
    node *p = l.pHead;
    if (l.pHead == nullptr){
        cout << "blank";
        return;
    }
    while (p != nullptr){
        cout << p->info << ' ';
        p = p->pNext;
    }
}

int main(){
    List l;
    Init(l);
    inputList(l);
    outputList(l);

    return 0;
}