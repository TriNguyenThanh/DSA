/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;



//###INSERT CODE HERE -
void inputArray(int *&a, int &n);
void outputArray(int *a, int n);
int *add(int *&a, int &n, int value);
int *removed(int *&a, int &n, int index);
int run(int *&a, int &n, int m);
int countEvenNumbers(int *a, int n);
void removedEvenNumbers(int *&a, int &n, int count);

int main(){
    int n = 0;
    int *a = new int;
    inputArray(a, n);
    int m; cin >> m;
    cout << "Before:"; outputArray(a, n);
    switch (run(a, n, m))
    {
    case 1:
        cout << "\nNot enough "<< m <<" even numbers but still delete";
        cout << "\nAfter:";
        if(n == 0) cout << "Empty";
        else outputArray(a, n);
        break;
    case 2:
        cout << "\nThere are no even numbers in the array";
        break;
    case 3:
        cout << "\nAfter:Empty";
        break;
    case 4:
        cout << "\nNo deletion required";
        break;
    default:
        cout << "\nAfter:"; outputArray(a, n);
    }
    return 0;
}
void inputArray(int *&a, int &n){
    int temp; cin >> temp;
    while(temp != -1){
        a = add(a, n, temp);
        cin >> temp;
    }
}
void outputArray(int *a, int n){
    for (int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
}
int *add(int *&a, int &n, int value){
    int *tmp = new int[n+1];
    for (int i = 0; i < n; ++i){
        tmp[i] = a[i];
    }
    tmp[n] = value;
    n++;
    delete a;
    a = nullptr;
    return tmp;
}
int *removed(int *&a, int &n, int index){
    int *tmp = new int[n-1];
    for (int i = 0; i < index; ++i){
        tmp[i] = a[i];
    }
    for (int i = index+1; i < n; ++i){
        tmp[i-1] = a[i];
    }
    n--;
    delete a;
    a = nullptr;

    return tmp;
}
int countEvenNumbers(int *a, int n){
    int count = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] % 2 == 0) count++;
    }
    return count;
}
void removedEvenNumbers(int *&a, int &n, int count){
    int i = 0;
    while(count-- > 0){
        while(true){
            if (a[i] % 2 == 0) break;
            i++;
        }
        a = removed(a, n, i);
    }
}
int run(int *&a, int &n, int m){
    int c = countEvenNumbers(a, n);
    if (m == 0) return 4;
    else if (c == 0) return 2;
    else if (m > c){
        removedEvenNumbers(a, n, c);
        return 1;
    }else if (m == c && c == n) return 3;
    else{
        removedEvenNumbers(a, n, m);
        return 0;
    }
}   
