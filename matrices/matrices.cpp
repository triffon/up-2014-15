/*
 * matrices.cpp
 *
 *  Created on: 27.11.2014 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

const int MAX = 100;

void testMatrices() {
	int a[MAX][MAX] = { 0 };

	int m, n;
	cout << "m, n = ";
	cin >> m >> n;

	for(int i = 0; i < m; i++)
		// i - номер на реда
		// въвеждане на i-ти ред
		for(int j = 0; j < n; j++) {
			// j - номер на стълба
			// въвежда j-ти елемент на i-ти ред
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}

	// обхождане на матрицата по редове
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			cout << a[i][j] << '\t';
		cout << endl;
	}

	/*
	// обхождане на матрицата по стълбове
	for(int j = 0; j < n; j++) {
		for(int i = 0; i < m; i++)
			cout << a[i][j] << '\t';
		cout << endl;
	}
	*/



	int columnSums[MAX] = { 0 };

	for(int j = 0; j < n; j++)
		for(int i = 0; i < m; i++)
			columnSums[j] += a[i][j];

	for(int j = 0; j < n; j++)
		cout << "sum[" << j << "] = " << columnSums[j] << endl;

	cout << "Суми по стълбове:" << endl;

	for(int j = 0; j < n; j++) {
		int sum = 0;
		for(int i = 0; i < m; i++)
			sum += a[i][j];
		cout << "sum[" << j << "] = " << sum << endl;
	}

	cout << "Суми по редове:" << endl;

	for(int i = 0; i < m; i++) {
		int sum = 0;
		for(int j = 0; j < n; j++)
			sum += a[i][j];
		cout << "sum[" << i << "] = " << sum << endl;
	}

	int x;
	cout << "x = "; cin >> x;

	for(int i = 0; i < m; i++) {
		// търсим x в реда a[i]
		int j = 0;
		while (j < n && a[i][j] != x)
			j++;
		// да - a[i][j] == x
		// не - j == n
		if (j < n)
			cout << x << " се среща в ред " << i << endl;
	}

	int j = 0, min = 1;
	while(j < n && min % 2 != 0) {
		min = a[0][j];
		for(int i = 1; i < m; i++)
			if (a[i][j] < min)
				min = a[i][j];
		// min е най-малкият елемент в стълб j
		j++;
	}
	// няма стълб с четен минимум - j == n
	// има стълб с четен минимум - min % 2 == 0
	if (min % 2 == 0)
		cout << "Има стълб с четен минимум: " << min << endl;
	else
		cout << "Няма стълб с четен минимум!" << endl;


	// транспонираме
	// обхождаме само ПОД главния диагонал
	// работи само за квадратна матрица
	// домашно: за правоъгълна
	for(int i = 0; i < m; i++)
		for(int j = 0; j < i; j++) {
		// for(int j = i + 1; j < n; j++) {
			int tmp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tmp;
		}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cout << a[i][j] << '\t';
		cout << endl;
	}
}

void diagonals() {
	int b[MAX][MAX] = { 0 };
	int n;
	cout << "n = "; cin >> n;
	int count = 1;

	// ...
	for(int i = 0; i < n; i++)
		// i е редът, от който започва диагоналът
		for(int j = 0; j <= i; j++)
			b[i-j][j] = count++;


	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << b[i][j] << '\t';
		cout << endl;
	}

}

int main() {
	// testMatrices();
	diagonals();
	return 0;
}


