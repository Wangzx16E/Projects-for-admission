#include "StdAfx.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;
Student::Student(void)
{
	borrow_num = 0;

	brbook = " ";
}

Student::~Student(void)
{
}

void Student::r_setinfo()
{
	cout<<"\n"<<"������������";
	cin>>name;
	cout<<"\n"<<"���������֤��ţ�";
	cin>>cardid;
}

void Student::r_display()
{
	cout<<"\n"<<"�ö�����Ϣ���£�"<<endl;
	cout<<"������"<<name<<endl;
	cout<<"��ݣ�ѧ��"<<endl;
	cout<<"����֤�ţ�"<<cardid<<endl;
	if(brbook != " ")
		cout<<"�ѽ���ı�ţ�"<<brbook<<endl;
	else
		cout<<"��û�н��顣"<<endl;
}

void Student::r_borrow(string num)
{
	brbook = num;
	borrow_num = 1;
	r_borrowed = 2;
}

void Student::r_return()
{
	borrow_num = 0;
	r_borrowed = 1;
	brbook = " ";
}