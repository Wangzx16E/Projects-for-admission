#pragma once
#include "natural.h"
class Chemistry :
	public Natural
{
public:
	Chemistry(void);
	~Chemistry(void);

	int sum;//图书数量
	int subject;//具体类别（无机化学，有机化学）
	void setinfo();//设置图书信息
	void b_display();
	double b_calval();
};

