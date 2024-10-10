/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
new
delete
using
###End banned keyword*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
    int x;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;   
        l.tail = p;
    }
}

void xuat(List &l){
    for(Node *p = l.head; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}


//###INSERT CODE HERE -
void print_longest_increasing_sub_list(List l)
{
    if (l.head == nullptr)
    {
        cout << '0';
        return;
    }
    if (l.head == l.tail)
    {
        cout << '1';
        return;
    }

    int prev_val = l.head->val;
    int count = 1;
    int max_count = 1;
    for (Node* p = l.head->next; p != nullptr; p = p->next)
    {
        if (p->val >= prev_val)
        {
            count++;
        }
        else
        {
            if (max_count < count) max_count = count;
            count = 1;
        }
        prev_val = p->val;
    }

    cout << max_count;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List l;

    list_initializing(l);
    int x;
    do{
        cin >> x;
        if (x != -1) add_tail(l, x);
        else break;
    } while(true);

    print_longest_increasing_sub_list(l);


    return 0;
}
