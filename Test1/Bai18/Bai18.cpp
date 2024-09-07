/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cstdio>

using namespace std;

//###INSERT CODE HERE -
struct date{
    int day;
    int month;
    int year;
};

struct CB{
    char ID[35];
    date DATE;
    float TIME;
    char DES[35];
};
void xuatChuyenBay(CB a);
void nhapDSChuyenBay(CB a[], int &n);
CB longestFly(CB a[], int n);
bool check(char s[], char t[]);
void mind(CB a[], int n, char t[]);

int main(){
    CB a[100];
    int n;
    nhapDSChuyenBay(a, n);
    char s[35]; 
    cin.getline(s, 35);
    mind(a, n, s);

    return 0;
}
void nhapDSChuyenBay(CB a[], int &n){
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i){
        cin.getline(a[i].ID, 35);
        cin >> a[i].DATE.day >> a[i].DATE.month >> a[i].DATE.year;
        cin >> a[i].TIME;
        cin.ignore();
        cin.getline(a[i].DES, 35);
    }
}
CB longestFly(CB a[], int n){
    float max = a[0].TIME;
    int imax = 0;
    for (int i = 1; i < n; ++i){
        if(a[i].TIME > max){
            max = a[i].TIME;
            imax = i;
        }
    }
    return a[imax];
}
bool check(char des[], char t[]){
    int deslen = -1, tlen = -1;
    while(des[++deslen] != '\0');
    while(t[++tlen] != '\0');
    while(--tlen != -1){
        if(des[--deslen] != t[tlen]) return 0;
    }
    if (des[--deslen] != ' ') return 0;
    return 1;
}
void mind(CB a[], int n, char t[]){
    CB longest = longestFly(a, n);
    if (check(longest.DES, t)) cout << "YES";
    else cout << "NO";
}