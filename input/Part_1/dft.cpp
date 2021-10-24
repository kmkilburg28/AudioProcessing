#include <math.h>
#include "../Complex.h"
#include "../Matrix.h"
#include "../ft_helper.h"

Matrix<Complex> createDFTMatrix(unsigned int size) {
	Matrix<Complex> matrix = Matrix<Complex>(size, size);

	double angle = -2*M_PI / size;
	for (unsigned int row = 0; row < size; ++row) {
		for (unsigned int col = 0; col < size; ++col) {
			unsigned int rootNum = (row * col) % size;
			Complex root = getRoot(rootNum*angle);
			matrix.set(row, col, root);
		}
	}
	return matrix;
}

Matrix<Complex> DFT(Matrix<Complex> inputVector) {
	unsigned int size = inputVector.getRows();
	Matrix<Complex> dftMatrix = createDFTMatrix(size);
	Matrix<Complex> outputVector = dftMatrix * inputVector;
	dftMatrix.freeMatrix();
	return outputVector;
}