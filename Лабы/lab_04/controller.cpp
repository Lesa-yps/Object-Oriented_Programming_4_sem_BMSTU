#include "controller.h"

#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent), currentState(FREE)
{
    // Инициализация кабин с индексами 0 и 1
    cabine[0] = std::make_unique<Cabine>(0, this);
    cabine[1] = std::make_unique<Cabine>(1, this);
    for (int i = 0; i < 2; ++i) {
        currentFloor[i] = 0;
        currentDirection[i] = STAND;
    }
    for (int i = 0; i < FLOORS_AMOUNT; i++)
    {
        destinations[0][i] = false;
        destinations[1][i] = false;
    }
    QObject::connect(this, &Controller::cabineMoveUp, this, [this](int cabineIndex, int destFloor) {
        cabine[cabineIndex]->cabineMovesUp(destFloor);
    });
    QObject::connect(this, &Controller::cabineMoveDown, this, [this](int cabineIndex, int destFloor) {
        cabine[cabineIndex]->cabineMovesDown(destFloor);
    });
    for (int i = 0; i < 2; ++i) {
        QObject::connect(cabine[i].get(), &Cabine::cabineReachedDestinationFloor, this, &Controller::reachFloor);
    }
    QObject::connect(&cabine[0]->passFloorTimer, &QTimer::timeout, this, &Controller::checkCalls);
    QObject::connect(&cabine[1]->passFloorTimer, &QTimer::timeout, this, &Controller::checkCalls);

    QObject::connect(this, SIGNAL(pressButton(int)), &button, SLOT(ButtonDoPress(int)));
    QObject::connect(this, SIGNAL(unpressButton(int)), &button, SLOT(ButtonDoUnpress(int)));

    QObject::connect(&button, SIGNAL(buttonIsPress()), this, SLOT(checkCalls()));
    QObject::connect(&button, SIGNAL(buttonIsUnpress()), this, SLOT(checkCalls()));

    QObject::connect(this, SIGNAL(freeControllerSignal()), this, SLOT(freeControllerSlot()));

    //QObject::connect(&button, SIGNAL(buttonIsUnpress(int)), &door, SLOT(startOpening(int)));
    //QObject::connect(&door, SIGNAL(doorIsClosed()), this, SLOT(checkCalls()));
}

void Controller::controllerCall(int floor, int typeButton)
{
    currentState = BUSY;
    if (typeButton != FLOOR)
        destinations[typeButton - 1][floor - 1] = true;
    else
        chooseCabine(floor - 1);
    emit pressButton(floor - 1);
}

void Controller::chooseCabine(int floor)
{
    if ((currentFloor[0] <= floor && currentDirection[0] == UP) || (currentFloor[0] >= floor && currentDirection[0] == DOWN)\
        || (currentDirection[0] == STAND))
    {
        //qDebug("chooseCabine 1");
        destinations[0][floor] = true;
    }
    else if ((currentFloor[1] <= floor && currentDirection[1] == UP) || (currentFloor[1] >= floor && currentDirection[1] == DOWN)\
             || (currentDirection[1] == STAND))
    {
        //qDebug("chooseCabine 2");
        destinations[1][floor] = true;
    }
    else
    {
        int count1 = 0;
        for (int i = currentFloor[0]; i <= FLOORS_AMOUNT && i >= 0; i += currentDirection[0])
            if (destinations[0][i] == true)
                count1++;
        int count2 = 0;
        for (int i = currentFloor[1]; i <= FLOORS_AMOUNT && i >= 0; i += currentDirection[1])
            if (destinations[1][i] == true)
                count2++;
        if (count1 > count2)
            destinations[1][floor] = true;
        else
            destinations[0][floor] = true;
        //qDebug("chooseCabine 3 %d %d", count1, count2);
    }
}

void Controller::reachFloor(int floor, int numCabine)
{
    if (currentState != BUSY)
        return;
    currentState = REACH_FLOOR;
    currentFloor[numCabine] = floor;
    //qDebug("reachFloor %d %d %d", currentFloor[numCabine], numCabine, destinations[numCabine][floor]);
    destinations[numCabine][floor] = false;
    emit unpressButton(floor);
}

void Controller::checkCalls()
{
    currentState = CHECK;
    bool isNewFloorFound[2] = {false, false};
    for (int j = 0; j < 2; j++)
    {
        if (currentDirection[j] == UP)
        {
            for (int i = currentFloor[j]; i < FLOORS_AMOUNT - 1 && !isNewFloorFound[j]; i++)
                if (destinations[j][i])
                {
                    isNewFloorFound[j] = true;
                    currentFloor[j]++;
                    //qDebug("1 %d %d %d", currentFloor[j], i, j);
                    emit cabineMoveUp(j, i);
                }
            for (int i = currentFloor[j] - 1; i >= 0 && !isNewFloorFound[j]; i--)
                if (destinations[j][i])
                {
                    isNewFloorFound[j] = true;
                    currentFloor[j]--;
                    //qDebug("2 %d %d %d", currentFloor[j], i, j);
                    currentDirection[j] = DOWN;
                    emit cabineMoveDown(j, i);
                }
        }
        else
        {
            for (int i = currentFloor[j] - 1; i >= 0 && !isNewFloorFound[j]; i--)
                if (destinations[j][i])
                {
                    isNewFloorFound[j] = true;
                    currentFloor[j]--;
                    //qDebug("3 %d %d %d", currentFloor[j], i, j);
                    currentDirection[j] = DOWN;
                    emit cabineMoveDown(j, i);
                }
            for (int i = currentFloor[j]; i < FLOORS_AMOUNT - 1 && !isNewFloorFound[j]; i++)
                if (destinations[j][i])
                {
                    isNewFloorFound[j] = true;
                    currentFloor[j]++;
                    //qDebug("4 %d %d %d", currentFloor[j], i, j);
                    currentDirection[j] = UP;
                    emit cabineMoveUp(j, i);
                }
        }
        if (!isNewFloorFound[j])
            currentDirection[j] = STAND;
    }
    if (!isNewFloorFound[0] && !isNewFloorFound[1])
        freeControllerSignal();
    else
        currentState = BUSY;
}

void Controller::freeControllerSlot()
{
    if (currentState == FREE)
        return;
    currentState = FREE;
    emit finalMove();
}
