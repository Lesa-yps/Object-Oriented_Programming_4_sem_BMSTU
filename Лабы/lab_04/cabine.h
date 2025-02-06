#ifndef CABINE_H
#define CABINE_H

#include <QObject>
#include <QTimer>

#include "const.h"
#include "door.h"


class Cabine : public QObject
{
    Q_OBJECT

public:
    explicit Cabine(int index, QObject *parent = nullptr);
    QTimer passFloorTimer;

public slots:
    void cabineMovesUp(int destFloor);
    void cabineMovesDown(int destFloor);
    void cabineStandOpen();
    void cabineStandClose();

signals:
    void cabineReachedDestinationFloor(int floor, int cabineIndex);
    void cabineStop();
    void passingFloor();
    void openDoor(int floor, int cabineIndex);

private:
    enum cabineState
    {
        MOVESUP,
        MOVESDOWN,
        STANDING_OPEN,
        STANDING_CLOSE,
    };
    int currentFloor;
    int ind;
    cabineState currentState;
    Door door;
};


#endif // CABINE_H
