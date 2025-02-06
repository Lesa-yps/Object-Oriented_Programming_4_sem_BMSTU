#include "door.h"

#include <QDebug>

Door::Door(QObject *parent) : QObject(parent), currentState(CLOSED)
{
    openDoorTimer.setSingleShot(true);
    openStateDoorTimer.setSingleShot(true);
    closeDoorTimer.setSingleShot(true);
    QObject::connect(&openDoorTimer, SIGNAL(timeout()), this, SLOT(open()));
    QObject::connect(&openStateDoorTimer, SIGNAL(timeout()), this, SLOT(startClosing()));
    QObject::connect(&closeDoorTimer, SIGNAL(timeout()), this, SLOT(close()));
}

void Door::startOpening(int floor, int cabineIndex)
{
    if (currentState != CLOSED)
        return;
    currentState = OPENNING;
    currentfloor = floor;
    cabineInd = cabineIndex;
    qDebug("Двери лифта №%d на этаже №%d открываются...", cabineInd + 1, currentfloor + 1);
    openDoorTimer.start(OPEN_CLOSE_DOOR_TIME);
}

void Door::open()
{
    if (currentState != OPENNING)
        return;
    currentState = OPENED;
    qDebug("Двери лифта №%d на этаже №%d открылись. Пассажир может войти/выйти.", cabineInd + 1, currentfloor + 1);
    openStateDoorTimer.start(PASSENGER_TIME_SERVICE);
}


void Door::startClosing()
{
    if (currentState != OPENED)
        return;
    currentState = CLOSING;
    qDebug("Двери лифта №%d на этаже №%d закрываются...", cabineInd + 1, currentfloor + 1);
    closeDoorTimer.start(OPEN_CLOSE_DOOR_TIME);
}


void Door::close()
{
    if (currentState != CLOSING)
        return;
    currentState = CLOSED;
    qDebug("Двери лифта №%d на этаже №%d закрылись.", cabineInd + 1, currentfloor + 1);
    emit doorIsClosed();
}
