/*
 * add2.cpp
 *
 *  Created on: 2.10.2014 г.
 *      Author: trifon
 */


#include <iostream>
using namespace std;
int main() {
  int a, b = 100;
  // първо въвеждаме стойности
  cout << "a, b = "; cin >> a >> b;
  int c;
  c = a + b; // събираме числата
  cout << "a + b = " << c << endl;
  cout << a << " + " << b << " = " << c << endl;
  return 0;
}

