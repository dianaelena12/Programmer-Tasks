#include "TaskManager.h"
#include <qmessagebox.h>

TaskManager::TaskManager(const Programmer& p, Controller& c,QWidget *parent)
	: QWidget(parent),ctrl(c),programmer(p)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(this->programmer.getName()));

	this->ctrl.registerObserver(this);
	this->update();

	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &TaskManager::add);
	QObject::connect(this->ui.removeButton, &QPushButton::clicked, this, &TaskManager::remove);
	QObject::connect(this->ui.doneButton, &QPushButton::clicked, this, &TaskManager::done);
	QObject::connect(this->ui.startButton, &QPushButton::clicked, this, &TaskManager::start);
}

TaskManager::~TaskManager()
{
}

void TaskManager::update()
{
	this->ui.tasksList->clear();
	vector<Task> tasks = this->ctrl.getAllTasks();
	sort(tasks.begin(), tasks.end(), [](Task& a, Task&b) {return a.getStatus() > b.getStatus(); });
	for (auto &t : tasks) {
		QString current = "";
		current += QString::fromStdString(t.toString());
		if (t.getStatus() == "In progress" || t.getStatus() == "Closed")
			current += QString::fromStdString(this->ctrl.programmerById(t.getID()).getName());
		QListWidgetItem* item = new QListWidgetItem{ current };
		this->ui.tasksList->addItem(item);
	}
}

void TaskManager::add()
{
	string descr = this->ui.description->text().toStdString();

	Task t{ descr,"Open",0 };
	this->ctrl.addTask(t);
	this->update();
}

void TaskManager::remove()
{

	string all = this->ui.tasksList->selectedItems().at(0)->text().toStdString();
	if (all == "")
		return;
	stringstream elem(all);
	vector<string> aux;
	string current;
	while (getline(elem, current, '|'))
		aux.push_back(current);
	this->ctrl.removeTask(aux[0]);
	this->update();
}

void TaskManager::start()
{
	string all = this->ui.tasksList->selectedItems().at(0)->text().toStdString();
	stringstream elem(all);
	vector<string> aux;
	string current;
	while (getline(elem, current, '|'))
		aux.push_back(current);

	try
	{
		if (aux[1] != "Open")
			throw NotOpenException();
		int id = this->ctrl.getIDFromDescription(aux[0]);
		Task t{ aux[0], "In progress", this->programmer.getId() };
		this->ctrl.update(t);
		this->update();
	}
	catch (NotOpenException e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.what()));
		messageBox.setFixedSize(500, 200);
		return;
	}
}

void TaskManager::done()
{
	string all = this->ui.tasksList->selectedItems().at(0)->text().toStdString();
	stringstream elem(all);
	vector<string> aux;
	string current;
	while (getline(elem, current, '|'))
		aux.push_back(current);
	int id = this->ctrl.getIDFromDescription(aux[0]);
	if (aux[1] == "Open")
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "You can't finish a task that hasn't started!");
		messageBox.setFixedSize(500, 200);
		return;
	}
	if (aux[1] == "Closed")
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "You can't finish a task that's allready finished!");
		messageBox.setFixedSize(500, 200);
		return;
	}
	if (id == this->programmer.getId() && aux[1] == "In progress")
	{
		int ID = this->ctrl.getIDFromDescription(aux[0]);
		Task t{ aux[0], "Closed", id };
		this->ctrl.update(t);
		this->update();
	}
	else
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "You can't finish a task that's not yours!");
		messageBox.setFixedSize(500, 200);
		return;
	}
}
