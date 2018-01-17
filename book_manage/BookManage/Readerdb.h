#pragma once
#include "Reader.h"
#include <string>
#include <vector>
using namespace std;
class Readerdb
{
public:
	Readerdb(void);
	~Readerdb(void);

	void addreader(Reader* b);
	void delreader(string num);
	void listreader(string num);
	int findreader(string num);//·µ»ØvectorÏÂ±ê
	Reader* get(int i);
	int count();
private:
	vector<Reader*> readers;
};

