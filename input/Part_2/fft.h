#include <math.h>
#include "../Complex.h"
#include "../Matrix.h"

#ifndef FFT_H
#define FFT_H

Matrix<Complex> FFT(Matrix<Complex> inputVector);
Matrix<Complex> FFT(double inputVector[], unsigned int size);

#endif
