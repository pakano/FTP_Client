#ifndef FTPCONNECTDLG_H
#define FTPCONNECTDLG_H

#include <QDialog>
#include "ftp.h"
#include "ui_ftpconnectdlg.h"


class FtpConnectDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FtpConnectDlg(QWidget *parent = nullptr);
    ~FtpConnectDlg();
public:
    FTP_DATA ftp_data();
public slots:
    void onConnect();
private:
    Ui::FtpConnectDlg *ui;
};

#endif // FTPCONNECTDLG_H
