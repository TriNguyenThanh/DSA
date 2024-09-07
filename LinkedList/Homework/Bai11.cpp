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
node *findElement(List l, int x){
    node *p = l.pHead;
    while(p != nullptr){
        if (p->info == x) return p;
        p = p->pNext;
    }
    return p;
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
node *swapData(List &l, int x, int y){
    node *px = findElement(l, x);
    node *py = findElement(l, y);

    if (px && py){
        swap(px->info, py->info);
        return px;
    }else return nullptr;
}
int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L); // Neu ds rong thi xuat "List is empty"
    cout<<endl;

    int x, y; cin>>x>>y;
    node *p = swapData(L,x,y);
    /* Tim 2 node chua x va y,
    Hoan vi gia tri cua 2 node do,
    nghia la: Lien ket giua cac node khong thay doi, node ban dau chua x se doi lai la chua y
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi info cua 2 node khong
    Neu hoan vi info thi node chua x ban dau se doi lai chua y*/

    if(p) // co hoan vi
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
