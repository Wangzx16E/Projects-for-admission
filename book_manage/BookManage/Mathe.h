#pragma once
#include "natural.h"
class Mathe :
	public Natural
{
public:
	Mathe(void);
	~Mathe(void);

	int sum;//ͼ������
	int subject;//������𣨼���ѧ����ɢ��ѧ��
	void setinfo();//����ͼ����Ϣ
	void b_display();
	double b_calval();
};

