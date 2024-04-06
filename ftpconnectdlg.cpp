#include "ftpconnectdlg.h"
#include "ui_ftpconnectdlg.h"

FtpConnectDlg::FtpConnectDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FtpConnectDlg)
{
    ui->setupUi(this);
    ui->lineEdit_Host->setText("172.20.10.4");
    ui->lineEdit_User->setText("root");
    ui->lineEdit_Pass->setText("123");
    connect(ui->btn_connect,&QPushButton::clicked,this,&FtpConnectDlg::onConnect);
}

FtpConnectDlg::~FtpConnectDlg()
{
    delete ui;
}

FTP_DATA FtpConnectDlg::ftp_data()
{
    return
        //c++20 语法，返回一个类，快速构造
    {
        .host = ui->lineEdit_Host->text(),
        .user = ui->lineEdit_User->text(),
        .pass = ui->lineEdit_Pass->text()
    };
}

void FtpConnectDlg::onConnect()
{
    QDialog::accept();
}
