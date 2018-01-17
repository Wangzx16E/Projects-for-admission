#pragma once
#include "Book.h"
class Natural :
	public Book
{
public:
	Natural(void);
	~Natural(void);

	int theme;//2 自然科学类
	virtual void setinfo();//设置图书信息
	virtual void b_display() ;
	virtual double b_calval() ;
};

