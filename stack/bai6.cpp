/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


//###INSERT CODE HERE -
struct node
{
	int info;
	node* next;
};
struct Stack
{
	node* pHead;
};

node* getNode(int x) {
	node* new_node = new node;
	new_node->info = x;
	new_node->next = nullptr;
	return new_node;
}

void Init(Stack& s) {
	s.pHead = NULL;
}

bool isEmpty(Stack s) {
	return s.pHead == NULL;
}

void Push(Stack& s, int x) {
	node* NODE = getNode(x);
	if (s.pHead == NULL) {
		s.pHead = NODE;
		return;
	}
	NODE->next = s.pHead;
	s.pHead = NODE;
}
void Pop(Stack& l) {
	if (l.pHead == nullptr) return;
	if (l.pHead->next == nullptr) {
		delete l.pHead;
		l.pHead = nullptr;
		return;
	}
	node* p = l.pHead;
	l.pHead = l.pHead->next;
	p->next = nullptr;
	delete p;
}

bool isValid(string x) {
	Stack s;
	Init(s);

	for (int i = 0; x[i] != '\0'; ++i) {
		if (x[i] != ')' && x[i] != '}' && x[i] != ']') continue;
		if (x[i] == '(') Push(s, 1);
		else if (x[i] == '[') Push(s, 2);
		else if (x[i] == '{') Push(s, 3);
		else if (isEmpty(s)) return 0;
		else {
			if (x[i] == ')' && s.pHead->info == 1) Pop(s);
			else if (x[i] == ']' && s.pHead->info == 2) Pop(s);
			else if (x[i] == '}' && s.pHead->info == 3) Pop(s);
			else return 0;
		}
	}
	return s.pHead == nullptr;
}

int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}