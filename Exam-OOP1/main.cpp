#include "ExamOOP1.h"
#include "TaskManager.h"
#include "Tests.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Test::allTests();
	TaskRepository r("programmers.txt","tasks.txt");
	Controller c(r);
	vector<Programmer> programmers = c.getAllProgrammers();
	TaskManager* q;
	for (auto it : programmers) {
		q = new TaskManager{ it,c };
		q->show();
	}
	return a.exec();
}
