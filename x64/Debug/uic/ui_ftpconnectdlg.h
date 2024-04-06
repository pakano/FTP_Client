/********************************************************************************
** Form generated from reading UI file 'ftpconnectdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTPCONNECTDLG_H
#define UI_FTPCONNECTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FtpConnectDlg
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_host;
    QLineEdit *lineEdit_Host;
    QLabel *label_user;
    QLineEdit *lineEdit_User;
    QLabel *label_pass;
    QLineEdit *lineEdit_Pass;
    QPushButton *btn_connect;

    void setupUi(QDialog *FtpConnectDlg)
    {
        if (FtpConnectDlg->objectName().isEmpty())
            FtpConnectDlg->setObjectName(QString::fromUtf8("FtpConnectDlg"));
        FtpConnectDlg->resize(244, 177);
        widget = new QWidget(FtpConnectDlg);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 30, 222, 125));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_host = new QLabel(widget);
        label_host->setObjectName(QString::fromUtf8("label_host"));

        gridLayout->addWidget(label_host, 0, 0, 1, 1);

        lineEdit_Host = new QLineEdit(widget);
        lineEdit_Host->setObjectName(QString::fromUtf8("lineEdit_Host"));

        gridLayout->addWidget(lineEdit_Host, 0, 1, 1, 1);

        label_user = new QLabel(widget);
        label_user->setObjectName(QString::fromUtf8("label_user"));

        gridLayout->addWidget(label_user, 1, 0, 1, 1);

        lineEdit_User = new QLineEdit(widget);
        lineEdit_User->setObjectName(QString::fromUtf8("lineEdit_User"));

        gridLayout->addWidget(lineEdit_User, 1, 1, 1, 1);

        label_pass = new QLabel(widget);
        label_pass->setObjectName(QString::fromUtf8("label_pass"));

        gridLayout->addWidget(label_pass, 2, 0, 1, 1);

        lineEdit_Pass = new QLineEdit(widget);
        lineEdit_Pass->setObjectName(QString::fromUtf8("lineEdit_Pass"));

        gridLayout->addWidget(lineEdit_Pass, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        btn_connect = new QPushButton(widget);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));

        verticalLayout->addWidget(btn_connect);


        retranslateUi(FtpConnectDlg);

        QMetaObject::connectSlotsByName(FtpConnectDlg);
    } // setupUi

    void retranslateUi(QDialog *FtpConnectDlg)
    {
        FtpConnectDlg->setWindowTitle(QCoreApplication::translate("FtpConnectDlg", "Dialog", nullptr));
        label_host->setText(QCoreApplication::translate("FtpConnectDlg", "Host:", nullptr));
        label_user->setText(QCoreApplication::translate("FtpConnectDlg", "User:", nullptr));
        label_pass->setText(QCoreApplication::translate("FtpConnectDlg", "Pass:", nullptr));
        btn_connect->setText(QCoreApplication::translate("FtpConnectDlg", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FtpConnectDlg: public Ui_FtpConnectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTPCONNECTDLG_H
