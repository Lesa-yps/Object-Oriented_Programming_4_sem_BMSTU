#ifndef WORK_WITH_FILE_H
#define WORK_WITH_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "const_struct.h"

// читает объект из файла
error_t load_obj(struct Thing &obj_start, const char *file_name);

// записывает данные об объекте в файл
error_t upload_obj(const struct Thing &obj, const char *file_name);

// освобождает память из-под объекта
void free_obj(struct Thing &obj);

#endif // WORK_WITH_FILE_H
