#include <math.h>
#include "../Complex.h"
#include "../Matrix.h"
#include "../ft_helper.h"

Matrix<Complex> IFFT(Matrix<Complex> inputVector) {
	unsigned int size = inputVector.getRows();
	if (size == 1) {
		Matrix<Complex> outputVector = Matrix<Complex>(1, 1);
		outputVector.set(0, 0, *inputVector.at(0, 0));
		return outputVector;
	}

	Matrix<Complex> inputEven = Matrix<Complex>(size / 2, 1);
	Matrix<Complex> inputOdd  = Matrix<Complex>(size / 2, 1);
	for (unsigned int row = 0; row < size/2; ++row) {
		inputEven.set(row, 0, *inputVector.at(2*row, 0));
		inputOdd.set(row, 0, *inputVector.at(2*row + 1, 0));
	}

	Matrix<Complex> outputEven = IFFT(inputEven);
	Matrix<Complex> outputOdd  = IFFT(inputOdd);
	inputEven.freeMatrix();
	inputOdd.freeMatrix();

	Matrix<Complex> outputVector = Matrix<Complex>(size, 1);
	double angle = 2*M_PI / size;
	Complex root = getRoot(angle);
	Complex weight = Complex(1, 0);
	for (unsigned int row = 0; row < size/2; ++row) {
		Complex weightedOdd = weight*(*outputOdd.at(row, 0));
		*outputVector.at(row, 0)          = roundComplex((Complex)(*outputEven.at(row, 0) + weightedOdd) / Complex(2, 0));
		*outputVector.at(row + size/2, 0) = roundComplex((Complex)(*outputEven.at(row, 0) - weightedOdd) / Complex(2, 0));
		weight *= root;
	}
	outputEven.freeMatrix();
	outputOdd.freeMatrix();
	return outputVector;
}
