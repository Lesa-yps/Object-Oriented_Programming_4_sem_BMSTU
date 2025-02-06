#ifndef BRAIN_H
#define BRAIN_H

#include <math.h>
#include "const_struct.h"
#include "struct_actions.h"
#include "work_with_file.h"

// перенос
void brain_move_obj(struct Thing &obj, const struct Move &move_data);

// масштабирование
error_t brain_scale_obj(struct Thing &obj, const struct Scale &scale_data);

// поворот
void brain_turn_obj(struct Thing &obj, const struct Turn &turn_data);

#endif // BRAIN_H
