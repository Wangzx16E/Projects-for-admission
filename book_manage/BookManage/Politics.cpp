#include "StdAfx.h"
#include "Politics.h"
#include <iostream>
#include <string>

using namespace std;

Politics::Politics(void)
{
}


Politics::~Politics(void)
{
}

void Politics::setinfo()
{
	cout<<"\n"<<"������ͼ�����ƣ�";
	cin>>name;
	cout<<"\n"<<"������ͼ���ţ�";
	cin>>no;
	cout<<"\n"<<"������ͼ��۸�";
	cin>>price;
	cout<<"\n"<<"�����뱾����";
	cin>>sum;
	cout<<"\n"<<"������ͼ�������Ϣ��1�������˼���壬2�������ι�����";
	cin>>subject;cout<<"\n";
	while(subject != 1 && subject != 2)
	{
		cout<<"����������������룺";
		cin>>subject;
	}
}

void Politics::b_display()
{
	cout<<"\n"<<"��ͼ����Ϣ���£�"<<endl;
	cout<<"ͼ�����ƣ�"<<name<<endl;
	cout<<"ͼ���ţ�"<<no<<endl;
	cout<<"ͼ��۸�"<<price<<endl;
	cout<<"ͼ���������ѧ"<<"\n";
	cout<<"ͼ�������Ϣ��";
	switch(subject)
	{
		case 1:
			{cout<<"���˼����"<<endl;break;}
		case 2:
			{cout<<"���ι���"<<endl;break;}
	}
	cout<<"��ͼ�鱾����"<<sum<<endl;
	cout<<"�ܼ�ֵ��"<<b_calval()<<endl;
}

double Politics::b_calval()
{
	return (price * sum);
}