

#include <iostream>
#include <string>
#define MAX 2000
#define NULLDATA -1
using namespace std;

struct Stack1
{
    char arr[MAX];
    int n; // so luong phan tu cua stack
};

struct node
{
    char info;
    node* next;
};

void Init(Stack1& s) {
    s.n = 0;
}
bool isEmpty(Stack1 s) {
    return s.n == 0;
}
bool isFull(Stack1 s) {
    return s.n == MAX;
}

void Push(Stack1& s, char x) {
    if (isFull(s)) return;
    s.arr[s.n] = x;
    (s.n)++;
}
void Pop(Stack1& s) {
    if (isEmpty(s)) return;
    s.arr[s.n - 1] = NULLDATA;
    (s.n)--;
}
void printStack1(Stack1 s) {
    for (int i = s.n - 1; i >= 0; --i) {
        cout << s.arr[i];
    }
}

char Top(Stack1 s) {
    if (isEmpty(s)) return NULLDATA;
    return s.arr[s.n - 1];
}

void reverseWords(string str) {
    Stack1 s;
    Init(s);
    int x = 0;
    while (str[x] != '\0') {
        if (str[x] == ' ') {
            while (str[x] == ' ')
            {
                cout << ' ';
                x++;
            }
        }
        else {
            while (str[x] != ' ' && str[x] != '\0') {
                Push(s, str[x]);
                x++;
            }
            while (!isEmpty(s)) {
                cout << Top(s);
                Pop(s);
            }
        }
    }
}
int main()
{
    string str;
    getline(cin, str);
    reverseWords(str);
    return 0;
}