/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindowClass
{
public:
    QAction *action_connect;
    QAction *action_quit;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QTableWidget *list_file;
    QMenuBar *menuBar;
    QMenu *menu_connect;
    QMenu *menu_quit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainwindowClass)
    {
        if (mainwindowClass->objectName().isEmpty())
            mainwindowClass->setObjectName(QString::fromUtf8("mainwindowClass"));
        mainwindowClass->resize(967, 531);
        action_connect = new QAction(mainwindowClass);
        action_connect->setObjectName(QString::fromUtf8("action_connect"));
        action_quit = new QAction(mainwindowClass);
        action_quit->setObjectName(QString::fromUtf8("action_quit"));
        centralWidget = new QWidget(mainwindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 941, 461));
        list_file = new QTableWidget(groupBox);
        list_file->setObjectName(QString::fromUtf8("list_file"));
        list_file->setGeometry(QRect(10, 20, 921, 421));
        mainwindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainwindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 967, 26));
        menu_connect = new QMenu(menuBar);
        menu_connect->setObjectName(QString::fromUtf8("menu_connect"));
        menu_quit = new QMenu(menuBar);
        menu_quit->setObjectName(QString::fromUtf8("menu_quit"));
        mainwindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainwindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainwindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mainwindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        mainwindowClass->setStatusBar(statusBar);

        menuBar->addAction(menu_connect->menuAction());
        menuBar->addAction(menu_quit->menuAction());
        menu_connect->addAction(action_connect);
        menu_quit->addAction(action_quit);

        retranslateUi(mainwindowClass);

        QMetaObject::connectSlotsByName(mainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindowClass)
    {
        mainwindowClass->setWindowTitle(QCoreApplication::translate("mainwindowClass", "mainwindow", nullptr));
        action_connect->setText(QCoreApplication::translate("mainwindowClass", "\350\277\236\346\216\245", nullptr));
        action_quit->setText(QCoreApplication::translate("mainwindowClass", "\351\200\200\345\207\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("mainwindowClass", "\346\226\207\344\273\266\345\210\227\350\241\250", nullptr));
        menu_connect->setTitle(QCoreApplication::translate("mainwindowClass", "\350\277\236\346\216\245", nullptr));
        menu_quit->setTitle(QCoreApplication::translate("mainwindowClass", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindowClass: public Ui_mainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
