#pragma once
#include "social.h"
class History :
	public Social
{
public:
	History(void);
	~History(void);
	int sum;//ͼ������
	int subject;//�������
	void setinfo();//����ͼ����Ϣ
	void b_display();
	double b_calval();
};

