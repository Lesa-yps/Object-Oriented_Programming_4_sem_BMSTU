#ifndef REDRAW_OBJ_H
#define REDRAW_OBJ_H

#include <math.h>
#include "const_struct.h"
#include "Graph_view.h"

// перерисовывает объект
error_t redraw_obj(const struct Thing &obj, const struct Graph_view &view);

#endif // REDRAW_OBJ_H
