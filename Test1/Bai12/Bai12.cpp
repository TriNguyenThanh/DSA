/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include<cstring>

using namespace std;

//###INSERT CODE HERE -
void ThayTheKyTuChuCai(char s1[], char x){
    int i = 0;
    while(s1[i] != '\0'){
        if ((65 <= s1[i] && s1[i] <= 90) || (97 <= s1[i] && s1[i] <= 122))
            s1[i] = x;
        i++;
    }
}
int main()
{
    char s[256];
    cin.getline(s,256);
    char x;
    cin>>x;
    ThayTheKyTuChuCai(s,x); // Ham thay the cac ky tu chu cai co trong chuoi s thanh ky tu x
    cout<<s;
    return 0;
}
