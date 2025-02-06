#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "Matrix.h"
#include <cmath>

// создать сущность-обёртку для матрицы (трансформаций)
class Transformer
{
public:
    ~Transformer() = default;
    Matrix<double> GetMatrix() const;

protected:
    Matrix<double> _matrix;
};

#endif //TRANSFORMER_H
