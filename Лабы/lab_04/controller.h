#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QVector>

#include "const.h"
#include "cabine.h"
#include "button.h"


class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);

public slots:
    void controllerCall(int floor, int typeButton);
    void reachFloor(int floor, int cabineIndex);
    void checkCalls();
    void freeControllerSlot();

signals:
    void finalMove();
    void freeControllerSignal();
    void cabineMoveUp(int cabineIndex, int destFloor);
    void cabineMoveDown(int cabineIndex, int destFloor);
    void cabineRequest(int floor);
    void pressButton(int floor);
    void unpressButton(int floor);

private:
    void chooseCabine(int floor);
    enum controllerState
    {
        FREE,
        BUSY,
        CHECK,
        REACH_FLOOR
    };
    bool destinations[2][FLOORS_AMOUNT];
    controllerState currentState;
    int currentFloor[2];
    int currentDirection[2];
    std::unique_ptr<Cabine> cabine[2];
    Button button;
};


#endif // CONTROLLER_H
