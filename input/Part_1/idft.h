#include <math.h>
#include "../Complex.h"
#include "../Matrix.h"

#ifndef IDFT_H
#define IDFT_H

Matrix<Complex> createIDFTMatrix(unsigned int size);
Matrix<Complex> IDFT(Matrix<Complex> inputVector);

#endif
