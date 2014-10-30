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

	cout.precision(20);
	cout << "sum = " << sum << endl;
	return 0;
}

int stranger_sum() {
	double x;
	int n;
	cout << "n = "; cin >> n;
	cout << "x = "; cin >> x;

	double sum = 0;
	double y = 1;
	for( int i = 0; i <= n; i++) {
		// y = y(i)
		sum += y;
		// трябва да променим y, така че y = y(i+1)
		y *= x / (i + 1);
	}

	cout.precision(20);
	cout << "sum = " << sum << endl;
	return 0;
}

int strangest_sum() {
	double x;
	int n;
	cout << "n = "; cin >> n;
	cout << "x = "; cin >> x;

	double sum = 0;
	double y = 1;
	long fact = 1;
	for( int i = 0; i <= n; i++) {
		sum += pow(x, i) / fact;
		// трябва да променим fact
		fact *= i + 1;
	}

	cout.precision(20);
	cout << "sum = " << sum << endl;
	return 0;
}

int weird_sum() {
	double x;
	int n;
	cout << "n = "; cin >> n;
	cout << "x = "; cin >> x;

	double sum = 1;
	double y = 1;
	for( int i = 1; i <= n; i++) {
		// y = y(i-1)
		// трябва да променим y, така че y = y(i)
		y *= x / i;
		sum += y;
	}

	cout.precision(20);
	cout << "sum = " << sum << endl;
	return 0;
}

int div3max() {
	int n;
	cout << "n = "; cin >> n;

//	int count = 0, max = n*n*n - 5*n - 8;
	int count = 0, max = -12; // f(1)
	for(int i = 1; i <= n; i++) {
		int x = n*n*n - 5*i*i*n - 8*i;
		if (x % 3 == 0)
			count++;
		if (x > max)
			max = x;
	}

	cout << "Броят на числата, кратни на 3 е " << count << endl;
	cout << "Максимумът е " << max << endl;

	return 0;
}

int factw() {
	int n;
	cout << "n = "; cin >> n;

	long fact = 1;
	int i = 2 ;
	while( i <= n ) {
		fact *= i;
		i++;
	}
	// i > n

	cout << n << "! = " << fact << endl;
	return 0;
}

int average() {
	int x = 1;
	int sum = 0, count = -1;
	while (x != 0) {
		cout << "Въведете число: ";cin >> x;
//		if (x != 0) {
		sum += x;
		count++;
//		}
	}

	/*
	cout << sum << endl;
	cout << count << endl;
	*/

	cout << "Средното аритметично е ";
	cout << (double)sum / count << endl;
	return 0;
}

int average_better() {
	int x = 1;
	int sum = 0, count = 0;
	while (cin) {
		cout << "Въведете число: ";cin >> x;
		if (cin) {
			sum += x;
			count++;
		}
	}

	cout << "Средното аритметично е ";
	cout << (double)sum / count << endl;
	return 0;
}

int weirdest_sum() {
	double x, eps;
	cout << "x = ";cin >> x;
	cout << "eps = "; cin >> eps;

	double sum = 0, y = 1;
	int i = 0;
	while (fabs(y) >= eps) {
		sum += y;
		y *= x / (i + 1);
		i++;
	}
	// fabs(y) < eps

	cout.precision(20);
	cout << "sum = " << sum << endl;
	return 0;
}

int first_digit() {
	int n;
	cout << "n = ";cin >> n;

	int d = n;
	while (d >= 10)
		d /= 10;
	// d < 10
	// d е първата цифра на първоначалното n

	cout << "Първата цифра на " << n << " е " << d << endl;

	return 0;
}

int digit5() {
	int n;
	cout << "n = ";cin >> n;

	int d = n;
	bool hasDigit5 = false;
	while (d != 0 && !hasDigit5) {
		// d % 10 е последната цифра на d
		if (d % 10 == 5)
			hasDigit5 = true;
		// изтриваме последната цифра на d
		d /= 10;
	}
	// d == 0 || hasDigit5

	cout << "В числото " << n;
	if (!hasDigit5)
		cout << " НЕ";
	cout << " се съдържа 5" << endl;
}

int digit5better() {
	int n;
	cout << "n = ";cin >> n;

	int d = n;
	while (d % 10 != 5 && d != 0)
		// изтриваме последната цифра на d
		d /= 10;

	// ДА: d % 10 == 5
	// НЕ: d == 0
	// d % 10 == 5 || d == 0

	cout << "В числото " << n;
	if (d == 0) // <-> d % 10 != 5
		cout << " НЕ";
	cout << " се съдържа 5" << endl;

	return 0;
}

int average_best() {
	int x;
	int sum = 0, count = -1;
	do {
		cout << "Въведете число: ";cin >> x;
		sum += x;
		count++;
	} while (x != 0);

	if (count > 0) {
		cout << "Средното аритметично е ";
		cout << (double)sum / count << endl;
	}
	return 0;
}

int div7() {
	int n;
	cout << "n = "; cin >> n;

	int i = 1;
	// int x = n*n*n - 5*i*i*n - 8*i;
	int x;
	do {
		x = n*n*n - 5*i*i*n - 8*i;
		i++;
	} while (x % 7 != 0 && i <= n);
	// ДА: x % 7 == 0;
	// НЕ: i > n

	if (x % 7 == 0)
		cout << "Има";
	else
		cout << "Няма";

	/* !!!
 	if (i > n)
		cout << "Няма";
	else
		cout << "Има";
	 */

	cout << " число, кратно на 7." << endl;
	return 0;
}

int prime() {
	int n;
	cout << "n = "; cin >> n;

	// искаме да проверим има ли делител на
	// n между 2 и n - 1
	int i = 2;
	while (n % i != 0 && i < n)
		i++;
	// ДА, ИМА ДЕЛИТЕЛ:  n % i == 0
	// НЕ, НЯМА ДЕЛИТЕЛ: i == n

	cout << n;
	if (i != n)
		cout << " НЕ";
	cout << " е просто" << endl;
	return 0;
}

int print_clock() {
	for(int hours = 0; hours < 24; hours++)
		for(int minutes = 0; minutes < 60; minutes++) {
			cout << hours << ':';
			cout << ((minutes < 10) ? "0" : "");
			cout << minutes << endl;
		}
	return 0;
}

int main() {
	/*
	fact();
	factw();
	*/
	/*
	strange_sum();
	stranger_sum();
	strangest_sum();
	weird_sum();
	*/
	//div3max();
	//average();
	//average_better();
	//weird_sum();
	//weirdest_sum();
	// first_digit();
	// digit5();
	// digit5better();
	// prime();
	print_clock();
	return 0;
}


