#pragma once
#include "reader.h"
#include <string>

using namespace std;
class Student :
	public Reader
{
public:
	Student(void);
	~Student(void);

	void r_setinfo();//���ö�����Ϣ
	void r_display();//��ʾ������Ϣ
	void r_borrow(string num);
	void r_return();//����

};

