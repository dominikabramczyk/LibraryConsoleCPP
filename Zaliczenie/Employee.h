#pragma once
#include "User.h"
#include <string>
using namespace std;

class Employee /*: public User*/
{	
public:
	string Name, Surename;
	Employee(string Name, string Surename);
	/*Employee add_user(string , string);*/
	
};

