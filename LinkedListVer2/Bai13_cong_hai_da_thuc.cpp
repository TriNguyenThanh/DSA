/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
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
void addTail(DATHUC &daThuc, double heSo, int soMu)
{
    Node* newNode = getNode(heSo, soMu);

    if (daThuc.head == nullptr)
    {
        daThuc.head = daThuc.tail = newNode;
    }
	else
	{
		daThuc.tail->next = newNode;
		daThuc.tail = newNode;
	}
}
void Nhap(DATHUC &daThuc)
{
    daThuc.head = daThuc.tail = nullptr;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; ++i){
        cin >> heso >> somu;
        Node* p = getNode(heso, somu);
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
DATHUC Tong2DaThuc(DATHUC daThuc1, DATHUC daThuc2)
{
	DATHUC tong;
	tong.head = tong.tail = nullptr;
	Node* p1 = daThuc1.head;
	if (daThuc1.head == nullptr) return daThuc2;

	Node* p2 = daThuc2.head;
	if (daThuc1.head == nullptr) return daThuc2;

	while (true)
	{
		if (p1 == nullptr && p2 == nullptr) return tong;

		if (p1 != nullptr && p2 != nullptr)
		{
			if (p1->data->somu == p2->data->somu)
			{
				addTail(tong, p1->data->heso + p2->data->heso, p1->data->somu);
				p1 = p1->next;
				p2 = p2->next;
			}
			else if (p1->data->somu > p2->data->somu)
			{
				addTail(tong, p1->data->heso, p1->data->somu);
				p1 = p1->next;
			}
			else
			{
				addTail(tong, p2->data->heso, p2->data->somu);
				p2 = p2->next;
			}
		}
		else if (p1 != nullptr)
		{
			while(p1 != nullptr)
			{
				addTail(tong, p1->data->heso, p1->data->somu);
				p1 = p1->next;
			}
			return tong;
		}
		else
		{
			while(p2 != nullptr)
			{
				addTail(tong, p2->data->heso, p2->data->somu);
				p2 = p2->next;
			}
			return tong;
		}
	}
	return tong;
}

int main() {
    DATHUC A, B;
    Nhap(A);
    Nhap(B);
    cout << "Da thuc A: "; Xuat(A);
    cout << "\nDa thuc B: "; Xuat(B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}
