#pragma once
#include "natural.h"
class Mathe :
	public Natural
{
public:
	Mathe(void);
	~Mathe(void);

	int sum;//图书数量
	int subject;//具体类别（几何学，离散数学）
	void setinfo();//设置图书信息
	void b_display();
	double b_calval();
};

