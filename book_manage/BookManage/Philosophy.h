#pragma once
#include "social.h"
class Philosophy :
	public Social
{
public:
	Philosophy(void);
	~Philosophy(void);

	int sum;//ͼ������
	int subject;//�������
	void setinfo();//����ͼ����Ϣ
	void b_display();
	double b_calval();
};
