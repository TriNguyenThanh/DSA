/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
};

struct Node{
	DONTHUC* data;
	Node* next;

};

typedef struct DATHUC{
	Node* head;
	Node* tail;
}List;


//###INSERT CODE HERE -
Node* getNode(double heSo, int soMu)
{
	Node* newNode = new Node;
	newNode->data = new DONTHUC;
	newNode->next = nullptr;
	newNode->data->heso = heSo;
	newNode->data->somu = soMu;
	
	return newNode;
}
void Nhap(DATHUC &daThuc, double heSo, int soMu)
{
	Node* p = getNode(heSo, soMu);
	if (p == nullptr) return;

	if(daThuc.head == nullptr)
	{
		daThuc.head = daThuc.tail = p;
	}
	else
	{
		daThuc.tail->next = p;
		daThuc.tail = p;
	}
}
void Xuat(DATHUC daThuc)
{
	bool  is_cout = false;
	Node* p = daThuc.head;
	if (p == nullptr)
	{
		cout << '0';
		return;
	}
	else
	{	
		if (p->data->heso != 0)
		{
			if (p->data->heso != 1 && p->data->heso != -1) cout << p->data->heso;
			else if (p->data->heso == -1) cout << '-';

			if (p->data->somu == 0 && (p->data->heso == 1 || p->data->heso == -1)) cout << '1';
			else if (p->data->somu != 0)
			{
				if (p->data->somu == 1) cout << 'x';
				else cout << "x^" << p->data->somu;
			}

			is_cout = true;
		}
		else if (daThuc.head == daThuc.tail)
		{
			cout << '0';
			is_cout = true;
		}

		p = p->next;
		while(p != nullptr)
		{	
			if (p->data->heso != 0)
			{
				if (p->data->heso > 0 && (daThuc.head->next != p || daThuc.head->data->heso != 0)) cout << '+';

				if (p->data->heso != 1 && p->data->heso != -1) cout << p->data->heso;
				else if (p->data->heso == -1) cout << '-';

				if (p->data->somu == 0 && (p->data->heso == 1 || p->data->heso == -1)) cout << '1';
				else if (p->data->somu != 0)
				{
					if (p->data->somu == 1) cout << 'x';
					else cout << "x^" << p->data->somu;
				}
				is_cout = true;
			}
			p = p->next;
		}

		if (!is_cout) cout << '0';
	}
}
double TinhDaThuc(DATHUC daThuc, double x)
{
	if (daThuc.head == nullptr) return 0;
	double result = 0;
	for (Node* p = daThuc.head; p != nullptr; p = p->next)
	{
		result += p->data->heso * (pow(x, (double) p->data->somu));
	}
	return result;
}

int main() {
    DATHUC B;
    B.head=B.tail=NULL;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
