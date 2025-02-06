#include "button.h"

#include "QDebug"

Button::Button(QObject *parent) : QObject(parent), currentState(UNPRESS) { }

void Button::ButtonDoUnpress(int currentFloor)
{
    currentState = UNPRESS;
    qDebug("Кнопка этажа №%d погасла.", currentFloor + 1);
    emit buttonIsUnpress();
}

void Button::ButtonDoPress(int currentFloor)
{
    currentState = PRESS;
    qDebug("Кнопка этажа №%d загорелась.", currentFloor + 1);
    emit buttonIsPress();
}
