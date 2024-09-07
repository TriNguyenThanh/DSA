/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void inputMatrix(int a[100][100], int &n){
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
}
void outputMatrix(int a[100][100], int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}
void maxElementOfEachRow(int a[100][100], int n){
    int max, imax;
    for (int i = 0; i < n; ++i){
        max = a[i][0]; imax = 0;
        for (int j = 1; j < n; ++j)
            if (a[i][j] > max){
                max = a[i][j];
                imax = j;
            }
        cout << "a["<< i <<"]["<<imax<<"]=" << max << '\n';
    }
}

int main()
{
    int a[100][100];
    int n;
    inputMatrix(a,n);
    cout<<"Matrix: "<<endl;
    outputMatrix(a,n);

    cout<<"Maximum element of each row in the matrix: "<<endl;
    maxElementOfEachRow(a,n); // Tim phan tu lon nhat cua moi dong, xuat vi tri cua phan tu do va gia tri lon nhat.VD: a[0][1]=12

    return 0;
}