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
	cout<<"\n"<<"请输入图书名称：";
	cin>>name;
	cout<<"\n"<<"请输入图书编号：";
	cin>>no;
	cout<<"\n"<<"请输入图书价格：";
	cin>>price;
	cout<<"\n"<<"请输入本数：";
	cin>>sum;
	cout<<"\n"<<"请输入图书具体信息（1代表马克思主义，2代表政治管理）：";
	cin>>subject;cout<<"\n";
	while(subject != 1 && subject != 2)
	{
		cout<<"输入错误，请重新输入：";
		cin>>subject;
	}
}

void Politics::b_display()
{
	cout<<"\n"<<"该图书信息如下："<<endl;
	cout<<"图书名称："<<name<<endl;
	cout<<"图书编号："<<no<<endl;
	cout<<"图书价格："<<price<<endl;
	cout<<"图书类别：社会科学"<<"\n";
	cout<<"图书具体信息：";
	switch(subject)
	{
		case 1:
			{cout<<"马克思主义"<<endl;break;}
		case 2:
			{cout<<"政治管理"<<endl;break;}
	}
	cout<<"该图书本数："<<sum<<endl;
	cout<<"总价值："<<b_calval()<<endl;
}

double Politics::b_calval()
{
	return (price * sum);
}