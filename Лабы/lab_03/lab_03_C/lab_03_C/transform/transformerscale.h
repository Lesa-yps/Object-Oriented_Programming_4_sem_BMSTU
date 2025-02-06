#ifndef TRANSFORMSCALE_H
#define TRANSFORMSCALE_H

#include "Transformer.h"

class TransformerScale: public Transformer
{
public:
    TransformerScale(const double &kx, const double &ky, const double &kz);
};

#endif // TRANSFORMSCALE_H
