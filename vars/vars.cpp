/*
 * vars.cpp
 *
 *  Created on: 9.10.2014 г.
 *      Author: trifon
 */

#include <iostream>
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



int main() {
	// digits();
	chars();
	return 0;
}


