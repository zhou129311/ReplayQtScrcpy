#ifndef RECEIVER_H
#define RECEIVER_H

#include <QPointer>

#include "controller.h"

class QTcpSocket;
class DeviceMsg;
class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = Q_NULLPTR);
    virtual ~Receiver();

    void setControlSocket(QTcpSocket *controlSocket);
    void setController(Controller *cont);

public slots:
    void onReadyRead();

protected:
    void processMsg(DeviceMsg *deviceMsg);

private:
    QPointer<QTcpSocket> m_controlSocket;
    QPointer<Controller> m_controller;
};

#endif // RECEIVER_H
