#include "transformer.h"

Matrix<double> Transformer::GetMatrix() const
{
    return Matrix<double>(_matrix);
}
