#pragma once
#include "social.h"
class Linguistic :
	public Social
{
public:
	Linguistic(void);
	~Linguistic(void);
	int sum;//ͼ������
	int subject;//�������
	void setinfo();//����ͼ����Ϣ
	void b_display();
	double b_calval();
};

