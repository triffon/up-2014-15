/*
 * higherorder.cpp
 *
 *  Created on: 21.01.2015 г.
 *      Author: trifon
 */

#include <iostream>
#include <cmath>
using namespace std;

typedef int number;

void my_swap(number& x, number& y) {
	number tmp = x;
	x = y;
	y = tmp;
}

void testFunctionPointers() {
	void (*f)(number&, number&);
	f = my_swap;
	number x = 3, y = 5;
	// number x = 3.5, y = 5.3;
	// number x = 'A', y = 'B';
	cout << x << ' ' << y << endl;
	(*f)(x, y);
	cout << x << ' ' << y << endl;
	f(x, y);
	cout << x << ' ' << y << endl;

	// double (*op)(double) = sin;
	//  double (*op2)(double) = op;
	typedef double (*mathfun)(double);
	mathfun op = sin, op2 = cos;
	cout << op(0) << endl;
	op = cos;
	cout << op(0) << endl;
	op = NULL;
}

typedef int (*nextFunction)(int); // Например: plus1, mult2
typedef double (*termFunction)(double); // например: sin, cos, log, ...
typedef double (*operation)(double, double); // например: +, -, *, /, ...

double accumulate(operation op, // например: +, -, *, /, ...
				double base_value, // например: 0, 1
				int a, int b, // границите на интервала
				termFunction f, // например: sin, cos, log, ...
				nextFunction next) { // Например: plus1, mult2
	double result = base_value;
	for(int i = a; i <= b; i = next(i))
		/// !!! result op= f(i);
		// result = result + f(i);
		// result = result * f(i);
		// !!! result = result op f(i);
		result = op(result, f(i));
	return result;
}

int plus1(int n) { return n + 1; }
int plus2(int n) { return n + 2; }
int mult2(int n) { return n * 2; }

double my_plus(double x, double y) { return x + y; }
double my_mult(double x, double y) { return x * y; }

double id(double i) { return i; }

int fact(int n) {
	return accumulate(my_mult, 1, 1, n, id, plus1);
}

double expTerm(double i) {
	// връща общия i-ти член на сумата
	// приемаме x = 1
	return 1. / fact(i);
}

double X;

double expTerm2(double i) {
	// връща общия i-ти член на сумата
	return pow(X, i) / fact(i);
}


termFunction chooseFunction(int n) {
	switch (n) {
	case 1:return sin;
	case 2:return cos;
	case 3:return exp;
	case 4:return log;
	default: return id;
	}
}

void testAccumulate() {
	// !!! cout << accumulate(+, 0, 1, n, sin, plus1);
	int n = 10;
	cout << accumulate(my_plus, 0, 1, n, chooseFunction(1), plus1) << endl;
	cout << accumulate(my_plus, 0, 1, n, chooseFunction(2), mult2) << endl;
	cout << accumulate(my_mult, 1, 1, n, tan, plus2) << endl;
	// e^1
	cout << "X = "; cin >> X;
	cout << accumulate(my_plus, 0, 0, n, expTerm2, plus1) << endl;
}

termFunction F;

double fprime(double x) {
	const double DX = 1E-5;
	return (F(x + DX) - F(x)) / DX;
}

termFunction derive(termFunction f) {
	F = f; // лошо :(
	return fprime;
}

double square(double x) { return x * x; }

void testDerive() {
	termFunction sinPrime = derive(sin);
	cout << sinPrime(0) << endl;
	cout << derive(square)(10) << endl;
}

int main() {
	// testFunctionPointers();
	// testAccumulate();
	testDerive();
	return 0;
}

