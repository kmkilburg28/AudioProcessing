#include <math.h>
#include "../Complex.h"
#include "../Matrix.h"

#ifndef DFT_H
#define DFT_H

Matrix<Complex> createDFTMatrix(unsigned int size);
Matrix<Complex> DFT(Matrix<Complex> inputVector);

#endif
