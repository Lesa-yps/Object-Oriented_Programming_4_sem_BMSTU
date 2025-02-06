#ifndef DEFINES_H
#define DEFINES_H

#define FLOOR_PASS_TIME 1000
#define OPEN_CLOSE_DOOR_TIME 1500
#define PASSENGER_TIME_SERVICE 4000

#define FLOORS_AMOUNT 10

#define START_FLOOR 1
#define NOT_EXIST_FLOOR -1000

enum direction
{
    DOWN = -1,
    STAND = 0,
    UP = 1
};

enum button
{
    FLOOR = 0,
    CABINE1 = 1,
    CABINE2 = 2
};

#endif // DEFINES_H
