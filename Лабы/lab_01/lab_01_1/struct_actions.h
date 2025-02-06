#ifndef STRUCT_ACTIONS_H
#define STRUCT_ACTIONS_H

#include "const_struct.h"

struct Move
{
    double coord_d[COUNT_COORDS];
};
struct Turn
{
    int central_point[COUNT_COORDS];
    double angle;
    int numb_coord;
};
struct Scale
{
    double coord_k[COUNT_COORDS];
    int central_point[COUNT_COORDS];
};

#endif // STRUCT_ACTIONS_H
