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
void removeNode(DList &l, int x)
{
    DNode* p = findDNode(l, x);
    if (p == nullptr)
    {
        cout << "\nCan't find the value "<<x;
        return;
    }
    cout<<"\nDo you want to delete "<<x<<" ?(y/n): ";
    char user_input; cin >> user_input;
    if (user_input == 'n' || user_input == 'N') return;
    else if (user_input == 'y' || user_input == 'Y')
    {
        if (p == l.pHead)
        {
            if (l.pHead == l.pTail)
            {
                l.pHead = l.pTail = nullptr;
            }
            else
            {
                l.pHead = l.pHead->pNext;
                l.pHead->pPrev = nullptr;
            }
        }
        else if (p == l.pTail)
        {
            if (l.pHead == l.pTail)
            {
                l.pHead = l.pTail = nullptr;
            }
            else
            {
                l.pTail = l.pTail->pPrev;
                l.pTail->pNext = nullptr;
            }
        }
        else
        {
            p->pPrev->pNext = p->pNext;
            p->pNext->pPrev = p->pPrev;

            p->pPrev = nullptr;
            p->pNext = nullptr;      
        }

        delete p;
        p = nullptr;
        if (l.pHead == nullptr)
        {
            cout<<"\nThe list becomes empty";
        }
    }
}
void removeMultiNodeS(DList &l, int x)
{
    DNode* p = findDNode(l, x);
    if (p == nullptr)
    {
        cout << "\nCan't find the value "<<x;
        return;
    }
    cout<<"\nDo you want to delete "<<x<<"s ?(y/n): ";
    char user_input; cin >> user_input;
    
    if (user_input == 'n' || user_input == 'N') return;
    else if (user_input == 'y' || user_input == 'Y')
    {
        DNode *nextDNode = nullptr;
        while (p != nullptr)
        {
            nextDNode = p->pNext;
            if (p->info == x)
            {
                DNode* p = findDNode(l, x);
                if (p == nullptr) return;
                if (p == l.pHead)
                {
                    if (l.pHead == l.pTail)
                    {
                        l.pHead = l.pTail = nullptr;
                    }
                    else
                    {
                        l.pHead = l.pHead->pNext;
                        l.pHead->pPrev = nullptr;
                    }
                }
                else if (p == l.pTail)
                {
                    if (l.pHead == l.pTail)
                    {
                        l.pHead = l.pTail = nullptr;
                    }
                    else
                    {
                        l.pTail = l.pTail->pPrev;
                        l.pTail->pNext = nullptr;
                    }
                }
                else
                {
                    p->pPrev->pNext = p->pNext;
                    p->pNext->pPrev = p->pPrev;

                    p->pPrev = nullptr;
                    p->pNext = nullptr;      
                }

                delete p;
                p = nullptr;
            }
            p = nextDNode;
        }
        if (l.pHead == nullptr)
        {
            cout<<"\nThe list becomes empty";
        }
    }
}
void removeAfter(DList &l, int x)
{
    DNode* p = findDNode(l, x);
    if (p == nullptr)
    {
        cout << "\nCan't find the value "<<x;
        return;
    }
    if (p == l.pTail)
    {
        cout<<endl<<x<<" is the last element. Can't delete the element after it";
        return;
    }
    cout<<"\nDo you want to delete the element after "<<x<<" ?(y/n): ";
    char user_input; cin >> user_input;
    
    if (user_input == 'n' || user_input == 'N') return;
    else if (user_input == 'y' || user_input == 'Y')
    {
        DNode *deletedNode = p->pNext;
        if (deletedNode == l.pTail)
        {
            l.pTail = l.pTail->pPrev;
            l.pTail->pNext = nullptr;
            deletedNode->pPrev = nullptr;
        }
        else
        {
            p->pNext = deletedNode->pNext;
            deletedNode->pNext->pPrev = p;
            deletedNode->pNext = nullptr;
            deletedNode->pPrev = nullptr;
        }
        delete deletedNode;
        deletedNode = nullptr;
    }
}
void removeBefore(DList &l, int x)
{
    DNode* p = l.pTail;
    while (p!=nullptr)
    {
        if (p->info ==x)
            break;
        p = p->pPrev;
    }
    
    if (p == nullptr)
    {
        cout << "\nCan't find the value "<<x;
        return;
    }
    if (p == l.pHead)
    {
        cout<<endl<<x<<" is the first element. Can't delete the element before it";
        return;
    }
    cout<<"\nDo you want to delete the element before "<<x<<" ?(y/n): ";
    char user_input; cin >> user_input;
    
    if (user_input == 'n' || user_input == 'N') return;
    else if (user_input == 'y' || user_input == 'Y')
    {
        p = findDNode(l, x);
        if (p == l.pHead) p = p->pNext;
        while (p != nullptr)
        {
            if (p->info == x) break;
            p = p->pNext;
        }
        if (p == nullptr) return;
        
        DNode* deleteNode = p->pPrev;
        if (deleteNode == l.pHead)
        {
            l.pHead = l.pHead->pNext;
            l.pHead->pPrev = nullptr;
            deleteNode->pNext = nullptr;
        }
        else
        {
            deleteNode->pPrev->pNext = p;
            p->pPrev = deleteNode->pPrev;
            deleteNode->pNext = nullptr;
            deleteNode->pPrev = nullptr;
        }
        delete deleteNode;
        deleteNode = nullptr;
    }
}
void removeMultiAfters(DList &l, int x)
{
    DNode* p = findDNode(l, x);
    if (p == nullptr)
    {
        cout << "\nCan't find the value "<<x;
        return;
    }
    if (p == l.pTail)
    {
        cout<<"\nList has only one "<<x<<" and "<<x<<" is the last element. Can't delete the element after it";
        return;
    }    
    cout<<"\nDo you want to delete the element after "<<x<<" ?(y/n): ";
    char user_input; cin >> user_input;
    
    if (user_input == 'n' || user_input == 'N') return;
    else if (user_input == 'y' || user_input == 'Y')
    {
        while (p!= nullptr)
        {
            if (p->info == x)
            {
                DNode *deletedNode = p->pNext;
                if (deletedNode == l.pTail)
                {
                    l.pTail = l.pTail->pPrev;
                    l.pTail->pNext = nullptr;
                    deletedNode->pPrev = nullptr;
                }
                else
                {
                    p->pNext = deletedNode->pNext;
                    deletedNode->pNext->pPrev = p;
                    deletedNode->pNext = nullptr;
                    deletedNode->pPrev = nullptr;
                }
                delete deletedNode;
                deletedNode = nullptr;
            }
            p = p->pNext;
        }
    }
}
void removeMultiBefores(DList &l, int x)
{
    DNode* p = l.pTail;
    while (p!=nullptr)
    {
        if (p->info == x)
            break;
        p = p->pPrev;
    }
    
    if (p == nullptr)
    {
        cout << "\nCan't find the value "<<x;
        return;
    }
    if (p == l.pHead)
    {
        cout<<"\nList has only one "<<x<<" and "<<x<<" is the first element. Can't delete the element before it";
        return;
    }    
    cout<<"\nDo you want to delete all elements before "<<x<<" ?(y/n): ";
    char user_input; cin >> user_input;
    
    if (user_input == 'n' || user_input == 'N') return;
    else if (user_input == 'y' || user_input == 'Y')
    {
        p = findDNode(l, x);
        if (p == l.pHead) p = p->pNext;
        while (p != nullptr)
        {
            if (p->info == x) break;
            p = p->pNext;
        }
        if (p == nullptr) return;

        while (p != nullptr)
        {
            if (p->info == x)
            {
                DNode* deleteNode = p->pPrev;
                if (deleteNode == l.pHead)
                {
                    l.pHead = l.pHead->pNext;
                    l.pHead->pPrev = nullptr;
                    deleteNode->pNext = nullptr;
                }
                else
                {
                    deleteNode->pPrev->pNext = p;
                    p->pPrev = deleteNode->pPrev;
                    deleteNode->pNext = nullptr;
                    deleteNode->pPrev = nullptr;
                }
                delete deleteNode;
                deleteNode = nullptr;
            }
            p = p->pNext;
        }
    }
}
void removeAll(DList &l)
{
    cout<<"\nDo you want to delete all elements?(y/n): ";
    char user_input; cin >> user_input;
    
    if (user_input == 'n' || user_input == 'N') return;
    else if (user_input == 'y' || user_input == 'Y')
    {
        DNode *p = l.pHead;
        while (l.pHead != nullptr)
        {
            p = l.pHead;
            l.pHead = l.pHead->pNext;
            p->pNext = nullptr;
            if (l.pHead != nullptr)
                l.pHead->pPrev = nullptr;

            delete p;
            p = nullptr;
        }
    }
    cout<<"\nThe list becomes empty";
}
int main()
{
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
    cout<<"\n11. Delete the first element containing a specific value";
    cout<<"\n12. Delete all elements storing a particular value";
    cout<<"\n13. Delete the element after a specific value (only for the first one found)";
    cout<<"\n14. Delete the element before a specific value (only for the first one found)";
    cout<<"\n15. Delete all elements after a specific value";
    cout<<"\n16. Delete all elements before a specific value";
    cout<<"\n17. Delete all elements";
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
        case 11:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeNode(L,x);
            break;
        case 12:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiNodeS(L,x);
            break;
        case 13:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeAfter(L,x);
            break;
        case 14:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeBefore(L,x);
            break;
        case 15:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiAfters(L,x);
            break;
        case 16:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiBefores(L,x);
            break;
        case 17:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            removeAll(L);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
