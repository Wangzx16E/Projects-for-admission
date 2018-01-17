#pragma once
#include "social.h"
class Law :
	public Social
{
public:
	Law(void);
	~Law(void);

	int sum;//图书数量
	int subject;//具体类别
	void setinfo();//设置图书信息
	void b_display();
	double b_calval();
};

