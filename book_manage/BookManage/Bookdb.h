#pragma once
#include "Book.h"
#include <string>
#include <vector>
using namespace std;

class Bookdb
{
public:
	Bookdb(void);
	~Bookdb(void);

	void addbook(Book* b);
	void delbook(string num);
	void listbook(string num);
	int findbook(string num);//·µ»ØvectorÏÂ±ê
	Book* get(int i);
	int count();
private:
	vector<Book*> books;

};

