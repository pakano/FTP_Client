#ifndef FTP_H
#define FTP_H

#include <QObject>
#include <ftplib.h>

struct FTP_DATA
{
    QString host;
    QString user;
    QString pass;
};

struct FTP_FILE_INFO
{
    QString access;//Ȩ��
    QString link_cnt;//������
    QString ower;//����
    QString group;//����
    QString size;//��С
    QString date;//����(3)
    QString file_name;//�ļ���(last)
    //    uintptr_t size;
    //    bool is_dir;
};

class Ftp
{
public:
    Ftp();
    ~Ftp();
public:
    bool login(const FTP_DATA& data);
    QString pwd();
    std::vector<FTP_FILE_INFO> dir();
    bool cd(const QString& path);
    bool cdup();
    bool put(const QString& put_file);
    bool get(const QString& get_file, const QString& remote_file);
    bool del(const QString& file);
    QString error();
private:

private:
    ftplib* ftp;
    std::string cur_path;
};

#endif // FTP_H
