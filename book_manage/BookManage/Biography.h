#pragma once
#include "natural.h"
class Biography :
	public Natural
{
public:
	Biography(void);
	~Biography(void);

	int sum;//ͼ������
	int subject;//�������
	void setinfo();//����ͼ����Ϣ
	void b_display();
	double b_calval();
};

