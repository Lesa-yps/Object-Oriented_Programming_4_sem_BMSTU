#include "liftsystem.h"

#include <QDebug>

LiftSystem::LiftSystem(QObject *parent) : QObject(parent), currentState(DISABLE)
{
    QObject::connect(this, SIGNAL(callLift(int, int)), &controller, SLOT(controllerCall(int, int)));
    QObject::connect(&controller, SIGNAL(finalMove()), this, SLOT(finalWork()));
}

void LiftSystem::call(int floor, int typeButton)
{
    currentState = ENABLE;
    emit callLift(floor, typeButton);
}

void LiftSystem::finalWork()
{
    currentState = DISABLE;
}
