#include <iostream>
using namespace std;

int Alb[26];

void inputArray(int n, char a[]);
void isAlphabet(char c);
int count();

int main(){
    char a[1000];
    int n; cin >> n;
    inputArray(n, a);
    for (int i = 0; i < n; ++i)
        isAlphabet(a[i]);

    cout << count();
    return 0;
}
void inputArray(int n, char a[]){
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}
void isAlphabet(char c){
    int key = c;
    if (65 <= key && key <= 90) Alb[key - 65] = 1;
    else if (97 <= key && key<= 122) Alb[key - 97] = 1;
}
int count(){
    int d = 0;
    for (int i = 0; i < 26; ++i){
        if (Alb[i] == 0) d++;
    }
    return d;
}