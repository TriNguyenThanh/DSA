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
node *findMiddle(List l){
    if (l.pHead == nullptr) return nullptr;
    int n = 0;
    node *p = l.pHead;
    while(p != nullptr){
        n++;
        p = p->pNext;
    }
    //cout << "\nn = " << n << '\n';
    int mid;
    if (n == 1) mid = 1;
    else if (n == 2 || n == 3) mid = 2;
    else mid = (n/2) + 1;
    p = l.pHead;
    for (int i = 0; i < mid-1; ++i){
        p = p->pNext;
    }
    return p;
}
int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    node *p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"The middle element is "<<p->info;

    return 0;
}
