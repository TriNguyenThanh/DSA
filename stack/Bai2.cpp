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
    int t; // t là chỉ số của phần tử cuối mảng, tức là đỉnh stack
};
void Init(Stack &S)
{
    S.t=-1; //Khi stack chưa có phần tử nào thì top được khởi tạo là -1,
            // nếu khởi tạo t = 0 là SAI vì khi đó sẽ hiểu top tại a[0]
}
//###INSERT CODE HERE -
bool isEmpty(Stack s){
    return s.t+1 == 0;
}
bool isFull(Stack s){
    return s.t+1 == MAX;
}

void Push(Stack &s, int x){
    if (isFull(s)) return;
    s.arr[s.t+1] = x;
    (s.t)++;

}
void Pop(Stack &s){
    if (isEmpty(s)) return;
    s.arr[s.t] = NULLDATA;
    (s.t)--;
}
void printStack(Stack s){
    if (isEmpty(s)){
        cout << "Stack is empty";
        return;
    }
    for (int i = 0; i <= s.t; ++i){
        cout << s.arr[i] << ' ';
    }
}

int Top(Stack s){
    if (isEmpty(s)) return NULLDATA;
    return s.arr[s.t];
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);

    }
    cout<<"Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    Pop(S);
    cout<<"\nUpdated Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    return 0;
}




