#include "cabine.h"

#include <QDebug>
#include <QString>

Cabine::Cabine(int index, QObject *parent) : QObject(parent), ind(index)
{
    passFloorTimer.setSingleShot(true);
    currentState = STANDING_CLOSE;
    currentFloor = 0;
    QObject::connect(this, SIGNAL(cabineStop()), this, SLOT(cabineStandOpen()));
    QObject::connect(this, SIGNAL(openDoor(int, int)), &door, SLOT(startOpening(int, int)));
    QObject::connect(&door, SIGNAL(doorIsClosed()), this, SLOT(cabineStandClose()));
}

void Cabine::cabineMovesUp(int destFloor)
{
    if (currentState == STANDING_OPEN)
        return;
    currentState = MOVESUP;
    if (currentFloor != destFloor)
    {
        qDebug("Лифт №%d проезжает этаж №%d.", ind + 1, currentFloor + 1);
        //qDebug("UP %d", destFloor);
        currentFloor += 1;
        passFloorTimer.start(FLOOR_PASS_TIME);
    }
    else
        emit cabineStop();
}

void Cabine::cabineMovesDown(int destFloor)
{
    if (currentState == STANDING_OPEN)
        return;
    currentState = MOVESDOWN;
    if (currentFloor != destFloor)
    {
        qDebug("Лифт №%d проезжает этаж №%d.", ind + 1, currentFloor + 1);
        //qDebug("DOWN %d", destFloor);
        currentFloor -= 1;
        passFloorTimer.start(FLOOR_PASS_TIME);
    }
    else
        emit cabineStop();
}

void Cabine::cabineStandOpen()
{
    if (currentState == STANDING_OPEN)
        return;
    currentState = STANDING_OPEN;
    qDebug("Лифт №%d остановился на этаже №%d.", ind + 1, currentFloor + 1);
    emit openDoor(currentFloor, ind);
}

void Cabine::cabineStandClose()
{
    if (currentState == STANDING_CLOSE)
        return;
    currentState = STANDING_CLOSE;
    //qDebug("cabineStandClose");
    emit cabineReachedDestinationFloor(currentFloor, ind);
}
