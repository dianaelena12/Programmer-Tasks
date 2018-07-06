#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ExamOOP1.h"

class ExamOOP1 : public QMainWindow
{
	Q_OBJECT

public:
	ExamOOP1(QWidget *parent = Q_NULLPTR);

private:
	Ui::ExamOOP1Class ui;
};
