#pragma once
#include <string>

using namespace std;

class Programmer
{
private:
	string name;
	int id;
public:
	Programmer(int id, string name) : name(name), id(id) {}
	~Programmer() {}
	int getId()const { return this->id; }
	string getName() const { return this->name; }
};