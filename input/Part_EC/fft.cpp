#include <math.h>
#include "../Complex.h"
#include "../Matrix.h"
#include "../ft_helper.h"

Matrix<Complex> FFT(Matrix<Complex> inputVector) {
	const unsigned int size = inputVector.getRows();
	const unsigned int max_depth = log2(size);

	Matrix<Complex> workVector = Matrix<Complex>(size, 1);
	for (int i = 0; i < size; ++i) {
		workVector.set(i, 0, *inputVector.at(i, 0));
	}
	Matrix<Complex> outputVector = Matrix<Complex>(size, 1);

	// Divide
	for (int splitSize = size; splitSize > 1; splitSize /= 2) {
		for (int split = 0; split < size/splitSize; ++split) {
			for (int splitInd = 0; splitInd < splitSize; ++splitInd) {
				int destInd = splitInd % splitSize/2;
				if (splitInd % 2 != 0) { // odd
					destInd += splitSize/2;
				}
				outputVector.set(split*splitSize+destInd, 0, *workVector.at(split*splitSize+splitInd, 0));
			}
		}
		for (int i = 0; i < size; ++i) {
			workVector.set(i, 0, *outputVector.at(i, 0));
		}
	}
	workVector.freeMatrix();

	// Conquer
	for (int splitSize = 2; splitSize <= size; splitSize *= 2) {
		double angle = -2*M_PI / splitSize;
		for (int split = 0; split < size/splitSize; ++split) {
			Complex root = getRoot(angle);
			Complex weight = Complex(1, 0);
			for (int splitInd = 0; splitInd < splitSize/2; ++splitInd) {
				int evenInd = split*splitSize+splitInd;
				int oddInd = evenInd+splitSize/2;

				Complex even = *outputVector.at(evenInd, 0);
				Complex odd  = *outputVector.at(oddInd, 0);
				Complex weightedOdd = weight*odd;
				
				outputVector.set(evenInd, 0, roundComplex(even + weightedOdd));
				outputVector.set(oddInd,  0, roundComplex(even - weightedOdd));
				weight *= root;
			}
		}
	}

	return outputVector;
}
