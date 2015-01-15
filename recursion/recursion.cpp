/*
 * recursion.cpp
 *
 *  Created on: 8.01.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

int fact_for(int n) {
	int result = 1;
	// result == 0!
	for(int i = 1; i != n; i++)
		// result == (i-1)!
		result *= i;
		// result == i!
	// result == i! && !(i != n) <->
	// result == i! && i == n <->
	// result == n!
	return result;
}

int fact(int n) {
	if (n == 0)
		return 1;
	return n * fact(n - 1);
}

double power(double x, int n) {
	if (n == 0)
		return 1;
	if (n > 0)
		return x * power(x, n - 1);
	return 1 / power(x, -n);
}

int gcd(int a, int b) {
	if (a == b)
		return a;
	if (a > b)
		return gcd(a - b, a);
	return gcd(a, b - a);
}

const int MAX = 100;
int F[MAX] = { 0 };

int fib(int n) {
	// cout << "Смятаме fib(" << n << ")" << endl;
	if (n == 0 || n == 1)
		return n;
	return fib(n-1) + fib(n-2);
}

int fib_memo(int n) {
	// cout << "Смятаме fib(" << n << ")" << endl;
	if (n == 0 || n == 1)
		return n;
	if (F[n] ==  0) // не сме го смятали преди
		// смятаме го, но си го записваме
		F[n] = fib_memo(n-1) + fib_memo(n-2);
	return F[n];
}

int fib_for(int n) {
	if (n == 0)
		return 0;
	int a = 0, b = 1;
	for(int i = 2; i <= n; i++) {
		// b = f(i-1), a = f(i-2)
		int c = a + b;
		a = b;
		b = c;
		// b = f(i), a = f(i-1)
	}
	return b;
}

/*
 * <израз> ::= <цифра> | (<израз><операция><израз>)
 * <цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
 * <операция> ::= + | - | * | /
 */

// след приключване на функцията calculate
// expr сочи СЛЕД края на израза
double calculate(char const*& expr) {
	if (*expr >= '0' && *expr <= '9') {
		double result = *expr - '0';
		expr++;
		return result;
	}

	expr++; // прескачаме (
	double left = calculate(expr);
	// expr сочи към операцията
	char op = *expr++;
	double right = calculate(expr);
	// expr сочи към ), прескачаме я
	expr++;
	switch (op) {
	case '+' : return left + right;
	case '-' : return left - right;
	case '*' : return left * right;
	case '/' : return left / right;
	default : return 0;
	}
}

/*
 * <израз> ::= <цифра> | (<израз><операция><израз>)
 * <цифра> ::= 0 | 1
 * <операция> ::= & | '|'
 */

// след приключване на функцията calculate
// expr сочи СЛЕД края на израза
bool calculateLogic(char const*& expr, bool skip) {
	if (*expr == '0' || *expr == '1')
		return *expr++ - '0';

	expr++; // прескачаме (
	bool left = calculateLogic(expr, skip);
	// expr сочи към операцията
	char op = *expr++;
	bool result = false;
	if (op == '&' && !left) {
		skip = true;
		result = false;
	}
	if (op == '|' && left) {
		skip = true;
		result = true;
	}
	bool right = calculateLogic(expr, skip);
	// expr сочи към ), прескачаме я
	expr++;
	if (!skip)
		switch (op) {
		case '&' : result = left && right; break;
		case '|' : result = left || right; break;
		}
	return result;
}


void testCalculate() {
	char expr[MAX];
	cin.getline(expr, MAX);
	char const* p = expr;
	cout << calculate(p);
}

void testCalculateLogic() {
	char expr[MAX];
	cin.getline(expr, MAX);
	char const* p = expr;
	cout << calculateLogic(p, false);
}

void testRecursion() {
	cout << fact(7) << endl;
	cout << fact_for(7) << endl;
	cout << power(2, 5) << endl;
	cout << power(5, -2) << endl;
	// !! cout << fact(-3) << endl;
	// !! cout << fact_for(-3) << endl;
	cout << gcd(30, 12) << endl;
	int n = 40;
	cout << fib_for(n) << endl;
	cout << fib_memo(n) << endl;
	cout << fib(n) << endl;
}

void readArray(int a[], int n) {
	if (n == 0)
		return;
	cin >> a[0];
	readArray(a + 1, n - 1);
}

void printArray(int a[], int n) {
	if (n == 0)
		cout << endl;
	else {
		cout << a[0] << ' ';
		printArray(a + 1, n - 1);
	}
}

int sumArray(int a[], int n) {
	if (n == 0)
		return 0;
	return a[0] + sumArray(a + 1, n - 1);
}

bool found(int a[], int n, int x) {
	if (n == 0)
		// лесният лош случай
		return false;
	if (a[0] == x)
		// лесният добър случай
		return true;
	return found(a + 1, n - 1, x);
}

bool foundBetter(int a[], int n, int x) {
	return n != 0 && (a[0] == x || foundBetter(a + 1, n - 1, x));
}

bool monotone(int a[], int n) {
	return n < 2 || (a[n - 1] >= a[n - 2] && monotone(a, n - 1));
}

int& my_min(int& x, int& y) {
	return x < y ? x : y;
}

void my_swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}

int& minArray(int a[], int n) {
	if (n == 1)
		return a[0];
	return my_min(a[0], minArray(a + 1, n - 1));
}

void selectionSort(int a[], int n) {
	if (n < 2)
		return;
	my_swap(a[0], minArray(a, n));
	selectionSort(a + 1, n - 1);
}

// разделяме масива a на две части относно pivot
// лява част: <pivot
// дясна част: >=pivot
// фукцията връща номера на последния елемент от лявата част
int split(int a[], int n, int pivot) {
	int i = 0, j = n - 1;
	while (i != j) {
		if (a[i] < pivot)
			// на мястото си е, минаваме напред
			i++;
		else
			// a[i] не си е на мястото!
			if (a[j] >= pivot)
				// на мястото си е, минаваме назад
				j--;
			else
				// a[i] и a[j] не са си на мястото!!!
				// разменяме ги тогава
				my_swap(a[i], a[j]);
	}
	// i == j
	if (a[i] < pivot)
		return i;
	return i - 1;
}

void quickSort(int a[], int n) {
	if (n < 2)
		return;
	// разделяме масива на две части относно оста a[0]
	int k = split(a + 1, n - 1, a[0]) + 1;
	// split връща последният елемент на лявата част
	// (т.е. последния от елементите <a[0])
	// разменяме оста с този последен елемент
	my_swap(a[0], a[k]);
	// сортираме лявата част
	quickSort(a, k);
	// сортираме дясната част
	quickSort(a + k + 1, n - k - 1);
}

void testRecursionArrays() {
	int a[MAX] = { 0 };
	int n;
	cout << "n = "; cin >> n;
	readArray(a, n);
	printArray(a, n);
	cout << "Sum = " << sumArray(a, n) << endl;
 	int x;
	cout << "x = ";cin >> x;
	cout << "Found x? " << found(a, n, x) << endl;
	cout << "Found x? " << foundBetter(a, n, x) << endl;
	cout << "Monotone? " << monotone(a, n) << endl;
	// selectionSort(a, n);
	quickSort(a, n);
	printArray(a, n);
	/*
	cout << "Different? " << different(a, n) << endl;
	*/
}

int main() {
	// testRecursion();
	// testCalculate();
	// testCalculateLogic();
	testRecursionArrays();
	return 0;
}


