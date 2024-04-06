#include "MainWindow.h"
#include <QDebug>
#include <iostream>
#include <QMessageBox>
#include <QTime>
#include <vector>
#include <QFileDialog>
#include "ftpconnectdlg.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainwindowClass())
{
    ui->setupUi(this);

    //״̬��
    ui_connect_status = new QLabel(tr("ready"));
    ui_pwd = new QLabel(tr("pwd:/"));
    ui_cur_time = new QLabel(MainWindow::cur_time());
    ui->statusBar->addWidget(ui_connect_status);
    ui->statusBar->addWidget(ui_pwd);
    ui->statusBar->addWidget(ui_cur_time);

    //�˵���
    connect(ui->action_quit, &QAction::triggered, this, [=]() {
        qDebug() << "action_exit";
        if (QMessageBox::question(this, this->windowTitle(), "exit! sure?") != QMessageBox::Yes) 
            return;
        exit(0);
     });
    connect(ui->action_connect, &QAction::triggered, this, &MainWindow::onConnect);
    timer1 = startTimer(10);

    ui->list_file->setColumnCount(7);
    //ui->list_file->setHorizontalHeaderLabels({ "Ȩ��","������","����","����","��С","����","�ļ���" });
    ui->list_file->setHorizontalHeaderLabels({ "perm","links","owner","group","size","date","filename" });

    connect(ui->list_file, &QTableWidget::cellDoubleClicked, this, &MainWindow::cellDoubleClicked);

    init_menu();
}

void MainWindow::init_menu()
{
    QMenu* menu = new QMenu(ui->list_file);
    //auto cdupAction = menu->addAction("������һ��Ŀ¼");
    //auto refAction = menu->addAction("ˢ��");
    //auto putAction = menu->addAction("�ϴ�");
    //auto getAction = menu->addAction("����");
    //auto delAction = menu->addAction("ɾ��");
    auto cdupAction = menu->addAction("cdup");
    auto refAction = menu->addAction("refresh");
    auto putAction = menu->addAction("put");
    auto getAction = menu->addAction("get");
    auto delAction = menu->addAction("del");

    ui->list_file->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->list_file, &QTableWidget::customContextMenuRequested, [=](const QPoint& pos) {
        qDebug() << ui->list_file->currentRow();
        menu->exec(ui->list_file->viewport()->mapToGlobal(pos));
        });
    connect(cdupAction, &QAction::triggered, this, &MainWindow::cdupAction);
    connect(refAction, &QAction::triggered, this, &MainWindow::refAction);
    connect(putAction, &QAction::triggered, this, &MainWindow::putAction);
    connect(getAction, &QAction::triggered, this, &MainWindow::getAction);
    connect(delAction, &QAction::triggered, this, &MainWindow::delAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::closeEvent(QCloseEvent* e)
{
    qDebug() << "closeEvent";
    if (QMessageBox::question(this, this->windowTitle(), "exit! sure?") == QMessageBox::Yes)
        return;
    e->ignore();
}

void MainWindow::timerEvent(QTimerEvent* e)
{
    if (e->timerId() != timer1)
        return;
    ui_cur_time->setText(cur_time());
}

void MainWindow::onConnect()
{
    FtpConnectDlg dlg;
    if (dlg.exec() != QDialog::Accepted) 
        return;
    qDebug() << dlg.ftp_data().host;
    qDebug() << dlg.ftp_data().user;
    qDebug() << dlg.ftp_data().pass;

    if (!ftp.login(dlg.ftp_data()))
    {
        QMessageBox::critical(this, tr("error"), tr("connect failed!"));
        return;
    }
  
    qDebug() << dlg.ftp_data().pass;
    ui_connect_status->setText("connectOK:" + dlg.ftp_data().host);

    clear_ui_list();
    set_pwd();
    insert_list(ftp.dir());
}

void MainWindow::cellDoubleClicked(int row, int idx)
{
    if (row == -1)return;
    QString file_name = ui->list_file->item(row, 6)->text();
    if (ui->list_file->item(row, 0)->text()[0] != 'd')file_name = file_name.split(" ")[0];
    if (!ftp.cd(file_name)) {
        QMessageBox::warning(this, this->windowTitle(), QString("%1 change failed��%1 not dir").arg(file_name));
        return;
    }
    set_pwd();
    auto list = ftp.dir();
    if (list.empty()) {
        QMessageBox::warning(this, this->windowTitle(), QString("%1 change failed��%1 not dir").arg(file_name));
        return;
    }
    clear_ui_list();
    insert_list(list);
}

void MainWindow::cdupAction()
{
    if (!ftp.cdup()) return;
    set_pwd();
    clear_ui_list();
    insert_list(ftp.dir());
}

void MainWindow::refAction()
{
    clear_ui_list();
    insert_list(ftp.dir());
}

void MainWindow::putAction()
{
    QFileDialog file(this, "�ϴ��ļ�");
    file.setFileMode(QFileDialog::FileMode::ExistingFile);
    if (file.exec() != QDialog::Accepted)return;
    auto files = file.selectedFiles();
    if (files.size() > 1) {
        QMessageBox::warning(this, "ѡ���ļ����࣡", "���ѡ��һ���ļ�");
        return;
    }
    qDebug() << files[0];
    if (!ftp.put(files[0])) {
        QMessageBox::warning(this, this->windowTitle(), "�ϴ�ʧ��\n����" + ftp.error());
        return;
    }
    QMessageBox::information(this, this->windowTitle(), "�ϴ��ɹ���");
    clear_ui_list();
    insert_list(ftp.dir());
}

void MainWindow::getAction()
{
    int row = ui->list_file->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, this->windowTitle(), "û��ѡ�������ļ�");
        return;
    }
    QFileDialog file(this, "�����ļ���");
    file.setFileMode(QFileDialog::FileMode::AnyFile);
    file.selectFile(ui->list_file->item(row, 6)->text());
    if (file.exec() != QDialog::Accepted)return;
    auto files = file.selectedFiles();
    if (files.size() > 1) {
        QMessageBox::warning(this, "ѡ���ļ����࣡", "���ѡ��һ���ļ�");
        return;
    }
    qDebug() << files[0];
    if (!ftp.get(files[0], ui->list_file->item(row, 6)->text())) {
        QMessageBox::warning(this, this->windowTitle(), "����ʧ��\n����" + ftp.error());
        return;
    }
    QMessageBox::information(this, this->windowTitle(), "���سɹ���");
}

void MainWindow::delAction()
{
    int row = ui->list_file->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, this->windowTitle(), "û��ѡ��ɾ���ļ�");
        return;
    }
    if (!ftp.del(get_file_name(row)))
    {
        QMessageBox::warning(this, this->windowTitle(), "ɾ��ʧ��\n����" + ftp.error());
        return;
    }
    QMessageBox::information(this, this->windowTitle(), "ɾ���ɹ���");
    clear_ui_list();
    insert_list(ftp.dir());
}

QString MainWindow::cur_time()
{
    return QTime::currentTime().toString();
}

QString MainWindow::get_file_name(int row)
{
    auto file_name = ui->list_file->item(row, 6)->text();
    if (file_name.contains(" ") && ui->list_file->item(row, 0)->text()[0] == 'l')
        file_name = file_name.split(" ")[0];
    return file_name;
}

void MainWindow::set_pwd()
{
    ui_pwd->setText("pwd:" + ftp.pwd());
}

void MainWindow::clear_ui_list()
{
    while (ui->list_file->rowCount() > 0)ui->list_file->removeRow(0);
}

void MainWindow::insert_list(const std::vector<FTP_FILE_INFO>& list)
{
    for (auto& info : list)
    {
        insert_row(ui->list_file->rowCount(), info);
    }
}

void MainWindow::insert_row(int row, const FTP_FILE_INFO& info)
{
    ui->list_file->insertRow(row);
    insert_item(row, 0, info.access);
    insert_item(row, 1, info.link_cnt);
    insert_item(row, 2, info.ower);
    insert_item(row, 3, info.group);
    insert_item(row, 4, info.size);
    insert_item(row, 5, info.date);
    insert_item(row, 6, info.file_name);
}

void MainWindow::insert_item(int row, int idx, QString item)
{
    ui->list_file->setItem(row, idx, new QTableWidgetItem(item));
    ui->list_file->item(row, idx)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
}
