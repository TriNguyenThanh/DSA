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

void init(DList &l)
{
    l.pHead = l.pTail = nullptr;
}
DNode* getDNode(int x)
{
    DNode *ptr = new DNode;
    ptr->info = x;
    ptr->pNext = ptr->pPrev = nullptr;

    return ptr;
}
DNode* findDNode(DList l, int x)
{
    DNode* ptr = l.pHead;
    while (ptr!=nullptr)
    {
        if (ptr->info == x)
            return ptr;
        ptr = ptr->pNext;
    }
    return nullptr;
}
void printList(DList l){
    if (l.pHead == nullptr)
    {
        cout<<"List is empty";
        return;
    }
    for (DNode *p = l.pHead; p != nullptr; p = p->pNext)
    {
        cout << p->info << ' ';
    }
}
void addHead(DList &l, int x)
{
    DNode* ptr = getDNode(x);
    if (l.pHead == nullptr)
        l.pHead = l.pTail = ptr;
    else
    {
        ptr->pNext = l.pHead;
        l.pHead->pPrev = ptr;
        l.pHead = ptr;
    }
}
void addTail(DList &l, int x)
{
    DNode* ptr = getDNode(x);
    if (l.pHead == nullptr)
        l.pHead = l.pTail = ptr;
    else
    {
        ptr->pPrev = l.pTail;
        l.pTail->pNext = ptr;
        l.pTail = ptr;
    }
}
void createList(DList &l)
{
    int x; cin >> x;
    while (x != -1)
    {
        addTail(l, x);
        cin >> x;
    }    
}
void addAfter(DList &l, int x, int y)
{
    if (l.pHead == nullptr) return;
    DNode* ptr = findDNode(l, x);
    if (ptr == nullptr){
        cout << "\nCan't find the value "<<x;
        return;
    }
    
    DNode* newDNode = getDNode(y);
    if (newDNode == nullptr) return;

    if (ptr == l.pTail)
    {
        addTail(l, y);
        return;
    }

    newDNode->pNext = ptr->pNext;
    ptr->pNext->pPrev = newDNode;
    newDNode->pPrev = ptr;
    ptr->pNext = newDNode;
}
void addBefore(DList &l, int x, int y)
{
    if (l.pHead == nullptr) return;
    DNode* ptr = findDNode(l, x);
    if (ptr == nullptr)
    {
        cout << "\nCan't find the value "<<x;
        return;
    }
    
    DNode* newDNode = getDNode(y);
    if (newDNode == nullptr) return;

    if (ptr == l.pHead)
    {
        addHead(l, y);
        return;
    }

    newDNode->pNext = ptr;
    newDNode->pPrev = ptr->pPrev;
    ptr->pPrev->pNext = newDNode;
    ptr->pPrev = newDNode;
}
void addAfterMulti(DList &l, int x, int y)
{
    DNode *p = findDNode(l, x);
    if (p == nullptr)
    {
        cout << "\nCan't find the value "<<x;
        return;
    }
    while (p != nullptr)
    {
        if (p->info == x)
        {
            if (p == l.pTail)
            {
                addTail(l, y);
                return;
            }
            else
            {
                DNode* newDNode = getDNode(y);
                newDNode->pNext = p->pNext;
                p->pNext->pPrev = newDNode;
                p->pNext = newDNode;
                newDNode->pPrev = p;

                p = p->pNext;
            }
        }
        else
        {
            p = p->pNext;
        }
    }
}
void addBeforeMulti(DList &l, int x, int y)
{
    DNode* p = findDNode(l, x);
    if (p == nullptr)
    {
        cout << "\nCan't find the value "<<x;
        return;
    }
    
    while (p != nullptr)
    {
        if (p->info == x)
        {
            if (p == l.pHead)
            {
                addHead(l, y);
            }
            else
            {
                DNode* newDNode = getDNode(y);

                newDNode->pNext = p;
                p->pPrev->pNext = newDNode;
                newDNode->pPrev = p->pPrev;
                p->pPrev = newDNode;
            }
        }
        p = p->pNext;
    }
}
void removeHead(DList &l)
{
    if (l.pHead == nullptr)
    {
        cout<<"\nList is empty. Can't delete";
        return;
    }
    cout<<"\nDo you want to delete the first element?(y/n): ";
    char user_input; cin >> user_input;
    
    if (user_input == 'n' || user_input == 'N') return;
    else if (user_input == 'y' || user_input == 'Y')
    {
        DNode* p = l.pHead;
        if (l.pHead == l.pTail)
        {
            l.pHead = l.pTail = nullptr;
            cout << "\nThe list becomes empty";
        }
        else
        {
            l.pHead = l.pHead->pNext;
            l.pHead->pPrev = nullptr;
        }
        delete p;
        p = nullptr;
    }
}
void removeTail(DList &l)
{
    if (l.pHead == nullptr)
    {
        cout<<"\nList is empty. Can't delete";
        return;
    }
    cout<<"\nDo you want to delete the last element?(y/n): ";
    char user_input; cin >> user_input;
    
    if (user_input == 'n' || user_input == 'N') return;
    else if (user_input == 'y' || user_input == 'Y')
    {
        DNode* p = l.pTail;
        if (l.pHead == l.pTail)
        {
            l.pHead = l.pTail = nullptr;
            cout << "\nThe list becomes empty";
        }
        else
        {
            l.pTail = l.pTail->pPrev;
            l.pTail->pNext = nullptr;
        }
        delete p;
        p = nullptr;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	DList L;
	init(L);
	int x,y,choice; char c;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n9. Delete the first element";
    cout<<"\n10. Delete the last element";
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
        case 7:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfterMulti(L,x,y);
            break;
        case 8:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBeforeMulti(L,x,y);
            break;
        case 9:
            removeHead(L);
            break;
        case 10:
            removeTail(L);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;
        }
    }

	return 0;
}