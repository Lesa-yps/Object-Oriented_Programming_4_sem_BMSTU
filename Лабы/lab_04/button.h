#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>


class Button : public QObject
{
    Q_OBJECT

public:
    explicit Button(QObject *parent = nullptr);

signals:
    void buttonIsPress();
    void buttonIsUnpress();

public slots:
    void ButtonDoUnpress(int currentFloor);
    void ButtonDoPress(int currentFloor);

private:
    enum buttonState
    {
        PRESS,
        UNPRESS
    };
    buttonState currentState;
};

#endif // BUTTON_H
