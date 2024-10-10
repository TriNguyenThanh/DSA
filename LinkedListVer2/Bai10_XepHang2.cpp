#include <iostream>
using namespace std;

#define MAXN 100005

struct Node
{
    int mssv;
    Node *pNext;
};
struct List
{
    Node* pHead;
    Node* pTail;
};

Node* nodeList[MAXN];

void init(List &l)
{
    l.pHead = l.pTail = nullptr;
}
Node* getNode(int x)
{

    Node *newNode = new Node;
    newNode->mssv = x;
    newNode->pNext = nullptr;

    return newNode;
}

void deleteNode(List &l, int x)
{   

    Node* prevNode = nodeList[x];
    if (prevNode == nullptr)
    {
        cout << "\nCant create prevNode with value " << x;
        return;
    }
    if (l.pTail->mssv == x)
    {
        l.pTail = prevNode;

        nodeList[x] = nullptr;
        delete l.pTail->pNext;
        l.pTail->pNext = nullptr;
    }
    else if (l.pHead->mssv != x)
    {
        Node* p = prevNode->pNext;
        prevNode->pNext = p->pNext;
        nodeList[p->pNext->mssv] = prevNode;
        p->pNext = nullptr;
        nodeList[p->mssv] = nullptr;
        delete p;
        p = nullptr;
    }
}
void addHead(List &l, int x)
{   

    Node* p = getNode(x);
    if (p == nullptr)
    {
        cout << "\nCant create p head node with value " << x;
        return;
    }

    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
        nodeList[l.pHead->mssv] = nullptr;
    }
    else
    {
        p->pNext = l.pHead;
        nodeList[l.pHead->mssv] = p;

        l.pHead = p;
        nodeList[l.pHead->mssv] = nullptr;
    }
}
void addTail(List &l, int x)
{

    Node *p = getNode(x);
    if (p == nullptr)
    {
        cout << "\nCant create tail node with value " << x;
        return;
    }
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
        nodeList[x] = nullptr;
    }
    else
    {
        nodeList[x] = l.pTail;
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void createList(List &l, int n)
{   
    for (int i = 1; i <= n; ++i)
    {
        addTail(l, i);
    }
}
void move(List &l, int x)
{

    if (l.pHead == nullptr) return;
    if (l.pHead->mssv == x) return;

    deleteNode(l, x);
    addHead(l, x);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, x; cin >> n >> m;
    List l;
    init(l);
    createList(l, n);
    
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        move(l, x);
        cout << l.pTail->mssv << ' ';
    }
    return 0;
}
