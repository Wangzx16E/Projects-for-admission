#include "StdAfx.h"
#include "Computer.h"
#include <iostream>
#include <string>

using namespace std;

Computer::Computer(void)
{
}

Computer::~Computer(void)
{
}

void Computer::setinfo()
{
	cout<<"\n"<<"������ͼ�����ƣ�";
	cin>>name;
	cout<<"\n"<<"������ͼ���ţ�";
	cin>>no;
	cout<<"\n"<<"������ͼ��۸�";
	cin>>price;
	cout<<"\n"<<"�����뱾����";
	cin>>sum;
	cout<<"\n"<<"������ͼ�������Ϣ��1����C���ԣ�2����C++��3����JAVA����";
	cin>>subject;cout<<"\n";
	while(subject != 1 && subject != 2 && subject != 3)
	{
		cout<<"����������������룺";
		cin>>subject;
	}
}

void Computer::b_display()
{
	cout<<"\n"<<"��ͼ����Ϣ���£�"<<endl;
	cout<<"ͼ�����ƣ�"<<name<<endl;
	cout<<"ͼ���ţ�"<<no<<endl;
	cout<<"ͼ��۸�"<<price<<endl;
	cout<<"ͼ�������Ȼ��ѧ"<<"\n";
	cout<<"ͼ�������Ϣ��";
	switch(subject)
	{
		case 1:
			{cout<<"C����"<<endl;break;}
		case 2:
			{cout<<"C++"<<endl;break;}
		case 3:
			{cout<<"JAVA"<<endl;break;}
	}
	cout<<"��ͼ�鱾����"<<sum<<endl;
	cout<<"�ܼ�ֵ��"<<b_calval()<<endl;
}

double Computer::b_calval()
{
	return (price * sum);
}