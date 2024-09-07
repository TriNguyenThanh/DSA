/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void inputMatrix(char a[100][100], int &n){
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    
}
void outputMatrix(char a[100][100], int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (a[i][j] == 120) a[i][j] = 88;
            else if (a[i][j] == 111) a[i][j] = 79;
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
bool checkRow(char a[100][100], int n, int x, int y){
    a[x][y] = 'X';
    for (int i = 0; i < n; ++i){
        if (a[x][i] != 'X') return 0;
    }
    return 1;
}
bool checkCol(char a[100][100], int n, int x, int y){
    a[x][y] = 'X';
    for (int i = 0; i < n; ++i){
        if (a[i][y] != 'X') return 0;
    }
    return 1;
}
bool checkMainDiag(char a[100][100], int n, int x, int y){
    a[x][y] = 'X';
    for (int i = 0; i < n; ++i){
        if (a[i][i] != 'X') return 0;
    }
    return 1;
}
bool checkSecDiag(char a[100][100], int n, int x, int y){
    a[x][y] = 'X';
    for (int i = 0; i < n; ++i){
        if (a[i][n-i-1] != 'X') return 0;
    }
    return 1;
}
bool checkEmpty(char a[100][100], int n, int x, int y){
    a[x][y] = 'X';
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] == '-') return 1;

    return 0;
}
void checkWin(char a[100][100], int n, int x, int y){
    if (x > n || y > n) cout << "Invalid";
    else if (a[x][y] != '-') cout << "Not empty";
    else if (checkRow(a, n, x, y)) cout << "You win at row " << x;
    else if (checkCol(a, n, x, y)) cout << "You win at column " << y;
    else if (checkMainDiag(a, n, x, y)) cout << "You win on the main diagonal";
    else if (checkSecDiag(a, n, x, y)) cout << "You win on the secondary diagonal";
    else if (checkEmpty(a, n, x, y)) cout << "My turn";
    else cout << "Game over";
}

int main()
{
    int n; char a[100][100];
    inputMatrix(a,n);
    cout<<"Board:\n";
    outputMatrix(a,n);
    int x,y;
    cin>>x>>y;
    cout<<"You just place an X on ("<<x<<","<<y<<")"<<endl;
    checkWin(a,n,x,y);
    return 0;
}