#pragma once
#include "social.h"
class Politics :
	public Social
{
public:
	Politics(void);
	~Politics(void);

	int sum;//ͼ������
	int subject;//�������
	void setinfo();//����ͼ����Ϣ
	void b_display();
	double b_calval();
};

