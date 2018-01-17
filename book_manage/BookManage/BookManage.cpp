// BookManage.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "Book.h"
#include "Computer.h"
#include "Natural.h"
#include "Social.h"
#include "Bookdb.h"
#include "Reader.h"
#include "Readerdb.h"
#include "Student.h"
#include "Ordireader.h"
#include <string>
#include "Mathe.h"
#include "Chemistry.h"
#include "Physics.h"
#include "Politics.h"
#include "Economy.h"
#include "Law.h"
#include "Linguistic.h"
#include "Biography.h"
#include "Geography.h"
#include "History.h"
#include "Philosophy.h"

using namespace std;

//图书板块
void addbooks(Bookdb* p)
{
	int theme;
	int subtheme;
	cout<<"\n"<<"请输入图书类别（1代表社会科学，2代表自然科学）";
	cin>>theme;
	if(theme == 1)//社会科学
	{
		cout<<"\n"<<"请输入图书所属子类别："<<endl;
		cout<<"\t(1)政治学；（2）经济学；（3）法学；（4）语言；（5）哲学；（6）历史"<<endl;
		cin>>subtheme;		
		switch(subtheme)
		{
		case 1:
			{
				Politics * po = new Politics();
				Book *b = po;
				b->setinfo();
				b->b_display();	
				p->addbook(b);
				Book* t = p->get(p->count()-1);
				t = po;
				break;
			}
		case 2:
			{
				Economy * ec = new Economy();
				Book *b = ec;
				b->setinfo();
				b->b_display();	
				p->addbook(b);
				Book* t = p->get(p->count()-1);
				t = ec;
				break;
			}
		case 3:
			{
				Law * la = new Law();
				Book *b = la;
				b->setinfo();
				b->b_display();	
				p->addbook(b);
				Book* t = p->get(p->count()-1);
				t = la;
				break;
			}
		case 4:
			{
				Linguistic * li = new Linguistic();
				Book *b = li;
				b->setinfo();
				b->b_display();	
				p->addbook(b);
				Book* t = p->get(p->count()-1);
				t = li;
				break;
			}
		case 5:
			{
				Philosophy * phi = new Philosophy();
				Book *b = phi;
				b->setinfo();
				b->b_display();	
				p->addbook(b);
				Book* t = p->get(p->count()-1);
				t = phi;
				break;
			}
		case 6:
			{
				History * hi = new History();
				Book *b = hi;
				b->setinfo();
				b->b_display();	
				p->addbook(b);
				Book* t = p->get(p->count()-1);
				t = hi;
				break;
			}
		}
	}
	if(theme == 2)//自然科学
	{		
		cout<<"\n"<<"请输入图书所属子类别："<<endl;
		cout<<"\t(1)数学；（2）物理学；（3）计算机科学；（4）化学；（5）地理学；（6）生物学"<<endl;
		cin>>subtheme;		
		switch(subtheme)
		{
		case 1:
			{
				Mathe * ma = new Mathe();
				Book *b = ma;
				b->setinfo();
				b->b_display();	
				p->addbook(b);
				Book* t = p->get(p->count()-1);
				t = ma;
				break;
			}
		case 2:
			{
				Physics * ph = new Physics();
				Book *b = ph;
				b->setinfo();
				b->b_display();	
				p->addbook(b);
				Book* t = p->get(p->count()-1);
				t = ph;
				break;
			}
		case 3:
			{
				Computer * com = new Computer();
				//Natural *na = &com; 
				Book *b = com;
				b->setinfo();
				b->b_display();	
				p->addbook(b);
				Book* t = p->get(p->count()-1);
				t = com;
				break;
			}
		case 4:
			{
				Chemistry * ch = new Chemistry();
				Book *b = ch;
				b->setinfo();
				b->b_display();	
				p->addbook(b);
				Book* t = p->get(p->count()-1);
				t = ch;
				break;
			}
		case 5:
			{
				Geography * geo = new Geography();
				Book *b = geo;
				b->setinfo();
				b->b_display();	
				p->addbook(b);
				Book* t = p->get(p->count()-1);
				t = geo;
				break;
			}
		case 6:
			{
				Biography * bio = new Biography();
				Book *b = bio;
				b->setinfo();
				b->b_display();	
				p->addbook(b);
				Book* t = p->get(p->count()-1);
				t = bio;
				break;
			}
		}
	}
}

void delbooks(Bookdb* p)
{
	cout<<"\n"<<"请输入要删除的图书编号："<<endl;
	string n;
	cin>>n;
	p->delbook(n);
}

void findbooks(Bookdb*p)
{
	cout<<"\n"<<"请输入要查找的图书编号："<<endl;
	string n;
	cin>>n;
	p->listbook(n);
}
//读者板块
void addreader(Readerdb* p)
{
	int r_type;
	cout<<"\n"<<"请输入读者身份（1代普通读者，2代表学生）";
	cin>>r_type;
	if(r_type == 1)//普通读者
	{
		Ordireader * per = new Ordireader();
		Reader *b = per;
		b->r_setinfo();
		b->r_display();	
		p->addreader(b);
		Reader* t = p->get(p->count()-1);
		t = per;
	}
	if(r_type == 2)//学生
	{		
		Student * stu = new Student();
		Reader *b = stu;
		b->r_setinfo();
		b->r_display();	
		p->addreader(b);
		Reader* t = p->get(p->count()-1);
		t = stu;
	}
}

void delreader(Readerdb* p)
{
	cout<<"\n"<<"请输入要删除的读者编号："<<endl;
	string n;
	cin>>n;
	p->delreader(n);
}

void findreader(Readerdb* p)
{
	cout<<"\n"<<"请输入要查找的读者编号："<<endl;
	string n;
	cin>>n;
	p->listreader(n);
}
//界面函数
void mainjiemian()//主界面
{
	cout<<"***********************************"<<endl;
	cout<<"          图 书 管 理 系 统            "<<"\n"<<endl;
	cout<<"              （1）借书/还书               "<<"\n"<<endl;
	cout<<"              （2）图书管理           "<<"\n"<<endl;
	cout<<"              （3）用户管理           "<<"\n"<<endl;
	cout<<"              （0）退出           "<<"\n"<<endl;
	cout<<"***********************************"<<endl;
}

void bookjiemian()
{
	cout<<"——————————————"<<endl;
	cout<<"         图 书 管 理          "<<"\n"<<endl;
	cout<<"         （1）增加          "<<"\n"<<endl;
	cout<<"         （2）删除          "<<"\n"<<endl;
	cout<<"         （3）查找          "<<"\n"<<endl;
	cout<<"         （4）返回   "<<"\n"<<endl;
	cout<<"——————————————"<<endl;
}

void readerjiemian()
{
	cout<<"——————————————"<<endl;
	cout<<"         用 户 管 理          "<<"\n"<<endl;
	cout<<"         （1）增加          "<<"\n"<<endl;
	cout<<"         （2）删除          "<<"\n"<<endl;
	cout<<"         （3）查找          "<<"\n"<<endl;
	cout<<"         （4）返回    "<<"\n"<<endl;
	cout<<"——————————————"<<endl;
}
//主板块
void borroworreturn(Bookdb* bd,Readerdb* rd)
{
	char br;
	cout<<"借书请输入1；还书请输入2；"<<endl;
	cin>>br;
	if(br == '1')
	{
		string r_id ="";	
		string b_id = "";
		int r_flag,b_flag;
		do
		{
			cout<<"请输入借书证号："<<endl;
			cin>>r_id;
			r_flag = rd->findreader(r_id);
		}while(r_flag == -1);
		do
		{
			cout<<"请输入要借的图书编号："<<endl;
			cin>>b_id;
			b_flag = bd->findbook(b_id);
		}while(b_flag == -1);

		Reader * r = rd->get(r_flag);
		if(r->r_borrowed == 1)
		{
			Book * b = bd->get(b_flag);
			if(b->b_borrowed == 2)
				cout<<"该书已被他人借出！"<<endl;
			else
			{
				r->r_borrowed = 2;
				r->r_borrow(b_id);
				b->b_borrowed = 2;
				cout<<"借书成功！"<<endl;
			}
		}
		else
			cout<<"您已借过图书，请归还后再借！"<<endl;
		
	}
	if(br == '2')
	{
		string r_id ="";
		int r_flag;
		do
		{
			cout<<"请输入借书证号："<<endl;
			cin>>r_id;
			r_flag = rd->findreader(r_id);
		}while(r_flag == -1);

		Reader * r = rd->get(r_flag);
		if(r->r_borrowed != 1)
		{
			string b_id = r->brbook;
			int i = bd->findbook(b_id);
			Book * b = bd->get(i);
			r->r_return();
			b->b_return();
			cout<<"还书成功！"<<endl;
		}
		else
			cout<<"您还没有借书！"<<endl;
	}
}

void booksmanage(Bookdb* d)//图书管理
{
	int in;
	do
	{
		bookjiemian();
		cin>>in;
		switch(in)
		{
		case 1:
			addbooks(d);
			break;
		case 2:
			delbooks(d);
			break;
		case 3:
			findbooks(d);
			break;
		case 4:
			break;
		default:
			cout<<"输入错误，请重新输入。"<<endl;
		} 
	}while(in!= 4);
}

void readersmanage(Readerdb* d)
{
	int in;
	do
	{
		readerjiemian();
		cin>>in;
		switch(in)
		{
		case 1:
			addreader(d);
			break;
		case 2:
			delreader(d);
			break;
		case 3:
			findreader(d);
			break;
		case 4:
			break;
		default:
			cout<<"输入错误，请重新输入。"<<endl;
		} 
	}while(in!= 4);
}

int main(void)
{
	Bookdb bookdb;
	Bookdb * bdb = &bookdb;
	Readerdb readerdb;
	Readerdb * rdb = &readerdb;
	
	Computer * com = new Computer(); 
	com->name = "C语言教程";
	com->subject = 1;
	com->no = "001";
	com->price = 40;
	com->sum = 1;
	Book *b = com;
	b->b_display();	
	bookdb.addbook(b);

	com = new Computer(); 
	com->name = "C++教程";
	com->subject = 2;
	com->no = "002";
	com->price = 50;
	com->sum = 1;
	b = com;
	b->b_display();	
	bookdb.addbook(b);

	Student * stu = new Student();
	stu->name = "Tom";
	stu->cardid = "001";
	Reader *r = stu;
	r->r_display();	
	readerdb.addreader(r);

	stu = new Student();
	stu->name = "Jerry";
	stu->cardid = "002";
	r = stu;
	r->r_display();	
	readerdb.addreader(r);

	int in;
	do
	{
		mainjiemian();
		cin>>in;
		switch(in)
		{
		case 1:
			borroworreturn(bdb,rdb);
			break;
		case 2:
			booksmanage(bdb);
			break;
		case 3:
			readersmanage(rdb);
			break;
		} 
	}while(in!= 0);

	
	system("pause");
	return 0;
}

