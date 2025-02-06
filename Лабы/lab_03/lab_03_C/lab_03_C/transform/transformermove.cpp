#include "transformermove.h"

TransformerMove::TransformerMove(const double &dx, const double &dy, const double &dz)
{
    this->_matrix = {{ 1.,  0.,  0., 0.},
                    { 0.,  1.,  0., 0.},
                    { 0.,  0.,  1., 0.},
                    {dx, dy, dz, 1.}};
}
