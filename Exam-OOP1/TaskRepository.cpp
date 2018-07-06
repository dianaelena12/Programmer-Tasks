#include "TaskRepository.h"

TaskRepository::TaskRepository(string fileName1, string fileName2)
{
	this->dumpFile = fileName2;
	this->readProgrammersFromFile(fileName1);
	this->readTasksFromFile(fileName2);
}

void TaskRepository::addTask(const Task & t)
{
	this->tasks.push_back(t);
}

void TaskRepository::addProgrammer(const Programmer & p)
{
	this->programmers.push_back(p);
}

void TaskRepository::removeTask(const string descr)
{
	for (int i = 0; i < this->tasks.size(); i++) {
		if (this->tasks[i].getDescription() == descr)
			this->tasks.erase(this->tasks.begin() + i);
	}
}

int TaskRepository::getIDFromDescr(const string descr)
{
	for (int i = 0; i < this->tasks.size(); i++) {
		if (this->tasks[i].getDescription() == descr)
			return this->tasks[i].getID();
	}
	return -1;
}

Programmer TaskRepository::getProgrammerById(int id)
{
	for (int i = 0; i < this->programmers.size(); i++) {
		if (this->programmers[i].getId() == id)
			return this->programmers[i];
	}
	return Programmer{ 0,"" };
}

void TaskRepository::readProgrammersFromFile(string fileName)
{
	ifstream in(fileName);
	string line;
	while (getline(in, line)) {
		stringstream ss{ line };
		string tolken;
		vector<string> aux;
		while (getline(ss, tolken, '|')) {
			aux.push_back(tolken);
		}
		if (aux.size() == 2) {
			Programmer t(stoi(aux[0]), aux[1]);
			this->addProgrammer(t);
		}
	}
	in.close();
}

void TaskRepository::readTasksFromFile(string fileName)
{
	ifstream in(fileName);
	string line;
	while (getline(in, line)) {
		stringstream ss{ line };
		string tolken;
		vector<string> aux;
		while (getline(ss, tolken, '|')) {
			aux.push_back(tolken);
		}
		if (aux.size() == 3) {
			Task t(aux[1], aux[2], stoi(aux[0]));
			this->addTask(t);
		}
	}
	in.close();
}

void TaskRepository::dumpIntoFile()
{
	ofstream out(this->dumpFile);
	for (auto t : this->tasks) {
		out << t.getID() << "|" << t.getDescription() << "|" << t.getStatus() << endl;
	}
	out.close();
}
