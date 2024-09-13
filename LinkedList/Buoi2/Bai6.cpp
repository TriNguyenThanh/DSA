/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};

//###INSERT CODE HERE -
void init(DList &l){
    l.pHead = l.pTail = nullptr;
}
DNode* getDNode(int x){
    DNode *p = new DNode;
    if (p == nullptr) return nullptr;

    p->pNext = p->pPrev = nullptr;
    p->info = x;

    return p;
}

void addTail(DList &l, int x){
    DNode*p = getDNode(x);
    if (l.pHead == nullptr){
        l.pHead = l.pTail = p;
    }else{
        p->pPrev = l.pTail;
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void addHead(DList &l, int x){
    DNode *p = getDNode(x);
    if (l.pHead == nullptr){
        l.pHead = l.pTail = p;
    }else{
        p->pNext = l.pHead;
        l.pHead->pPrev = p;
        l.pHead = p;
    }
}
DNode *find(DList l, int x){
    if (l.pHead == nullptr) return nullptr;
    DNode *p = l.pHead;
    while (p != nullptr)
    {
        if (p->info == x) return p;
        p = p->pNext;
    }
    return p;
    
}
void addAfter(DList &l, int x, int y){
    DNode *p = find(l, x);
    if (p == nullptr){
        cout << "\nCan't find the value "<<x;
    }else{
        if (p == l.pTail){
            addTail(l, y);
            return;
        }
        DNode *new_ele = getDNode(y);
        new_ele->pNext = p->pNext;
        new_ele->pPrev = p;
        p->pNext->pPrev = new_ele;
        p->pNext = new_ele;
    }
}
void addBefore(DList &l, int x, int y){
    DNode *p = find(l, x);
    if (p == nullptr){
        cout << "\nCan't find the value "<<x;
    }else{
        if (p == l.pHead){
            addHead(l, y);
            return;
        }
        DNode *new_ele = getDNode(y);
        new_ele->pNext = p;
        new_ele->pPrev = p->pPrev;
        p->pPrev->pNext = new_ele;
        p->pPrev = new_ele;
    }
}
void createList(DList &l){
    int x;
    while(1){
        cin >> x;
        if (x == -1) break;
        addTail(l, x);
    }
}
void printList(DList l){
    if (l.pHead == nullptr){
        cout << "List is empty";
        return;
    }
    DNode *p = l.pHead;
    while(p != nullptr){
        cout << p->info << ' ';
        p = p->pNext;
    }
}
int main()
{
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
