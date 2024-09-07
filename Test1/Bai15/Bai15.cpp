/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include <cstring>

using namespace std;

//###INSERT CODE HERE -
int type(char x){
    if (48 <= x && x <= 57) return 1;
    if ((65 <= x && x <= 90) || (97 <= x && x <= 122)) return 2;
    return 3;
}
bool compare(char x1, char x2){
    int type_x1 = type(x1), type_x2 = type(x2);
    if (type_x1 == 1)
        if (x1 == x2) return 1;
        else return 0;
    return (type_x1 == type_x2); 
}
int SoSanhBangNhauTheoSo(char s[], char t[]){
    int slen = -1, tlen = -1;
    while (s[++slen] != '\0');
    while (t[++tlen] != '\0');

    if (slen != tlen) return 0;
    int i = 0;
    while (compare(s[i], t[i]) && i < slen){
        i++;
    }
    //cout << i << "-" << slen << '\n';
    return i == slen;
}

int main()
{
    char s[256], t[256];
    cin.getline(s,256);
    cin.getline(t,256);
    cout<<SoSanhBangNhauTheoSo(s,t);//so giong nhau, cung la chu cai

    return 0;
}
