#ifndef TRANSFORMERMOVE_H
#define TRANSFORMERMOVE_H

#include "Transformer.h"

class TransformerMove: public Transformer
{
public:
    TransformerMove(const double &dx, const double &dy, const double &dz);
};

#endif // TRANSFORMERMOVE_H
