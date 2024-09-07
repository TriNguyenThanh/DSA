#include <iostream>
using namespace std;

int count(char s[]);

int main(){
    char s[256];
    cin.getline(s, 256);
    cout << count(s);    
    return 0;
}


int count(char s[]){
    int c = 0;
    int i = -1;
    while(s[++i] != '\0'){
        if(i == 0 && s[i] != ' '){
            while(s[i] != ' ' || s[i] != '\0'){
                if (s[i] < 97 || 122 < s[i]) break;
                i++;
            }
            if (s[i] == ' ' || s[i] == '\0') c++;
        }else if (s[i-1] == ' ' && s[i] != ' '){
            while(s[i] != ' ' || s[i] != '\0'){
                if (s[i] < 97 || 122 < s[i]) break;
                i++;
            }
            if (s[i] == ' ' || s[i] == '\0') c++;
        }
        
    }
    return c;
}