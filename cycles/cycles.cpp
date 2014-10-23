/*
 * cycles.cpp
 *
 *  Created on: 23.10.2014 г.
 *      Author: trifon
 */

#include <iostream>
#include <cmath>
using namespace std;

int fact() {
	int n;
	cout << "n = "; cin >> n;

	long fact = 1;
	for( int i = 2 ; i <= n ; i++ )
		fact *= i;

	cout << n << "! = " << fact << endl;
	return 0;
}

int strange_sum() {
	double x;
	int n;
	cout << "n = "; cin >> n;
	cout << "x = "; cin >> x;

	double sum = 0;
	for( int i = 0; i <= n; i++) {

		long fact = 1;
		for( int j = 2 ; j <= i ; j++ )
			fact *= j;

		sum += pow(x, i) / fact;
	}

	cout << "sum = " << sum << endl;
}

int main() {
	// fact();
	strange_sum();
	return 0;
}


