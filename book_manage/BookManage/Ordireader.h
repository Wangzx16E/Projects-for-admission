#pragma once
#include "reader.h"
#include <string>
class Ordireader :
	public Reader
{
public:
	Ordireader(void);
	~Ordireader(void);

	void r_setinfo();//���ö�����Ϣ
	void r_display();//��ʾ������Ϣ
	void r_borrow(string num);
	void r_return();//����
};

