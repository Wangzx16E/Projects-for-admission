#pragma once
#include "natural.h"
class Computer :
	public Natural
{
public:
	Computer(void);
	~Computer(void);

	int sum;//ͼ������
	int subject;//�������C���ԣ�C++��JAVA��
	void setinfo();//����ͼ����Ϣ
	void b_display();
	double b_calval();
};

