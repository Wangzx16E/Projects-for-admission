#include "StdAfx.h"
#include "Readerdb.h"
#include "Reader.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Readerdb::Readerdb(void)
{
}

Readerdb::~Readerdb(void)
{
}

void Readerdb::addreader(Reader* b)
{
	readers.push_back(b);
}

void Readerdb::delreader(string num)
{
	int flag = 0;
	Reader *b = readers[0];
	for(int i = 0;i<readers.size();i++)
	{
		b = readers[i];
		if(b->cardid == num && b->r_del ==1)
		{
			b->r_del = 2;
			flag = 1;
			cout<<"删除成功！"<<endl;
			break;
		}
	}
	if(flag == 0)
		cout<<"没有找到该读者！"<<endl;
}

void Readerdb::listreader(string num)
{
	int flag = 0;
	Reader* b = readers[0];
	for(int i = 0;i < readers.size();i++)
	{
		b = readers[i];
		if(b->cardid == num && b->r_del ==1)
		{
			b->r_display();flag = 1;break;
		}
	}
	if(flag == 0)
		cout<<"没有找到该读者！"<<endl;
}

int Readerdb::findreader(string num)
{
	int i,flag = 0;
	Reader* b = readers[0];
	for(i = 0;i < readers.size();i++)
	{
		b = readers[i];
		if(b->cardid == num && b->r_del ==1)
		{
			flag = 1;break;
		}
	}
	if(flag == 0)
	{cout<<"没有找到该读者！"<<endl;return -1;}
	else
		return i;
}

int Readerdb::count()
{
	return readers.size();
}

Reader* Readerdb::get(int i)
{
	return readers[i];	
}