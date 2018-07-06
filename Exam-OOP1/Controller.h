#pragma once
#include "Observer.h"
#include "TaskRepository.h"
#include <algorithm>

//This is the Controller

class Controller : public Subject
{
private:
	TaskRepository repo;
public:
	Controller(TaskRepository& r) : repo(r) {}

	~Controller() {}

	vector<Task> getAllTasks() const { return this->repo.getTasks(); }

	vector<Programmer> getAllProgrammers() const { return this->repo.getProgrammers(); }

	void addTask(Task& t);

	void removeTask(const string descr);
	/*
		This function calls from the TaskRepository the function removeTask, which will
		remove the current task, by description, from the task list
		In: string containing the description of the task
		Out:- the element is removed from the list
	*/

	void update(Task t);
	/*
		This function call from the TaskRepository the functions removeTask and
		addTask in order to update the status of the task
		In: Object of type Task
		Out:- the object was updated
	*/
	int getIDFromDescription(const string descr);

	Programmer programmerById(int id);
	TaskRepository getRepo() const { return this->repo; }


};