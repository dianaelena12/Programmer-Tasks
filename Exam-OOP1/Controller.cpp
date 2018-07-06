#include "Controller.h"

void Controller::addTask(Task & t)
{
	this->repo.addTask(t);
	this->repo.dumpIntoFile();
	this->notify();
}

void Controller::removeTask(const string descr)
{
	this->repo.removeTask(descr);
	this->repo.dumpIntoFile();
	this->notify();
}

void Controller::update(Task t)
{

	this->repo.removeTask(t.getDescription());
	this->repo.addTask(t);
	this->repo.dumpIntoFile();
	this->notify();
}

int Controller::getIDFromDescription(const string descr)
{
	return this->repo.getIDFromDescr(descr);

}

Programmer Controller::programmerById(int id)
{
	return this->repo.getProgrammerById(id);
}
