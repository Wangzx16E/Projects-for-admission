#pragma once
#include "natural.h"
class Geography :
	public Natural
{
public:
	Geography(void);
	~Geography(void);

	int sum;//ͼ������
	int subject;//�������
	void setinfo();//����ͼ����Ϣ
	void b_display();
	double b_calval();
};

