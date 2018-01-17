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
	cout<<"\n"<<"请输入姓名：";
	cin>>name;
	cout<<"\n"<<"请输入借书证编号：";
	cin>>cardid;
}

void Student::r_display()
{
	cout<<"\n"<<"该读者信息如下："<<endl;
	cout<<"姓名："<<name<<endl;
	cout<<"身份：学生"<<endl;
	cout<<"借书证号："<<cardid<<endl;
	if(brbook != " ")
		cout<<"已借书的编号："<<brbook<<endl;
	else
		cout<<"还没有借书。"<<endl;
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