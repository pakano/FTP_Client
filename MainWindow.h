#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QCloseEvent>
#include <QTimerEvent>
#include <QLabel>
#include "Ftp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClass; };
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init_menu();

public:
    static QString cur_time();
 
public slots:
    void onConnect();
    void cellDoubleClicked(int row, int idx);
    void cdupAction();
    void refAction();
    void putAction();
    void getAction();
    void delAction();
protected:
    void closeEvent(QCloseEvent* e);
    void timerEvent(QTimerEvent* e);
private:
    QString get_file_name(int row);
    void set_pwd();
    void clear_ui_list();
    void insert_list(const std::vector<FTP_FILE_INFO>& list);
    void insert_row(int row, const FTP_FILE_INFO& info);
    void insert_item(int row, int idx, QString item);

private:
    Ui::mainwindowClass* ui;

    QLabel *ui_connect_status;
    QLabel *ui_pwd;
    QLabel *ui_cur_time;
    int timer1;
    Ftp ftp;
};
