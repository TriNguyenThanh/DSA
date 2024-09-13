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
bool is_subsequence(List l1, List l2){
    Node *ptr1 = l1.head;
    Node *ptr2 = l2.head;
    int n1 = 0, n2 = 0;
    while(ptr1 != nullptr){
        n1++;
        ptr1 = ptr1->next;
    }
    while(ptr2 != nullptr){
        n2++;
        ptr2 = ptr2->next;
    }
    ptr1 = l1.head;
    ptr2 = l2.head;
    if (n1 >= n2){
        if (l1.head == nullptr && l2.head != nullptr) return false;
        if (l2.head == nullptr) return true;
        while (ptr1 != nullptr)
        {
            if (ptr1->val == ptr2->val){
                ptr2 = ptr2->next;
                if (ptr2 == nullptr)
                    return true;
            }
            ptr1 = ptr1->next;
        }
        return false;
    }else{
        if (l2.head == nullptr && l1.head != nullptr) return false;
        if (l1.head == nullptr) return true;
        while (ptr2 != nullptr)
        {
            if (ptr2->val == ptr1->val){
                ptr1 = ptr1->next;
                if (ptr1 == nullptr)
                    return true;
            }
            ptr2 = ptr2->next;
        }
        return false;
    }

}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List lists[2];

    for(int i = 0; i < 2; i++){
        list_initializing(lists[i]);
        int x;
        do{
            cin >> x;
            if (x != -1) add_tail(lists[i], x);
            else break;
        } while(true);
    }

    if ( is_subsequence(lists[0], lists[1])) cout << "TRUE";
    else cout << "FALSE";


    return 0;
}
