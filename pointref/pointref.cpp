/*
 * pointref.cpp
 *
 *  Created on: 4.12.2014 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

int main() {
	int x = 3, y = 4;
	int *p = &x, *q = &y; // <-> int* p = &x; int* q = &y;

	cout << p << endl;
	cout << *p << endl;
	p = &y;
	cout << p << endl;
	cout << *p << endl;
	y = 10;
	cout << p << endl;
	cout << *p << endl;
	cout << *p++ << endl;
	cout << p << endl;
	cout << y << endl;
	/* !!! ЛОШО !!!
	long address = (long)p;
	cout << address << endl;
	p = (int*)(address - 2);
	cout << p << endl;
	cout << *p << endl;
	*/

	int a[5] = { 1, 2, 3, 4, 5 };
	p = a;
	*p = 10;
	cout << a[0] << endl;

	*a = 15;
	cout << a[0] << endl;

	cout << p[2] << endl;
	cout << *(p + 2) << endl;
	cout << 2[p] << endl;
	cout << *(2 + p) << endl;

	cout << a << endl;

	p++;
	cout << p << endl;
	cout << *p << endl;

	p+=2;
	cout << p << endl;
	cout << *p << endl;



	return 0;
}


