#include <iostream>

#include "fft.h"
#include "ifft.h"

#include "../Complex.h"
#include "../Matrix.h"

int main(int argc, char** argv) {
	unsigned int size = 8;
	// double inputArray[] = {0, 0.7071, 1, 0.7071, 0, -0.7071, -1, -0.7071};
	double inputArray[] = {0, sqrt(2)/2, 1, sqrt(2)/2, 0, -sqrt(2)/2, -1, -sqrt(2)/2};
	std::cout << inputArray << std::endl;
	Matrix<Complex> output = FFT(inputArray, size);
	// double outputArray[] = {0, -4, 0, 0, 0, 0, 0, 4};
	// Matrix<Complex> output = Matrix<Complex>(size, 1);
	// for (unsigned int row = 0; row < output.getRows(); ++row) {
	// 	output.set(row, 0, Complex(0, outputArray[row]));
	// }
	std::cout << output << std::endl;
	Matrix<Complex> reverseInput = IFFT(output);
	std::cout << reverseInput << std::endl;

	reverseInput.freeMatrix();
	output.freeMatrix();
	// input.freeMatrix();
	return 0;
}