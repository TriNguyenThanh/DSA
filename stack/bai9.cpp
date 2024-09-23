#include <iostream>
#include <stack>

using namespace std;
int size(stack<int> s){
    int last = s.top();
    s.pop();
    int n, count = 0;
    if (last < s.top()) return 1;
    while(s.empty()){
        n = s.top();
        if (last >= n) count++;
        else return count;
    }

}
int main(){
    stack<int> s;
    int n, x, count = 0;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> x;
        s.push(x);
        count += size(s);
    }

    return 0;
}
