
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include<iostream>
#include<cstring>
using namespace std;

//###INSERT CODE HERE -
int countWords(char s[]){
    int i = -1, count = 0;
    while(s[++i] != '\0'){
        if (i == 0 && s[i] != 32)
            count++;
        else if(s[i-1] == ' ' && s[i] != ' ')
            count++;
    }
    return count;
}

int main()
{

   char s[256];
   cin.getline(s, 256);

   cout << countWords(s) << endl;
    return 0;
}
