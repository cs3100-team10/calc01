// approach 1 -- individual functions for operation

#include<cmath>

float add(float x, float y) {
	return x + y;
}

float subtract(float x, float y) {
	return x - y;
}

float multiply(float x, float y) {
	return x * y;
}

float divide(float x, float y) {
	return x / y;
}

float cosine(float x) {
	return cos(x);
}

float sine(float x) {
	return sin(x);
}

float tangent(float x) {
	return tan(x);
}

float arcCosine(float x) {
	return acos(x);
}

float arcSine(float x) {
	return asin(x);
}

float arcTan(float x) {
	return atan(x);
}

float exponential(float x) {
	return exp(x);
}

float naturalLog(float x) {
	return log(x);
}

float log(float x) {
	return log10(x);
}

float power(float x, float n) {
	return pow(x,n);
}

float squareRoot(float x) {
	return sqrt(x);
}

float cubeRoot(x) {
	return cbrt(x);
}

float factorial(x) {
	for (i = 0; i <= x; i++)
	
		if (i == 0) {
			fact = 1;
		}
		else {
			fact = fact * i;
		}
	return fact;
}