/*
 * arrays.cpp
 *
 *  Created on: 13.11.2014 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

void testArrays() {
	const int MAX = 1000;

	int a[MAX] = { 0 }, n;

	do {
		cout << "n = ";cin >> n;
	} while (n <= 0 || n > MAX);
	// 0 < n <= MAX

	for(int i = 0; i < n; i++)
		cout << "a[" << i << "] = " << a[i] << endl;

	for(int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}

	for(int i = 0; i < n; i++)
		cout << "a[" << i << "] = " << a[i] << endl;
	// 1. Сумата на елементите в масива
	// 2. Да се въведе x и да се провери дали x се среща
	// в масива
	// 3. Да се провери дали масивът е растяща редица
}


int main() {
	testArrays();
}


