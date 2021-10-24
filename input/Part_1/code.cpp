#include <iostream>

#include "dft.h"
#include "idft.h"

#include "../Complex.h"
#include "../Matrix.h"

int main(int argc, char** argv) {
	unsigned int size = 4;
	Matrix<Complex> input = Matrix<Complex>(size, 1);
	for (unsigned int row = 0; row < input.getRows(); ++row) {
		input.set(row, 0, Complex(row, 1));
	}
	std::cout << input << std::endl;
	Matrix<Complex> output = DFT(input);
	std::cout << output << std::endl;
	Matrix<Complex> reverseInput = IDFT(output);
	std::cout << reverseInput << std::endl;

	reverseInput.freeMatrix();
	output.freeMatrix();
	input.freeMatrix();
	return 0;
}