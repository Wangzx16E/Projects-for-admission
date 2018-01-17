#include "StdAfx.h"
#include "Physics.h"
#include <iostream>
#include <string>

using namespace std;
Physics::Physics(void)
{
}

Physics::~Physics(void)
{
}

void Physics::setinfo()
{
	cout<<"\n"<<"请输入图书名称：";
	cin>>name;
	cout<<"\n"<<"请输入图书编号：";
	cin>>no;
	cout<<"\n"<<"请输入图书价格：";
	cin>>price;
	cout<<"\n"<<"请输入本数：";
	cin>>sum;
	cout<<"\n"<<"请输入图书具体信息（1代表力学，2代表电磁学）：";
	cin>>subject;cout<<"\n";
	while(subject != 1 && subject != 2)
	{
		cout<<"输入错误，请重新输入：";
		cin>>subject;
	}
}

void Physics::b_display()
{
	cout<<"\n"<<"该图书信息如下："<<endl;
	cout<<"图书名称："<<name<<endl;
	cout<<"图书编号："<<no<<endl;
	cout<<"图书价格："<<price<<endl;
	cout<<"图书类别：自然科学"<<"\n";
	cout<<"图书具体信息：";
	switch(subject)
	{
		case 1:
			{cout<<"力学"<<endl;break;}
		case 2:
			{cout<<"电磁学"<<endl;break;}
	}
	cout<<"该图书本数："<<sum<<endl;
	cout<<"总价值："<<b_calval()<<endl;
}

double Physics::b_calval()
{
	return (price * sum);
}