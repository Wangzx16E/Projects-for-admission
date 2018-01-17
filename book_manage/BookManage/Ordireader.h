#pragma once
#include "reader.h"
#include <string>
class Ordireader :
	public Reader
{
public:
	Ordireader(void);
	~Ordireader(void);

	void r_setinfo();//设置读者信息
	void r_display();//显示读者信息
	void r_borrow(string num);
	void r_return();//还书
};

