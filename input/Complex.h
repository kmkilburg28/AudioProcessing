#include "math.h"
#include "iostream"

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
	private:

	public:
	double a;
	double b;
	Complex() {
		this->a = 0;
		this->b = 0;
	}
	/**
	 * Create the complex number a + bi
	 * @param a The real coefficent of a Complex number
	 * @param b The imaginary coefficient of a Complex number
	 */
	Complex(double a, double b) {
		this->a = a;
		this->b = b;
	}

	Complex& operator+=(const Complex& c2) {
		this->a += c2.a;
		this->b += c2.b;
		return *this;
	}
	Complex& operator-=(const Complex& c2) {
		this->a -= c2.a;
		this->b -= c2.b;
		return *this;
	}
	Complex& operator*=(const Complex& c2) {
		double c1a = this->a;
		this->a =     c1a*c2.a - this->b*c2.b;
		this->b = this->b*c2.a +     c1a*c2.b;
		return *this;
	}
	Complex& operator/=(const Complex& c2) {
		double divisor = c2.a*c2.a + c2.b*c2.b;
		double c1a = this->a;
		this->a = (    c1a*c2.a - this->b*c2.b) / divisor;
		this->b = (this->b*c2.a +     c1a*c2.b) / divisor;
		return *this;
	}

	const Complex operator~() {
		Complex result = *this;
		result.b = -result.b;
		return result;
	}

	const Complex operator+(const Complex& c2) {
		Complex result = *this;
		result += c2;
		return result;
	}
	const Complex operator-(const Complex& c2) {
		Complex result = *this;
		result -= c2;
		return result;
	}
	const Complex operator*(const Complex& c2) {
		Complex result = *this;
		result *= c2;
		return result;
	}
	const Complex operator/(const Complex& c2) {
		Complex result = *this;
		result /= c2;
		return result;
	}
	
	friend std::ostream& operator<<(std::ostream& out, const Complex& complex) {
		std::cout << complex.a << " + " << complex.b << "i";
		return out;
	}
};

#endif
