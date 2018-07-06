/********************************************************************************
** Form generated from reading UI file 'TaskManager.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskManager
{
public:
    QListWidget *tasksList;
    QLineEdit *description;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *startButton;
    QPushButton *doneButton;

    void setupUi(QWidget *TaskManager)
    {
        if (TaskManager->objectName().isEmpty())
            TaskManager->setObjectName(QStringLiteral("TaskManager"));
        TaskManager->resize(453, 409);
        tasksList = new QListWidget(TaskManager);
        tasksList->setObjectName(QStringLiteral("tasksList"));
        tasksList->setGeometry(QRect(10, 20, 256, 321));
        description = new QLineEdit(TaskManager);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(280, 20, 151, 71));
        addButton = new QPushButton(TaskManager);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(300, 100, 101, 31));
        removeButton = new QPushButton(TaskManager);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(300, 150, 101, 31));
        startButton = new QPushButton(TaskManager);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(30, 350, 91, 41));
        doneButton = new QPushButton(TaskManager);
        doneButton->setObjectName(QStringLiteral("doneButton"));
        doneButton->setGeometry(QRect(140, 350, 91, 41));

        retranslateUi(TaskManager);

        QMetaObject::connectSlotsByName(TaskManager);
    } // setupUi

    void retranslateUi(QWidget *TaskManager)
    {
        TaskManager->setWindowTitle(QApplication::translate("TaskManager", "TaskManager", nullptr));
        addButton->setText(QApplication::translate("TaskManager", "ADD", nullptr));
        removeButton->setText(QApplication::translate("TaskManager", "REMOVE", nullptr));
        startButton->setText(QApplication::translate("TaskManager", "START", nullptr));
        doneButton->setText(QApplication::translate("TaskManager", "DONE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskManager: public Ui_TaskManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
