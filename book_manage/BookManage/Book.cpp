#include "StdAfx.h"
#include "Book.h"
#include <string>
#include <iostream>

using namespace std;

Book::Book(void)
{
	name = "";
	no = "0";
	price = 0;
	b_borrowed = 1;
	b_del = 1;
}

Book::~Book(void)
{
}

void Book::setinfo()
{
}

void Book::b_display()
{
}

double Book::b_calval()
{
	return 0;
}

void Book::b_borrow()
{
	b_borrowed = 2;
}

void Book::b_return()
{
	b_borrowed = 1;
}
