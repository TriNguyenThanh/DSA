#include <iostream>
using namespace std;



struct PhanSo
{
	int tu;
	int mau;
};

PhanSo *l[4];

int main(){
	PhanSo *p, *t = new PhanSo;

	p->mau = 1;
	p->tu = 1;

	t->tu = 2;
	t->mau = 5;
	
	l[0] = p;
	l[1] = t;
	
	int tu = l[0]->tu;
	int mau = l[0]->mau;

	cout << l[0]->tu << '/' << l[0]->mau;

	return 0;
}