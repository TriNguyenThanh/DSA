/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


//###INSERT CODE HERE -

bool isValid(string s){
	int tmp = 0;
	for (int i = 0; s[i] != '\0'; ++i){
		if (s[i] == '(') tmp++;
		else {
			tmp--;
			if (tmp < 0) return 0;
		}
	}
	return tmp == 0;
}

int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}



