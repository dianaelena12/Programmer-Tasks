/********************************************************************************
** Form generated from reading UI file 'ExamOOP1.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMOOP1_H
#define UI_EXAMOOP1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamOOP1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExamOOP1Class)
    {
        if (ExamOOP1Class->objectName().isEmpty())
            ExamOOP1Class->setObjectName(QStringLiteral("ExamOOP1Class"));
        ExamOOP1Class->resize(600, 400);
        menuBar = new QMenuBar(ExamOOP1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ExamOOP1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExamOOP1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ExamOOP1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(ExamOOP1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ExamOOP1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ExamOOP1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ExamOOP1Class->setStatusBar(statusBar);

        retranslateUi(ExamOOP1Class);

        QMetaObject::connectSlotsByName(ExamOOP1Class);
    } // setupUi

    void retranslateUi(QMainWindow *ExamOOP1Class)
    {
        ExamOOP1Class->setWindowTitle(QApplication::translate("ExamOOP1Class", "ExamOOP1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamOOP1Class: public Ui_ExamOOP1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMOOP1_H
