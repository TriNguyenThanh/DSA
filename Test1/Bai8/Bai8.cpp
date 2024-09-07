/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>

using namespace std;


//###INSERT CODE HERE -
void inputArray(int a[100][100], int n, int m){
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
}
void outputArray(int a[100][100], int n, int m){
    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}
void swap(int &a, int &b){
    a += b;
    b = a - b;
    a = a - b;
}

void horizontal_invert(int a[100][100], int n, int m){
    for (int i = 0; i < m; ++i){
        int start = 0, end = n - 1;
        while (start < end){
            swap(a[start++][i], a[end--][i]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;


    int a[100][100];

    inputArray(a, n, m);

    horizontal_invert(a, n, m);

    outputArray(a, n, m);

    return 0;
}
