#pragma once
#include "natural.h"
class Computer :
	public Natural
{
public:
	Computer(void);
	~Computer(void);

	int sum;//图书数量
	int subject;//具体类别（C语言，C++，JAVA）
	void setinfo();//设置图书信息
	void b_display();
	double b_calval();
};

