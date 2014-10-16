/*
 * vars.cpp
 *
 *  Created on: 9.10.2014 г.
 *      Author: trifon
 */

#include <iostream>
#include <cmath>

using namespace std;
int digits() {
	int a;
	cout << "a = "; cin >> a;
	bool digit = a >= 0 && a < 10;
	bool notDigit1 = !digit;
	bool notDigit2 = a < 0 || a >= 10;

	cout << "digit? " << digit << endl;
	cout << "not digit? (1) " << notDigit1 << endl;
	cout << "not digit? (2) " << notDigit2 << endl;

	bool primeDigit = a == 2 || a == 3 || a == 5 || a == 7;
	// цифра, която се дели на две или на три
	bool digit23 = digit && (a % 2 == 0 || a % 3 == 0);

	cout << "prime digit? " << primeDigit << endl;
	cout << "digit divisible by 2 or 3? " << digit23 << endl;
	return 0;
}

int chars() {
	char c;
	cout << "c = ";
	//cin >> c;
	c = cin.get();
	cout << "c = '" << c << "'" << endl;
	int code = c;
	cout << code << endl;
	// bool digit = code >= 48 && code <= 57;
	bool digit = c >= '0' && c <= '9';
	cout << "digit? " << digit << endl;
	return 0;
}

int floats() {
	// float f = 1e-10;
	double f = 1e-10;
	f = f / 1e100;
	cout << f << endl;

	// float g = 1.2;
	// double g = 1.2;
	// long double g = 1.2;
	float g = 1.2;
	g = g - 0.3;
	g = g - 0.3;
	g = g - 0.3;
	g = g - 0.3;
	bool b1 = g == 0;
	cout << g << endl;
	cout << "==0? " << b1 << endl;

	const double EPS = 1e-4;

	bool e1 = fabs(g) < EPS;
	cout << "<EPS? " << e1 << endl;


	cout << "---------" << endl;

	float h = 1.25;
	h = h - 0.25;
	h = h - 0.25;
	h = h - 0.25;
	h = h - 0.25;
	h = h - 0.25;
	bool b2 = h == 0;
	cout << h << endl;
	cout << "==0? " << b2 << endl;

	bool e2 = fabs(h) < EPS;
	cout << "<EPS? " << e2 << endl;

	return 0;
}

int conversions() {
	bool b = true;
	char c = 'A';
	cout << b + c << endl;
	cout << 2 + 3.7 << endl;
	cout << 5 / 3 << endl;
	double d = 5;
	cout << d / 3 << endl;
	cout << 5.0 / 3 << endl;
	cout << (double)5 / 3 << endl;

	cout << (char)69 << endl;

	cout << (int)5.123 << endl;

	cout << (bool)'A' << endl;
	cout << (bool)'\0' << endl;

	long egn = 9876543210;
	cout << egn << endl;

	short segn = egn;
	cout << segn << endl;

	unsigned short s1 = 50000;
	unsigned short s2 = s1 * 2;
	cout << s1 << ' ' << s2 << endl;

	// (cout << egn) > (segn << endl);
	cout << (egn > segn) << endl;
	return 0;
}

int main() {
	// digits();
	// chars();
	// floats();
	conversions();
	return 0;
}


