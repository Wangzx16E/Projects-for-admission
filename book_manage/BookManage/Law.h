#pragma once
#include "social.h"
class Law :
	public Social
{
public:
	Law(void);
	~Law(void);

	int sum;//ͼ������
	int subject;//�������
	void setinfo();//����ͼ����Ϣ
	void b_display();
	double b_calval();
};

