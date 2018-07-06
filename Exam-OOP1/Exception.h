#pragma once
#include <exception>

using namespace std;

class NotOpenException : public exception
{
public:
	const char* what() const throw()
	{
		return "The task is not open!";
	}
};