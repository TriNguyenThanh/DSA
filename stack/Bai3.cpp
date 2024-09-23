/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};

//###INSERT CODE HERE -
void Init(Stack &s){
    s.n = 0;
}
bool isEmpty(Stack s){
    return s.n == 0;
}
bool isFull(Stack s){
    return s.n == MAX;
}

void Push(Stack &s, int x){
    if (isFull(s)) return;
    s.arr[s.n] = x;
    (s.n)++;

}
void Pop(Stack &s){
    if (isEmpty(s)) return;
    s.arr[s.n-1] = NULLDATA;
    (s.n)--;
}
void printStack(Stack s){
    if (isEmpty(s)){
        cout << "0";
        return;
    }
    for (int i = s.n-1; i >= 0; --i){
        cout << s.arr[i] ;
    }
}

int Top(Stack s){
    if (isEmpty(s)) return NULLDATA;
    return s.arr[s.n-1];
}
void DecimaltoBinary2(int x, Stack &s){
    int du = x;
    while(true){
        if (du == 0) return;
        else if (du == 1){
            Push(s, 1);
            return;
        }
        else if (du >= 2){
            Push(s, du%2);
            du /= 2;
        }
    }
}
int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary2(n,S);
    printStack(S);
    return 0;
}




