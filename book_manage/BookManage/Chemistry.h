#pragma once
#include "natural.h"
class Chemistry :
	public Natural
{
public:
	Chemistry(void);
	~Chemistry(void);

	int sum;//ͼ������
	int subject;//��������޻���ѧ���л���ѧ��
	void setinfo();//����ͼ����Ϣ
	void b_display();
	double b_calval();
};

