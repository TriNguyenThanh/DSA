#include <iostream>
using namespace std;

const int length = 100;

void inputArr(int arr[], int &n) {
	int value;
	while (n < length && cin >> value && value != -1)
		arr[n++] = value;
}

void outputArr(int arr[], int n) {
	for (int i = 0; i< n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int solution(int arr[], int &n, int m) {
	int count = 0, i = 0;
	while (i < n) {
		if (arr[i] % 2 == 0) {
			for (int j = i; j < n - 1; j++) {
				arr[j] = arr[j + 1];
			}
			n--;
			count++;
			if (count == m) break;
		} else i++;
	}
	
	return count;
}

int main() {
	int arr[length];
	int n = 0;
	inputArr(arr, n);
	
	int m; cin >> m;
	cout << "Before:";
	outputArr(arr, n);
	
	int count = solution(arr, n, m);
	if (m == 0)
		cout << "No deletion required" << endl;
	else if (count == 0)
		cout << "There are no even numbers in the array" << endl;
	else if (n == 0) {
		cout<<"After:Empty";
	} else if (count < m) {
		cout << "Not enough " <<  m << " even numbers but still delete" << endl;
		cout << "After:"; 
		outputArr(arr, n);
	} else {
		cout << "After:";
		outputArr(arr, n);
	}  
	
	return 0;
}