#include <iostream>
#include<math.h>
using namespace std;

void inputArray(int n, int s[]){
    for (int i = 0; i < n; ++i){
        cin >> s[i];
    }
}
void outputArray(int n, int s[]){
    for (int i = 0;i < n; ++i){
        cout << s[i] << ' ';
    }
}
bool ktcp(int n){
    if (n == 0 || n == 1) return true;
    int k = sqrt(n);
    return k*k == n;
}
int main(){
    int n, count = 0;cin >> n;
    int s[n];
    inputArray(n, s);
    if (n < 1) cout << "Mang rong.";
    else{
        outputArray(n, s);cout << '\n';
        for (int i = 1; i < n; i += 2)
            if (ktcp(s[i])){
                cout << s[i] << ' ';
                count++;
            }
        if (count == 0) cout << "Mang khong chua so chinh phuong.";
        else cout << "\n" << count;
    }
    return 0;
}
