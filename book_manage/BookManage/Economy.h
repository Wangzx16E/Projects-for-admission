#pragma once
#include "social.h"
class Economy :
	public Social
{
public:
	Economy(void);
	~Economy(void);

	int sum;//ͼ������
	int subject;//�������
	void setinfo();//����ͼ����Ϣ
	void b_display();
	double b_calval();
};

