#pragma once
#include <string>

using namespace std;

class Reader
{
public:
	Reader(void);
	~Reader(void);

	string name;
	string cardid;//����֤��
	int r_borrowed;//1����û���飬2��������
	int r_del;//1������ڣ�2����ɾ��
	int borrow_num;//���鱾��
	string brbook;//������ı��

	virtual void r_setinfo();//���ö�����Ϣ
	virtual void r_display();//��ʾ������Ϣ
	virtual void r_borrow(string num);//����
	virtual void r_return();//����
};

