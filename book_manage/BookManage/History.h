#pragma once
#include "social.h"
class History :
	public Social
{
public:
	History(void);
	~History(void);
	int sum;//图书数量
	int subject;//具体类别
	void setinfo();//设置图书信息
	void b_display();
	double b_calval();
};

