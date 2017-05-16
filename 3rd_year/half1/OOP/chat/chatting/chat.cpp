#include "chat.h"

void listening (Chat &chat)
{
    while(1)
    {
//        Sleep(SECOND);
        chat.mutex.lock();
        chat.readyRead();
        chat.mutex.unlock();
    }
}

void IAmOnline (Chat &chat)
{
    std::string here = "";
    while (1)
    {
        chat.mutex.lock();
        chat.send(here, QHostAddress::Broadcast);
        chat.mutex.unlock();
//        Sleep(SECOND);
    }
}

Chat::Chat(QObject *parent) : QObject(parent)
{
    localIP = QHostAddress("192.168.1.64");

    socket_receiver.bind(localIP, port);

    std::thread listen(listening, std::ref(*this)),
                who_is_online(IAmOnline, std::ref(*this));

    listen.detach();   who_is_online.detach();

    std::string HERuser = "User is here";
    send(HERuser, QHostAddress::Broadcast);
}

void Chat::send(std::string &message, const QHostAddress &address)
{
    if (address != QHostAddress::Broadcast && message != "1" && message != "User is here")
        history.push_back(localIP.toString().toStdString() + ": " + message + "\n");

    if (!message.empty())
    {
        qDebug() << "Message (send)" << message.c_str() << "\n";
        if (message != "1") message = std::string("0") + message;
    }

    qDebug() << "\nSend message: " << "\"" << message.c_str() << "\"";

    QByteArray Data(message.c_str());

    socket_sender.writeDatagram(Data, address, port); //send it with socket
}

void Chat::sendFile(QString Filename, const QHostAddress &address)
{
    QByteArray data;

    QFile file(Filename);

    if(!file.open(QIODevice::ReadOnly))
        return;

    data.append('2');

    data.append(file.readAll());
    qDebug() << "file sending data:" << data;

    socket_sender.writeDatagram(data, address, port); //send it with socket
    file.close();
}

void Chat::readyRead()
{
    bool wasLoop = false; //это переменаая, которая активирует сигнал
    clearUserList();

    while (socket_receiver.hasPendingDatagrams())
      {
        wasLoop = true;
        QByteArray datagram;
        datagram.resize(socket_receiver.pendingDatagramSize());

        QHostAddress address;
        socket_receiver.readDatagram(datagram.data(), datagram.size(), &address);

        if (datagram[0] == '2')
        {
            QFile file("temp.bmp");

            if(!file.open(QIODevice::WriteOnly))
                return;

            datagram.remove(0, 1);
            file.write(datagram);

            file.close();
            emit getFile(); //file
        }

        std::string message = datagram.toStdString(),
                    _address = address.toString().toStdString();

        users.insert(_address);

        if (!message.empty())
        {
            if (message[0] == '0')
            {
                std::string sys = "1";
                history.push_back(_address + ": " + message.substr(1, message.length()) + "\n");
                send(sys, address);
            }

            if (message[0] == '1')
                emit submit();
        }
      }

    if (wasLoop) emit getMes();
}

void Chat::clearUserList()
{
    static size_t i = 0;
    size_t OnlineTime = 600;

    if (i++ == OnlineTime)    // раз в 60 секунд остеиваются пользователи, не проявляющие активность
    {
        i = 0;
        users.clear();
        qDebug("User-Set was cleared");
    }
}

