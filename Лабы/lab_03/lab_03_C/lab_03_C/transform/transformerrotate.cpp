#include "transformerrotate.h"

TransformerRotate::TransformerRotate(const double &ox, const double &oy, const double &oz)
{
    Matrix<double> rotateXMatrix = {{1.,        0.,        0.,        0.},
                                    {0.,     cos(ox), -sin(ox),     0.},
                                    {0.,     sin(ox),  cos(ox),     0.},
                                    {0.,        0.,        0.,        1.}};

    Matrix<double> rotateYMatrix = {{ cos(oy), 0., sin(oy), 0.},
                                    {    0.,    1.,    0.,    0.},
                                    {-sin(oy), 0., cos(oy), 0.},
                                    {    0.,    0.,    0.,    1.}};

    Matrix<double> rotateZMatrix = {{ cos(oz), -sin(oz),     0.,        0.},
                                    { sin(oz),  cos(oz),     0.,        0.},
                                    {    0.,        0.,        1.,        0.},
                                    {    0.,        0.,        0.,        1.}};
    this->_matrix = rotateXMatrix * rotateYMatrix * rotateZMatrix;
}
