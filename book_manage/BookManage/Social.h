#pragma once
#include "Book.h"
class Social :
	public Book
{
public:
	Social(void);
	~Social(void);

	int theme;//1 社科类
	virtual void setinfo();//设置图书信息
	virtual void b_display() ;
	virtual double b_calval();
};

