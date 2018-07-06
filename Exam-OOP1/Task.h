#pragma once
#include <string.h>
#include <sstream>

using namespace std;

class Task
{
private:
	string description;
	string status;
	int id;
public:
	Task(string descr, string status, int id) : description(descr), id(id), status(status) {}
	string getDescription() const { return this->description; }
	string getStatus() const { return this->status; }
	int getID() const { return this->id; }
	void setID(int id) { this->id = id; }
	string toString()
	{
		stringstream s;
		s << this->description << "|" << this->status << "|";
		return s.str();
	}
};