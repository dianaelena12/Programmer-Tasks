#pragma once
#include "Programmer.h"
#include "Task.h"
#include <vector>
#include <fstream>

class TaskRepository
{
private:
	vector<Programmer> programmers;
	vector<Task> tasks;
	string dumpFile;
public:
	TaskRepository(string fileName1, string fileName2);

	void addTask(const Task& t);

	void addProgrammer(const Programmer& p);

	void removeTask(const string descr);

	int getIDFromDescr(const string descr);

	Programmer getProgrammerById(int id);

	void readProgrammersFromFile(string fileName);

	void readTasksFromFile(string fileName);

	void dumpIntoFile();

	vector<Task> getTasks() const { return this->tasks; }
	vector<Programmer> getProgrammers() const { return this->programmers; }
};