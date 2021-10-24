#include "dft.h"
#include "../Complex.h"
#include "../Matrix.h"

Matrix<Complex> createIDFTMatrix(unsigned int size) {
	Matrix<Complex> matrix = createDFTMatrix(size);
	for (unsigned int row = 0; row < size; ++row) {
		for (unsigned int col = 0; col < size; ++col) {
			Complex conjugate = ~(*matrix.at(row, col));
			matrix.set(row, col, Complex(conjugate.a / size, conjugate.b / size));
		}
	}
	return matrix;
}

Matrix<Complex> IDFT(Matrix<Complex> inputVector) {
	unsigned int size = inputVector.getRows();
	Matrix<Complex> idftMatrix = createIDFTMatrix(size);
	Matrix<Complex> outputVector = idftMatrix * inputVector;
	idftMatrix.freeMatrix();
	return outputVector;
}