/*
 * functions.cpp
 *
 *  Created on: 6.11.2014 г.
 *      Author: trifon
 */

#include <cmath>
#include <iostream>
#include "functions.h"
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


double triarea(double x1, double y1, double x2, double y2,
				double x3, double y3) {
	double a = distance(x1, y1, x2, y2);
	double b = distance(x2, y2, x3, y3);
	double c = distance(x1, y1, x3, y3);
	return heron(a, b, c);
}
double distance(double x1, double y1, double x2, double y2) {
	return sqrt(square(x2-x1)+square(y2-y1));
}
double heron(double a, double b, double c) {
	double p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

double square(double x) {
	return x * x;
}

void testArea() {
	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << "S = " << triarea(x1, y1, x2, y2, x3, y3) << endl;
}

int f(int x) {
	x += 5;
	return x * 2;
}

int g(int x) {
	return x + 1;
}

int x = 10;

void askToIncrease(int delta) {
	cout << "Да увелича ли x с " << delta << "?";
	char c;
	cin >> c;
	if (c == 'y')
		x += delta;
}

int counter() {
	static int count = 0;
	count++;
	return count;
}

void mult2(int& k) {
	k *= 2;
}

void testVariables() {
	cout << f(g(x)) << endl;
	cout << x << endl;
	askToIncrease(3);
	cout << "x = " << x << endl;
	for(int i = 1; i <= 10; i++)
		cout << counter() << endl;
}

void myswap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void myswap(double& p, double& q) {
	double tmp = p;
	p = q;
	q = tmp;
}

void myswap(char& p, char& q) {
	char tmp = p;
	p = q;
	q = tmp;
}

/*
template <typename T>
void myswap(T& x, T& y) {
	T tmp = x;
	x = y;
	y = tmp;
}
*/

void ambiguous(char p) {
	cout << "Char: " << p << endl;
}

void ambiguous(double p) {
	cout << "Double: " << p << endl;
}


void testReferences() {
	cout << "x = " << x << endl;
	mult2(x);
	cout << "x = " << x << endl;

	int y = 18;
	cout << "y = " << y << endl;
	mult2(y);
	cout << "y = " << y << endl;

	// !!! mult2(3);
	mult2(y += 4);
	cout << "y = " << y << endl;

	int a = 3, b = 4, c = 5;
	cout << "a,b,c = " << a << ',' << b << ',' << c << endl;
	myswap(a, b);
	cout << "a,b,c = " << a << ',' << b << ',' << c << endl;
	myswap(a, c);
	cout << "a,b,c = " << a << ',' << b << ',' << c << endl;


	// double p = 1.2, q = 2.3, r = 3.4;
	char p = 'p', q = 'q', r = 'r';

	cout << "p,q,r = " << p << ',' << q << ',' << r << endl;
	myswap(p, q);
	cout << "p,q,r = " << p << ',' << q << ',' << r << endl;
	myswap(p, r);
	cout << "p,q,r = " << p << ',' << q << ',' << r << endl;

	ambiguous('a');
	ambiguous(1.2);
	// !!! ambiguous(65);
	ambiguous((char)65);
	ambiguous((double)65);
}

int main() {
	// printSquared(readNumber(1, 5+5));
	// testArea();
	// testVariables();
	testReferences();
	return 0;
}
