/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
string
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

//###INSERT CODE HERE -
void MaHoaMatThu(char s[]){
    int i = -1;
    while(s[++i] != '\0'){
        if (65 <= s[i] && s[i] <= 90){
            if (i != 0 && s[i-1] != ' ') cout << '.';
            cout << (int) s[i]-65;
        }
        else if (97 <= s[i] && s[i] <= 122){
            if (i != 0 && s[i-1] != ' ') cout << '.';
             cout << (int) s[i]-97;
        }
        else if (s[i] == 32) cout << '-';
        else cout << s[i];
    }
}

int main()
{
    char s[100];
    cin.getline(s,99);
    cout<<"Chuoi vua nhap: "<<s;
    cout<<"\nChuoi sau khi duoc ma hoa: ";
    MaHoaMatThu(s);

    return 0;
}
