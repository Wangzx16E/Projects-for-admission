#pragma once
#include <string>

using namespace std;

class Book
{
public:
	Book(void);
	~Book(void);

	string name;//图书名称
	string no;//图书编号
	
	int b_borrowed;//1为在架，2为借出
	int b_del;//1为存在，2为删除
	double price;//价格

	virtual void setinfo();//设置图书信息
	virtual void b_display();//显示信息
	virtual double b_calval();//计算价值
	void b_borrow();
	void b_return();
};

