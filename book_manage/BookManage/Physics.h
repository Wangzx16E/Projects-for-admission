#pragma once
#include "natural.h"
class Physics :
	public Natural
{
public:
	Physics(void);
	~Physics(void);

	int sum;//ͼ������
	int subject;//���������ѧ�����ѧ��
	void setinfo();//����ͼ����Ϣ
	void b_display();
	double b_calval();
};

