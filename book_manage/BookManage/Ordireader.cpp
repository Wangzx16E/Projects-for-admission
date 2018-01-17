#include "StdAfx.h"
#include "Ordireader.h"
#include <iostream>
#include <string>

using namespace std;
Ordireader::Ordireader(void)
{
	borrow_num = 0;
	brbook = " ";
}

Ordireader::~Ordireader(void)
{
}

void Ordireader::r_setinfo()
{
	cout<<"\n"<<"请输入姓名：";
	cin>>name;
	cout<<"\n"<<"请输入借书证编号：";
	cin>>cardid;
}

void Ordireader::r_display()
{
	cout<<"\n"<<"该读者信息如下："<<endl;
	cout<<"姓名："<<name<<endl;
	cout<<"身份：普通读者"<<endl;
	cout<<"借书证号："<<cardid<<endl;
	if(brbook != " ")
		cout<<"已借书的编号："<<brbook<<endl;
	else
		cout<<"还没有借书。"<<endl;
}

void Ordireader::r_borrow(string num)
{
	brbook = num;
	borrow_num = 1;
	r_borrowed = 2;
}

void Ordireader::r_return()
{
	borrow_num = 0;
	r_borrowed = 1;
	brbook = " ";
}