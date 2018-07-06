#include "Tests.h"
#include "qmessagebox.h"

void Test::removeTest()
{
	TaskRepository r{ "testP.txt","testT.txt" };
	Controller c{ r };
	c.addTask(Task{ "Go","Open",0 });
	vector<Task> testTasks = c.getAllTasks();
	c.removeTask("Go");
	assert(c.getAllTasks().size() != testTasks.size());
	assert(testTasks[0].getID() == 1);
	c.addTask(Task{ "Go","Open",0 });
}

void Test::updateTest()
{
	TaskRepository r{ "testP.txt","testT.txt" };
	Controller c{ r };
	vector<Task> testTasks = c.getAllTasks();
	c.removeTask("neah-uh");
	c.addTask(Task{ "neah-ul", "In progress",2 });

	Task t{ "neah-ul", "Closed",2 };
	
	c.update(t);

	assert(testTasks.size() == c.getAllTasks().size());

	vector<Task> testTasks2 = c.getAllTasks();
	assert(testTasks2[2].getStatus() == "Closed");
}

void Test::allTests()
{
	removeTest();
	updateTest();
}
