/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
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
void swap(Node *p1, Node *p2){
    int tmp = p1->info;
    p1->info = p2->info;
    p2->info = tmp;
}
Node *min(List l, Node*start){
    Node *min_ = start;
    for(Node *p = start; p != NULL; p = p->pNext){
        if (p->info < min_->info) min_ = p;        
    }
    return min_;
}
void MySort(List &l){
    for(Node *p = l.pHead; p->pNext != NULL; p = p->pNext){
        Node *min_node = min(l, p);
        swap(min_node, p);
    }
}
int MySearch(List l, int x){
    int i = 0;
    Node *p = l.pHead;
    while (p!=nullptr)
    {
        if (p->info == x)
            return i;

        p = p->pNext;
        i++;
    }
    return -1;
}
void inputList(List &l, int n){
    int x;
    for (int i = 0; i < n; ++i){
        cin >> x;
        addTail(l, x);
    }
}
void outputList(List l){
    for(Node *p = l.pHead; p != NULL; p = p->pNext){
        cout << p->info << " ";
    }
}

int main()
{
    int n; cin>>n;
    List L;init (L);
    inputList(L,n);
    MySort(L);
    cout<<"Sorted List: ";
    outputList(L);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = MySearch(L,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

