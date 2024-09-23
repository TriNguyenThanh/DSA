#include <iostream>
#include <stack>
using namespace std;
void DecimaltoBinary2(int x, stack<int> &s){
    int du = x;
    while(true){
        if (du == 0) return;
        else if (du == 1){
            s.push(1);
            return;
        }
        else if (du >= 2){
            s.push(du%2);
            du /= 2;
        }
    }
}
void printStack(stack<int> s){
    if (s.empty()){
        cout << "0";
        return;
    }
    for (int i = s.size() - 1; i >= 0; --i){
        cout << s.top();
        s.pop();
    }
}
int main(){
    stack<int> binary;
    int n; cin >> n;
    DecimaltoBinary2(n, binary);
    printStack(binary);
}