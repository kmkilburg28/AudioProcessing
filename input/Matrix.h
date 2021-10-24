#include <stdlib.h>
#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix {
private:
	unsigned int rows;
	unsigned int cols;
	T* M;

	void setSize(unsigned int rows, unsigned int cols) {
		this->freeMatrix();
		this->rows = rows;
		this->cols = cols;
	}

public:
	Matrix() {
		M = NULL;
	}
	Matrix(unsigned int rows, unsigned int cols) {
		M = NULL;
		this->setSize(rows, cols);
		this->createMatrix();
	}
	unsigned int getRows() const {
		return this->rows;
	}
	unsigned int getCols() const {
		return this->cols;
	}

	void createMatrix() {
		this->freeMatrix();
		M = (T*)malloc(sizeof(T) * (this->rows*this->cols));
	}
	void freeMatrix() {
		if (M != NULL) {
			free(M);
			M = NULL;
		}
	}
	T* at(unsigned int row, unsigned int col) const {
		return this->M + (row * this->cols + col);
	}
	void set(unsigned int row, unsigned int col, T value) {
		*this->at(row, col) = value;
	}

	const Matrix<T> operator*(const Matrix<T>& m2) {
		if (this->getCols() != m2.getRows()) {
			std::cout << "Incompatible matrix multiplication" << std::endl;
			exit(1);
		}
		Matrix<T> result = Matrix<T>(this->getRows(), m2.getCols());
		
		for (unsigned int row = 0; row < result.getRows(); ++row) {
			for (unsigned int col = 0; col < result.getCols(); ++col) {
				T* element = result.at(row, col);
				*element = Complex(0, 0);
				for (unsigned int pair = 0; pair < this->getCols(); ++pair) {
					*element += *(this->at(row, pair)) * *(m2.at(pair, col));
				}
			}
		}
		return result;
	}
	friend std::ostream& operator<<(std::ostream& out, const Matrix<T>& m) {
		for (unsigned int row = 0; row < m.rows; ++row) {
			for (unsigned int col = 0; col < m.cols; ++col) {
				T* element = m.at(row, col);
				std::cout << *element;
				if (col != m.cols-1)
					std::cout << ", ";
			}
			std::cout << "\n" << std::endl;
		}
		return out;
	}
};

#endif
