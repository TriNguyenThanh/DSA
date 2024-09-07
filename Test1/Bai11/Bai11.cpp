 /*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/
#include <iostream>
#include<cstring>
using namespace std;

//###INSERT CODE HERE -
void transformString(char s1[], char s2[]){
    int i = 0;
    while(s1[i] != '\0'){
        if (s1[i] == 32 || (48 <= s1[i] && s1[i] <= 57))
            s2[i] = s1[i];
        else if (65 <= s1[i] && s1[i] <= 90)
            s2[i] = s1[i] + 32;
        else if (97 <= s1[i] && s1[i] <= 122)
            s2[i] = s1[i] - 32;
        else s2[i] = '*';
        i++;
    }
    s2[i] = s1[i];
}
int main()
{
    char s1[200], s2[200];
    cout<<"Nhap chuoi = ";
    cin.getline(s1, 199);
    transformString(s1, s2); //khong dung duoc ham toupper, tolower
    cout<<"\ns1="<<s1<<endl;
    cout<<"s2="<<s2;

    return 0;
}

