#pragma once
#include "Book.h"
class Natural :
	public Book
{
public:
	Natural(void);
	~Natural(void);

	int theme;//2 ��Ȼ��ѧ��
	virtual void setinfo();//����ͼ����Ϣ
	virtual void b_display() ;
	virtual double b_calval() ;
};

