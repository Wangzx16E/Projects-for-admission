#include "StdAfx.h"
#include "Mathe.h"
#include <iostream>
#include <string>

using namespace std;

Mathe::Mathe(void)
{
}

Mathe::~Mathe(void)
{
}

void Mathe::setinfo()
{
	cout<<"\n"<<"������ͼ�����ƣ�";
	cin>>name;
	cout<<"\n"<<"������ͼ���ţ�";
	cin>>no;
	cout<<"\n"<<"������ͼ��۸�";
	cin>>price;
	cout<<"\n"<<"�����뱾����";
	cin>>sum;
	cout<<"\n"<<"������ͼ�������Ϣ��1������ѧ��2������ɢ��ѧ����";
	cin>>subject;cout<<"\n";
	while(subject != 1 && subject != 2)
	{
		cout<<"����������������룺";
		cin>>subject;
	}
}

void Mathe::b_display()
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
			{cout<<"����ѧ"<<endl;break;}
		case 2:
			{cout<<"��ɢ��ѧ"<<endl;break;}
	}
	cout<<"��ͼ�鱾����"<<sum<<endl;
	cout<<"�ܼ�ֵ��"<<b_calval()<<endl;
}

double Mathe::b_calval()
{
	return (price * sum);
}