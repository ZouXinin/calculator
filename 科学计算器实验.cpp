#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
#define e 1.71828;
struct node
{
	double a;
	node* next;
	node* pre;
};
//�˵�
void menu()
{
	 printf("%-48s***��ӭʹ�ÿ�ѧ������***\n","");
	printf( "%-35s==================================================\n","") ;
	printf( "%-35s===============�ӣ�+==========����-===============\n","") ;
	printf( "%-35s===============�ˣ�*==========����/===============\n","") ;
	printf( "%-35s===============�׳ˣ�!========��ָ��^=============\n","") ;
	printf( "%-35s===============���ң�s========���ң�c=============\n","") ;
	printf( "%-35s===============���У�t========����ת����#=========\n","") ;
	printf( "%-35s=======================���㣺e====================\n","") ;
	
}
//�ָ���
void divider()
{
	printf("----------------------------------------------------------------------------------------------------------------------\n");
}
//��������
class calculate
{
	double t1;
	char x;
	double t2;
public:
	double a;
	calculate(){}
	calculate(node* head);
};
//�׳�����
class Fac :public calculate
{
public:
	double Fac1(double p)
	{
		if (fmod(p, 1) != 0 || p < 1)
		{
			return 0;
		}
		if (p == 1)
		{
			return 1;
		}
		return p * Fac1(p - 1);
	}
};
//��������
class System :public calculate
{
	int i;
	char x[20];
public:
	System(double t);
};
//��������
class AC :public calculate
{
public:
	AC(node* head);
};
class Createlink
{
	node* head;
	node* f;
	node* p;
public:
	Createlink()
	{
		head, p, f = NULL;
		head = new node;
		f = head;
		cin >> head->a;
		head->pre, head->next = NULL;
		for (;;)
		{
			p = new node;
			calculate c(head);
			p->a = c.a;
			for (f = head; f->next != NULL; f = f->next);
			f->next = p;
			p->pre = f;
			p->next = NULL;
			divider();
			cout<<p->a;
		}
		
	}
};
//�������ຯ��
calculate::calculate(node* head)
{
	a = 0;
	node* p = NULL;
	t2 = 0;
	for (;;)
	{
		bool flag = 1;
		for (p = head; p->next != NULL; p = p->next);
		t1 = p->a;
		cin >> x;
		switch(x)
		{
			case'+':
				cin >> t2;
				a = t1 + t2;
				break;
			case'-':
				cin >> t2;
				a = t1 - t2;
				break;
			case'*':
				cin >> t2;
				a = t1 * t2;
				break;
			case'/':
				cin >> t2;
				if (t2 == 0)
				{
					cout << "error����������" << endl;
					divider();
					cout << t1;
					flag = 0;
					break;
				}
				a = t1 / t2;
				break;
			case'^':
				cin >> t2;
				a = pow(t1, t2);
				break;
			case'!':
			{
				Fac j;
				a = j.Fac1(t1);
				if (a == 0)
				{
					cout << "error������AC\n" << endl;
				}
				break;
			}
			case's':
				a=sin((t1/180)*3.14159);
				break;
			case'c':
				a = cos((t1/180)*3.14159);
				break;
			case't':
				if (t1 == 90)
				{
					cout << "�����\n������AC" << endl;
					break;
				}
				a = tan((t1/180)*3.14159);
				break;
			case'e':
			{
				AC a(head);
			}
			break;
			case'#':
			{
				System ji(t1);
				divider();
				cout<<t1<<endl;
			}
			flag = 0;
			break;
		default:
			cout << "error ����������\n" << endl;
			flag = 0;
			break;
		}
		if (flag)
			break;
	}
}
//�����ຯ��
AC::AC(node* head)
{
	node* p = NULL, * f = NULL;
	for (p = head, f = p->next;; p = f, f = f->next)
	{
		if (f == NULL)
		{
			delete(p);
			break;
		}
		delete(p);
	}
	system("cls");
	menu();
	divider();
	Createlink cr;
}
//�����ຯ��
System::System(double t)
{
	cout << "��ѡ��ת���Ľ�������" << endl;
	cin >> i;
	itoa(t, x, i);
	divider();
	cout << x;
}
int main()
{
	menu();
	divider();
	Createlink cr;
	return 0;
}