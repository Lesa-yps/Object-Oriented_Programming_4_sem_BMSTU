#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "const_struct.h"
#include "struct_actions.h"
#include "Graph_view.h"
#include "redraw_obj.h"
#include "brain.h"
#include "work_with_file.h"
#include "init_obj.h"

// коды для менеджера задач
enum Activ
{
    START,
    LOAD,
    UPLOAD,
    TURN,
    SCALE,
    MOVE,
    QUIT,
    DRAW
};
// запрос менеджеру задач
struct Request
{
    enum Activ action;
    const char *filename;
    struct Graph_view view;
    union
    {
        struct Turn turn;
        struct Move move;
        struct Scale scale;
    };
};
typedef struct Request request_t;

// менеджер задач
error_t task_manager(const request_t &request);

#endif // TASK_MANAGER_H
