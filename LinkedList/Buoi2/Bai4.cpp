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
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
