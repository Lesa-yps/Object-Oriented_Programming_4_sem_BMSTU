#include "transformerscale.h"

TransformerScale::TransformerScale(const double &kx, const double &ky, const double &kz)
{
    this->_matrix = {{kx,  0.,  0., 0.},
                     { 0., ky,  0., 0.},
                     { 0.,  0., kz, 0.},
                     { 0.,  0.,  0., 1.}};
}
