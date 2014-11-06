/*
 * functions.cpp
 *
 *  Created on: 6.11.2014 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

double square(double);
bool stopProblem(int);

void printSquared(int n) {
	cout << "n = " << n << endl;
	cout << "n^2 = " << square(n) << endl;
	return;
}

int readNumber(int from, int to) {
	int n;
	do {
		cout << "n = "; cin >> n;
	} while (from > n || n > to);
	// from <= n && n <= to
	return n;
}

double square(double x) {
	return x * x;
}

int main() {
	printSquared(readNumber(1, 5+5));
	return 0;
}


