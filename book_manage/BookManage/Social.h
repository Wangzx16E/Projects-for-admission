#pragma once
#include "Book.h"
class Social :
	public Book
{
public:
	Social(void);
	~Social(void);

	int theme;//1 �����
	virtual void setinfo();//����ͼ����Ϣ
	virtual void b_display() ;
	virtual double b_calval();
};

