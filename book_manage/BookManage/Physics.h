#pragma once
#include "natural.h"
class Physics :
	public Natural
{
public:
	Physics(void);
	~Physics(void);

	int sum;//图书数量
	int subject;//具体类别（力学，电磁学）
	void setinfo();//设置图书信息
	void b_display();
	double b_calval();
};

