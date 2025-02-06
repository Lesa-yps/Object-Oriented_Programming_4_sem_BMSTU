#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QTimer>

#include "const.h"


class Door : public QObject
{
    Q_OBJECT

public:
    explicit Door(QObject *parent = nullptr);

signals:
    void doorIsClosed();

public slots:
    void startOpening(int floor, int cabineIndex);
    void startClosing();

private slots:
    void open();
    void close();

private:
    enum doorState
    {
        OPENED,
        OPENNING,
        CLOSED,
        CLOSING
    };
    int currentfloor;
    int cabineInd;
    QTimer openDoorTimer;
    QTimer closeDoorTimer;
    doorState currentState;
    QTimer openStateDoorTimer;
};


#endif // DOOR_H
