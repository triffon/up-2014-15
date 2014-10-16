/*
 * control.cpp
 *
 *  Created on: 16.10.2014 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

int statements() {
	cout << "Hello" << ", world!"; // оператор от израз
	2+3; // оператор от израз
	int x = 5; // оператор за дефиниция
	x = 4.3;
	cout << x << endl;
	cout << (x = 5) << endl;
	int a, b, c;
	a = b = c = 10;
	a = (b = (c = 10));
	cout << a << ' ' << b << ' ' << c << endl;
	((a = b) = c) = 15;
	cout << a << ' ' << b << ' ' << c << endl;
	cout << ++a << endl;
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;

	++a += 5;
	cout << a << endl;

	// !!! a++ += 5;

	;;;;
	;;

	return 0;
}

int lineq() {
	double a, b;
	cout << "a = ";cin >> a;
	cout << "b = ";cin >> b;

	if (a == 0)
		// ако a == 0
		if (b == 0)
			// ако b == 0
			cout << "Всяко x е решение!" << endl;
		else
			// ако b != 0
			cout << "Никое x не е решение!" << endl;
	else {
		// ако a != 0
		double x = -b / a;
		cout << "Решението е " << x << endl;
	}

	return 0;
}

int main() {
	// statements();
	lineq();
	return 0;
}

