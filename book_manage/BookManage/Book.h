#pragma once
#include <string>

using namespace std;

class Book
{
public:
	Book(void);
	~Book(void);

	string name;//ͼ������
	string no;//ͼ����
	
	int b_borrowed;//1Ϊ�ڼܣ�2Ϊ���
	int b_del;//1Ϊ���ڣ�2Ϊɾ��
	double price;//�۸�

	virtual void setinfo();//����ͼ����Ϣ
	virtual void b_display();//��ʾ��Ϣ
	virtual double b_calval();//�����ֵ
	void b_borrow();
	void b_return();
};

