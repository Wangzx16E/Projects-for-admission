#include "StdAfx.h"
#include "Geography.h"
#include <iostream>
#include <string>

using namespace std;

Geography::Geography(void)
{
}


Geography::~Geography(void)
{
}

void Geography::setinfo()
{
	cout<<"\n"<<"������ͼ�����ƣ�";
	cin>>name;
	cout<<"\n"<<"������ͼ���ţ�";
	cin>>no;
	cout<<"\n"<<"������ͼ��۸�";
	cin>>price;
	cout<<"\n"<<"�����뱾����";
	cin>>sum;
	cout<<"\n"<<"������ͼ�������Ϣ��1�������ĵ���2������Ȼ������";
	cin>>subject;cout<<"\n";
	while(subject != 1 && subject != 2)
	{
		cout<<"����������������룺";
		cin>>subject;
	}
}

void Geography::b_display()
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
			{cout<<"���ĵ���"<<endl;break;}
		case 2:
			{cout<<"��Ȼ����"<<endl;break;}
	}
	cout<<"��ͼ�鱾����"<<sum<<endl;
	cout<<"�ܼ�ֵ��"<<b_calval()<<endl;
}

double Geography::b_calval()
{
	return (price * sum);
}