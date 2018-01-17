#pragma once
#include <string>

using namespace std;

class Reader
{
public:
	Reader(void);
	~Reader(void);

	string name;
	string cardid;//借书证号
	int r_borrowed;//1代表没借书，2代表借过书
	int r_del;//1代表存在，2代表删除
	int borrow_num;//借书本数
	string brbook;//所借书的编号

	virtual void r_setinfo();//设置读者信息
	virtual void r_display();//显示读者信息
	virtual void r_borrow(string num);//借书
	virtual void r_return();//还书
};

