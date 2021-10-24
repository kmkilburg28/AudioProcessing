#include <math.h>
#include "../Complex.h"
#include "../Matrix.h"
#include "../ft_helper.h"

Matrix<Complex> FFT(Matrix<Complex> inputVector) {
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

	Matrix<Complex> outputEven = FFT(inputEven);
	Matrix<Complex> outputOdd  = FFT(inputOdd);
	inputEven.freeMatrix();
	inputOdd.freeMatrix();

	Matrix<Complex> outputVector = Matrix<Complex>(size, 1);
	double angle = -2*M_PI / size;
	Complex root = getRoot(angle);
	Complex weight = Complex(1, 0);
	for (unsigned int row = 0; row < size/2; ++row) {
		Complex weightedOdd = weight*(*outputOdd.at(row, 0));
		*outputVector.at(row, 0)          = roundComplex(*outputEven.at(row, 0) + weightedOdd);
		*outputVector.at(row + size/2, 0) = roundComplex(*outputEven.at(row, 0) - weightedOdd);
		weight *= root;
	}
	outputEven.freeMatrix();
	outputOdd.freeMatrix();
	return outputVector;
}

Matrix<Complex> FFT(double inputVector[], unsigned int size) {
	double inputArray[] = {0, sqrt(2)/2, 1, sqrt(2)/2, 0, -sqrt(2)/2, -1, -sqrt(2)/2};
	Matrix<Complex> input = Matrix<Complex>(size, 1);
	for (unsigned int row = 0; row < input.getRows(); ++row) {
		input.set(row, 0, Complex(inputArray[row], 0));
	}
	Matrix<Complex> output = FFT(input);
	input.freeMatrix();
	return output;
}
