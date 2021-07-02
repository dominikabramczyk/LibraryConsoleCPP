#pragma once
#include <string>
using namespace std;

class Book
{
public:
	string Title, Author;
	bool IsRent;
	Book(string, string);
	void RentBook();
	void ReturnBook();
};

