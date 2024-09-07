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
bool my_strcmp(const char s[], const char t[]){
    int slen = -1, tlen = -1;
    while (s[++slen] != '\0');
    while (t[++tlen] != '\0');

    if (slen != tlen) return 0;
    int i = -1;
    while(s[++i] != '\0'){
        if (s[i] != t[i]) return 0;
    }
    return true;
}
void xuatChuyenBay(CB a){
    cout << a.ID << '\t' << a.DATE.day << '/' << a.DATE.month << '/' << a.DATE.year << '\t' << a.TIME << '\t' << a.DES;
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
void xuatChuyenBayToiTinh(CB a[], int n, const char s[]){
    for (int i = 0; i < n; ++i){
        if (my_strcmp(s, a[i].DES)){
            xuatChuyenBay(a[i]); cout <<'\n';
        }
    }
}
int main()
{
    CB a[100];
    int n;
    nhapDSChuyenBay(a,n); // Nhap danh sach cac chuyen bay

    cout<<"Machuyen\t|Ngaybay\t|Giobay\t|Noiden\n";
    xuatChuyenBayToiTinh(a,n,"Ha Noi");

    return 0;
}
