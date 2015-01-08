/*
 * pointref.cpp
 *
 *  Created on: 4.12.2014 г.
 *      Author: trifon
 */

#include <iostream>
#include <cstring>
using namespace std;

void testPointers() {
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

	cout << p[0] << ' ' << p[1] << endl;

}

char const* my_strchr(char const* p, char c) {
//	while (*p != c && *p != '\0')
	while (*p != c && *p) {
		// !!! *p = *p + 1;
		p = p + 1;
	}

	// *p == c -> да
	// *p == '\0' -> не
	return p ? p : NULL;
}

void test_strchr() {
	char s[] = "Hello, world!";
	char* s2 = s;
	cout << sizeof(s) << ' ' << sizeof(s2) << endl;
	cout << my_strchr(s2, 'r') << endl;
	cout << s2 << endl;
	if (!my_strchr(s, '?'))
		cout << "Не се среща '?'\n";
}

void testConstants() {
	int x = 5;
	int *p;
	p = &x;
	const int N = 100;
	// !!!const int N;
	// !!! int *const q;
	// !!! q = p;
	int *const q = p;
	*q = 10;
	cout << x << endl;
	int const* r = p;
	// !!! *r = 20;
	cout << *r << endl;
	// !!! p = r;
	/*
	 * ЛОШО!
	 *
	 * 	p = (int*)r;
	 *	*p = 30;
	 *	cout << x << endl;
	 *	*(int*)r = 20;
	 *	cout << x << endl;
	 *
	 */
	// !!! p = &N;
	r = &N;
	cout << *r << endl;
	int const* const s = &N;
	// !!! s++;
	// !!!! *s++;
	cout << *s << endl;
}

void printThis(void* p, char type[]) {
	/*
	switch(type) {
		case "int" :
		case "double" :
		case "char" :
	}*/
	if (strcmp(type, "int") == 0) {
		int* pi = (int*)p;
		cout << "Цяло число: " << *pi << endl;
	}
	else
	if (strcmp(type, "double") == 0) {
		double *pd = (double*)p;
		cout << "Дробно число: " << *pd << endl;
	}
	else
	if (strcmp(type, "char") == 0) {
		char* pc = (char*)p;
		cout << "Символ: " << *pc << endl;
	}
	else
		cerr << "Неизвестен тип!\n";
}

void testVoidStar() {
	int i = 1;
	double d = 1.2;
	char c = 'c';
	int* pi = &i;
	double* pd = &d;
	char* pc = &c;
	/*
	pi = pd;
	pd = pc;
	pc = pi;
	*/
	void* p;
	p = pi;
	cout << p << endl;
	p = pd;
	cout << p << endl;
	p = pc;
	cout << p << endl;
	printThis(pi, "integer");
	printThis(pi, "int");
	printThis(pd, "double");
	printThis(pc, "char");
}

void testReferences() {
	int a = 3;a++;
	cout << a << endl;
	int &b = a;b++;
	cout << a << endl;
	int const& c = b;
	// !!! c++;
	cout << a << endl;
	/*
	 * ЛОШО!
	 * ((int&)c)++;
	 * !!! ((int)c)++;
	 * ((int&)a)++;
	 * !!! ((int)a)++;
	 * cout << a << endl;
	 */
}

// !!!
int* returnPointerBad(int m) {
	int n = m * m;
	return &m;
}

int& returnReferenceBad(int m) {
	int n = m + m;
	return n;
	return m;
	// !!! return 3;
}

int& middle( int& x, int& y, int& z) {
	if (x <= y && y <= z || z <= y && y <= x)
		return y;
	if (y <= z && z <= x || x <= z && z <= y)
		return z;
	return x;
}

void testReturns() {
	// !!!
	int* p = returnPointerBad(3);
	// returnPointerBad(5);
	cout << *p << endl;

	int a = 10, b = 30, c = 20;
	middle(a, b, c) = 5;
	cout << a << ' ' << b << ' ' << c << endl;
}

char const* strdiff(char const* s1, char const* s2) {
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
		s1++;
		s2++;
	}
	// *s1 == '\0' || *s2 == '\0' (някой от низовете е свършил)
	// *s1 != *s2 (намираме първото различие)
	if (*s1 == *s2)
		// низовете са равни!
		return NULL;
	return s1;
}

int main() {
	// testPointers();
	// test_strchr();
	// testConstants();
	// testVoidStar();
	// testReferences();
	testReturns();
	cout << strdiff("Hello, world!", "Hello, C++!");
	return 0;
}


