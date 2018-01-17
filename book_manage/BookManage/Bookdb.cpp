#include "StdAfx.h"
#include "Bookdb.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Bookdb::Bookdb(void)
{
}

Bookdb::~Bookdb(void)
{
}

void Bookdb::addbook(Book* b)
{
	books.push_back(b);
}

void Bookdb::delbook(string num)
{
	int flag = 0;
	Book *b = books[0];
	for(int i = 0;i<books.size();i++)
	{
		b = books[i];
		if(b->no == num && b->b_del ==1)
		{
			b->b_del = 2;
			flag = 1;
			cout<<"删除成功！"<<endl;
			break;
		}
	}
	if(flag == 0)
		cout<<"没有找到该书籍！"<<endl;
}

void Bookdb::listbook(string num)
{
	int flag = 0;
	Book *b = books[0];
	for(int i = 0;i < books.size();i++)
	{
		b = books[i];
		if(b->no == num && b->b_del ==1)
		{
			b->b_display();flag = 1;break;
		}
	}
	if(flag == 0)
		cout<<"没有找到该书籍！"<<endl;
}

int Bookdb::findbook(string num)
{
	int i,flag = 0;
	Book* b = books[0];
	for(i = 0;i < books.size();i++)
	{
		b = books[i];
		if(b->no == num && b->b_del ==1)
		{
			flag = 1;break;
		}
	}
	if(flag == 0)
	{cout<<"没有找到该书籍！"<<endl;return -1;}
	else
		return i;
}

int Bookdb::count()
{
	return books.size();
}

Book* Bookdb::get(int i)
{
	return books[i];	
}
