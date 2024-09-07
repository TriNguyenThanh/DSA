/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;

//###INSERT CODE HERE -
void nhapMaTran(int a[100][100], int n, int m){
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
}
void xuatMaTranTheoCot(int a[100][100], int n, int m){
    cout << "Ma tran A(" << n << "x" << m << ") da nhap\n";
    for (int i = 0; i < m; ++i){
        cout << "Cot " << i << " gom cac so: ";
        for (int j = 0; j < n; ++j)
            cout << a[j][i] << ' ';
        cout << '\n';
    }
}
int main()
{
    int a[100][100], n, m;
    cin>>n>>m; //n: so dong, m: so cot
    nhapMaTran(a,n,m); //nhap nhu binh thuong theo tung dong
    xuatMaTranTheoCot(a,n,m); //Xuat theo tung cot
    return 0;
}

