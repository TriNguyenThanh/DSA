/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>

using namespace std;
//Goi y: SV co the viet cac ham sau

long long Factorial (int n); // tinh n!
int isFactorial (int n); // kiem tra n co phai la 1 so giai thua hay khong, nghia la co 1 con so i sao cho i!=n
int isTotalFactorial(int a[], int n); //kiem tra mang co phai chua toan so giai thua hay khong

//###INSERT CODE HERE -
long long f[101];

void inputArray(int a[], int &n){
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
        
}
void outputArray(int a[], int n){
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
}

void CalFactorial(){ // dung quy hoach dong de tinh giai thua
    f[0] = 1;
    for (int i = 1; i <= 100; ++i)
        f[i] = f[i-1] * i;
}

int isFactorial (int n){
    CalFactorial();
    for (int i = 0; i <= 100; ++i){
        if (f[i] == n) return 1;
        if (f[i] > n) return 0;
    }
}
int isTotalFactorial(int a[], int n){
    for (int i = 0; i < n; ++i){
        if(isFactorial(a[i]) == 0) return 0; 
    }
    return 1;
}
long long maxFactorial(int a[], int n){
    long long max = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > max) max = a[i];
    return max;
}

int main()
{
    int n, a[100];
    inputArray(a,n);
    cout<<"Array:"<<endl;
    outputArray(a,n);
    cout<<endl;

    if (isTotalFactorial (a,n)==1)
    {
        cout <<"Mang toan so giai thua"<<endl;
        cout << "So giai thua lon nhat: "<<maxFactorial (a,n);
    }
    else cout<<"Mang khong phai chua toan cac so giai thua";

    return 0;
}
