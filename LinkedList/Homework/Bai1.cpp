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
void Init(List &l){
    l.pHead = l.pTail = nullptr;
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
void inputList(List &l, int n){
    int x;
    for(int i = 0; i < n; ++i){
        cin >> x;
        addTail(l, x);
    }
}
void outputList(List l){
    Node *p = l.pHead;
    if (l.pHead == nullptr){
        cout << "List is empty";
        return;
    }
    while (p != nullptr){
        cout << p->info << ' ';
        p = p->pNext;
    }
}
void addList(List &l, int m){
    int x;
    for(int i = 0; i < m; ++i){
        cin >> x;
        addHead(l, x);
    }
}

int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cout<<"Enter a number: "; cin>>n; // Nhap so luong phan tu cua ds
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n); // Nhap 1 day gom n so va luu vao ds. Phan tu moi duoc them vao cuoi ds
    cout<<"\nThe created Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"

    cout<<"\nEnter a number: "; int m; cin>>m; // Nhap so luong phan tu them vao dau ds
    cout<<"\nEnter a sequence of "<<m<<" numbers: ";
    addList(L,m); // Nhap 1 day gom m so va them phan tu moi vao dau ds
    cout<<"\nThe updated Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"

    return 0;
}
