
#include <math.h>
#include "Complex.h"

double roundDouble(double a) {
	const double EPSILON = 0.0000001;
	double roundA = round(a);
	return abs(roundA - a) < EPSILON ? roundA : a;
}

Complex getRoot(double angle) {
	double a = cos(angle);
	double b = sin(angle);
	return Complex(roundDouble(a), roundDouble(b));
}

Complex roundComplex(Complex a) {
	return Complex(roundDouble(a.a), roundDouble(a.b));
}