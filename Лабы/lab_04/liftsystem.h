#ifndef LIFTSYSTEM_H
#define LIFTSYSTEM_H

#include <QObject>

#include "controller.h"

class LiftSystem : public QObject
{
    Q_OBJECT
public:
    explicit LiftSystem(QObject *parent = nullptr);

signals:
    void callLift(int floor, int typeButton);

public slots:
    void call(int floor, int typeButton);
    void finalWork();

private:
    enum liftSystemState
    {
        ENABLE,
        DISABLE
    };
    liftSystemState currentState;
    Controller controller;
};

#endif // LIFTSYSTEM_H
