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
		double a = 10;
		double x = -b / a;
		cout << "Решението е " << x << endl;
	}
	// !!! cout << "Отново: решението е " << x << endl;

	cout << "a = " << a << endl;
	// double a = 5;

	return 0;
}

int numbers3() {
	int a, b, c;
	cout << "a, b, c = "; cin >> a >> b >> c;

	cout << "Числата ";

	/*
	if (b > a && c > b)
		;
	else
		cout << "НЕ ";
	 */

	if (b <= a || c <= b)
		cout << "НЕ ";
	cout << "образуват растяща редица." << endl;
	return 0;
}

int min3() {
	int a, b, c;
	cout << "a, b, c = "; cin >> a >> b >> c;
	int min = a;
	// за момента a е най-малкото число от тези,
	// които сме прегледали

	/*
	if (a <= b && a <= c)
		min = a;
	if (b <= a && b <= c)
		min = b;
	if (c <= a && c <= b)
		min = c;
	*/

	// преглеждаме b:
	if (b < min)
		// има по-малко число: b
		min = b;

	// до момента min е най-малкото число от a и от b

	// преглеждаме c:
	if (c < min)
		// има по-малко число: c
		min = c;

	// до момента min е най-малкото число от a, b, c

	cout << "Най-малкото число е " << min << endl;
	return 0;
}

int sort3() {
	int a, b, c;
	cout << "a, b, c = "; cin >> a >> b >> c;

	if (a > b) {
		int x = a;
		a = b;
		b = x;
	}
	// a <= b
	if (b > c) {
		int x = b;
		b = c;
		c = x;
	}
	// b <= c && (a <= b || a <= c)
	if (a > b) {
		int x = a;
		a = b;
		b = x;
	}
	// a <= b && b <= c
	// => a <= c

	cout << "a, b, c = " << a << ' ' << b << ' ' << c << endl;

	return 0;
}

int switching() {
	int x;
	cout << "x = "; cin >> x;
	switch (x) {
		case 1 : x++; break;
		case 2 : x += 2; break;
		default : x += 5;
	}
	cout << "x = " << x << endl;
}

int calculator() {
	int a, b;
	char op;
	bool error = false;
	cin >> a >> op >> b;
	int result = 0;
	switch (op) {
	case '+':result = a + b;break;
	case '-':result = a - b;break;
	case '*':result = a * b;break;
	case '/':result = a / b;break;
	case '%':result = a % b;break;
	/*
	 * !!!
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':cout << "Резултат: " << result << endl;
	*/
	default:cout << "Грешна операция!" << endl;
			error = true;
	}
	if (!error)
		cout << "Резултат: " << result << endl;
}

int main() {
	// statements();
	// lineq();
	// numbers3();
	// min3();
	// sort3();
	// switching();
	// calculator();
	return 0;
}

