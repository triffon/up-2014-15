/*
 * arrays.cpp
 *
 *  Created on: 13.11.2014 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

void testArrays() {
	const int MAX = 100;

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
	// задача за всяко
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];

	cout << "sum = " << sum << endl;

	// 2. Да се въведе x и да се провери дали x се среща
	// в масива
	// задача за съществуване

	int x;
	cout << "x = ";cin >> x;
	bool flag = false;
	for(int i = 0; i < n; i++)
		if (a[i] == x)
			flag = true;

	if (flag)
		cout << "Среща се" << endl;
	else
		cout << "Не се среща" << endl;

	int i = 0;
	while(i < n && a[i] != x)
		i++;

	// a[i] == x <-> среща се
	// i == n <-> не се среща

	if (i < n)
		cout << "Среща се" << endl;
	else
		cout << "Не се среща" << endl;

	// 3. Да се провери дали масивът е растяща редица
	int count = 0;
	for(int i = 0; i < n - 1; i++)
		if (a[i] < a[i+1])
			count++;

	if (count == n - 1)
		cout << "Растяща е" << endl;
	else
		cout << "Не е растяща" << endl;

	i = 0;
	while (i < n - 1 && a[i] < a[i+1])
		i++;
	// a[i] >= a[i+1] <-> не е растяща
	// i == n - 1 <-> е растяща

	if (i == n - 1)
		cout << "Растяща е" << endl;
	else
		cout << "Не е растяща" << endl;

}


int main() {
	testArrays();
}


