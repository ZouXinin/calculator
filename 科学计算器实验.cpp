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
//菜单
void menu()
{
	 printf("%-48s***欢迎使用科学计算器***\n","");
	printf( "%-35s==================================================\n","") ;
	printf( "%-35s===============加：+==========减：-===============\n","") ;
	printf( "%-35s===============乘：*==========除：/===============\n","") ;
	printf( "%-35s===============阶乘：!========幂指：^=============\n","") ;
	printf( "%-35s===============正弦：s========余弦：c=============\n","") ;
	printf( "%-35s===============正切：t========进制转换：#=========\n","") ;
	printf( "%-35s=======================归零：e====================\n","") ;
	
}
//分割线
void divider()
{
	printf("----------------------------------------------------------------------------------------------------------------------\n");
}
//计算器类
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
//阶乘子类
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
//进制子类
class System :public calculate
{
	int i;
	char x[20];
public:
	System(double t);
};
//归零子类
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
//计算器类函数
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
					cout << "error请重新输入" << endl;
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
					cout << "error请输入AC\n" << endl;
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
					cout << "无穷大\n请输入AC" << endl;
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
			cout << "error 请重新输入\n" << endl;
			flag = 0;
			break;
		}
		if (flag)
			break;
	}
}
//归零类函数
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
//进制类函数
System::System(double t)
{
	cout << "请选择转换的进制数：" << endl;
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