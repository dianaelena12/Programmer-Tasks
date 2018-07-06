#pragma once

#include <QWidget>
#include "ui_TaskManager.h"
#include "Controller.h"
#include "Exception.h"

class TaskManager : public QWidget, public Observer
{
	Q_OBJECT

public:
	TaskManager(const Programmer& p, Controller& c,QWidget *parent = Q_NULLPTR);
	~TaskManager();
	void update();
	void add();
	void remove();
	void start();
	void done();

private:
	Ui::TaskManager ui;
	Programmer programmer;
	Controller& ctrl;
};
