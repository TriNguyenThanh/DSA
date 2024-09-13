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
typedef struct PROVINCE{
    int ID;
    string NAME;
    int POP;
    float AREA;
}pro;

struct node{
    pro info;
    node* pNext;
};

struct List{
    node* pHead;
    node* pTail;
};

void Init(List &l){
    l.pHead = l.pTail = nullptr;
}
node* getnode(pro x){
    node * tmp = new node;
    tmp->info = x;

    return tmp;
}

void addTail(List &l, pro temp){
    node* p = getnode(temp);
    if(l.pHead == nullptr) l.pHead = l.pTail = p;
    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}


void inputProvince(pro &province){
    cin >> province.ID;
    cin.ignore();
    getline(cin, province.NAME);
    cin >> province.POP >> province.AREA;
}
void outputProvince(pro province){
    cout << province.ID << '\t' << province.NAME << '\t' << province.POP << '\t' << province.AREA;
}
void inputListProvinces(List &l){
    int n; cin >> n;
    pro tmp;
    for (int i = 0; i < n; ++i){
        inputProvince(tmp);
        addTail(l, tmp);
    }
}
void outputListProvinces(const List &l){
    node* p = l.pHead;
    while(p != nullptr){
        outputProvince(p->info);
        cout << '\n';
        p = p->pNext;
    }
}
void outputProvincesMore1MillionPop(const List &l){
    node* p = l.pHead;
    while(p != nullptr){
        if (p->info.POP > 1000){
            outputProvince(p->info);
            cout << '\n';
        }
        p = p->pNext;
    }
}
node* findProMaxArea(const List &l){
    if (l.pHead == nullptr) return nullptr;
    node* p = l.pHead;
    node* maxPtr = l.pHead;

    while(p != nullptr){
        if (p->info.AREA > maxPtr->info.AREA)
            maxPtr = p;
        p = p->pNext;
    }
    return maxPtr;
}


int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}