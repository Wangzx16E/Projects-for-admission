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
	cout<<"\n"<<"������������";
	cin>>name;
	cout<<"\n"<<"���������֤��ţ�";
	cin>>cardid;
}

void Ordireader::r_display()
{
	cout<<"\n"<<"�ö�����Ϣ���£�"<<endl;
	cout<<"������"<<name<<endl;
	cout<<"��ݣ���ͨ����"<<endl;
	cout<<"����֤�ţ�"<<cardid<<endl;
	if(brbook != " ")
		cout<<"�ѽ���ı�ţ�"<<brbook<<endl;
	else
		cout<<"��û�н��顣"<<endl;
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