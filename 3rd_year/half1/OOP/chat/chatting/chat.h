#ifndef CHAT_H
#define CHAT_H

#include <QObject>
#include <QHostAddress>
#include <QUdpSocket>
#include <QByteArray>
#include <QDebug>
#include <QMutex>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>

#include <windows.h>
#include <list>
#include <set>
#include <thread>

#define SECOND 1000

class Chat : public QObject
{
private:
    Q_OBJECT

    std::list<std::string> history;
    std::set<std::string> users;

    QHostAddress localIP;
    QUdpSocket socket_sender, socket_receiver;
    QMutex mutex;

    qint64 port = 1234;

    void readyRead();
    void clearUserList();
    friend void listening(Chat&);
    friend void IAmOnline(Chat&);

    bool systemMessage = false;

public:
    explicit Chat(QObject *parent = 0);
    void send(std::string &message, const QHostAddress &address);

    void sendFile(QString Filename, const QHostAddress &address); //file

    auto getUserSet() const { return users; }
    auto getHistory() const { return history; }
    auto getLocalIP() const { return localIP.toString().toStdString(); }

signals:
    void getMes();
    void submit();

    void getFile(); //file
    void hotkey();
};

#endif // CHAT_H
