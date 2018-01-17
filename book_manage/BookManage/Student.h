#pragma once
#include "reader.h"
#include <string>

using namespace std;
class Student :
	public Reader
{
public:
	Student(void);
	~Student(void);

	void r_setinfo();//设置读者信息
	void r_display();//显示读者信息
	void r_borrow(string num);
	void r_return();//还书

};

