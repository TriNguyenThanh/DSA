#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -

struct Province
{
    int id;
    string name;
    int pop;
    float area;
};

struct Node
{
    Province info;
    Node* pNext;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

void init(List& l) {
    l.pHead = l.pTail = nullptr;
}

void addTail(List& l, Node* p) {
    if (p == nullptr) return;
    if (l.pHead == nullptr) {
        l.pHead = l.pTail = p;
    }
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

Node* find(List& l, string province_name) {
    for (Node* p = l.pHead; p != NULL; p = p->pNext) {
        if (p->info.name == province_name) return p;
    }
    return nullptr;
}

bool renmoveEle(List& l, string name) {
    if (l.pHead == nullptr){
        cout << "List is empty" << endl;
        return false;
    }
    Node* rm = find(l, name);
    if (rm == nullptr) return false;
    
    if (rm == l.pHead)
    {
        l.pHead = l.pHead->pNext;
        rm->pNext = nullptr;

        delete rm;
        rm = nullptr;
        return true;
    }
    else if (rm == l.pTail)
    {
        Node *p = l.pHead;
        while(p->pNext != l.pTail)
        {
            p = p->pNext;
        }
        l.pTail = p;
        l.pTail->pNext = nullptr;

        delete rm;
        rm = nullptr;
        return true;
    }
    else
    {
        for (Node* p = l.pHead; p != NULL; p = p->pNext) {
            if (p->pNext == rm) {
                p->pNext = rm->pNext;
                rm->pNext = nullptr;
                delete rm;
                rm = nullptr;
                return true;
            }
        }
    }
    return false;
}

void input(List& l, int n) {
    for (int i = 0; i < n; ++i) {
        Node* p = new Node;
        p->pNext = nullptr;

        cin >> p->info.id;
        cin.ignore();
        getline(cin, p->info.name);
        cin >> p->info.pop >> p->info.area;

        addTail(l, p);
    }
}
void output(List L) {
    if (L.pHead == nullptr) {
    	cout << "ID\t|Province\t|Population\t|Area" << endl;
        cout << "List is empty" << endl;
        return;
    }
    
    cout << "ID\t|Province\t|Population\t|Area" << endl;
    Node* temp = L.pHead;
    while (temp != nullptr) {
        cout << temp->info.id << "\t" << temp->info.name << "\t" 
             << temp->info.pop << "\t"  << temp->info.area << endl;
        temp = temp->pNext;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    List l; init(l);
    input(l, n);
    cout << "List of provinces:\n";
    output(l);
    if (n == 0) return 0;
    cout << "Enter the name of the province you want to delete:\n";
    std::string name;   
    cin.ignore();
    getline(cin, name);
    Node *x = find(l, name);
    if (x == nullptr){
        cout << "Not found\n";
        return 0;
    }
    renmoveEle(l, name);
    cout << "Updated List:\n";
    output(l);

    return 0;
}