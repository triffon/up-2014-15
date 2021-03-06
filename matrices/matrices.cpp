/*
 * matrices.cpp
 *
 *  Created on: 27.11.2014 г.
 *      Author: trifon
 */

#include <iostream>
#include <cstring>
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
	int b[MAX][MAX] = { 0 }, c[MAX][MAX] = { 0 };
	int n;
	cout << "n = "; cin >> n;
	int count = 1;

	// ...
	for(int i = 0; i < n; i++)
		// i е редът, от който започва диагоналът
		for(int j = 0; j <= i; j++)
			b[i-j][j] = count++;

	for(int j = 1; j < n; j++)
		// j е колоната, от която започва диагоналът
		for(int i = n - 1; i >= j; i--)
			b[i][n-1-(i-j)] = count++;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << b[i][j] << '\t';
		cout << endl;
	}

	count = 1;

	// ...
	/*
	for(int j = n - 1; j >= 0; j--)
		// j е колоната, от която започва диагоналът
		for(int i = n - 1; i >= n - 1 - j / 2; i--)
			c[i][i+j-(n-1)] = count++;
			*/
	for(int j = n - 1; j >= 0; j--)
		// j е колоната, от която започва диагоналът
		for(int i = n - 1, k = j; i + k >= n - 1; i--, k--)
			c[i][k] = count++;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << c[i][j] << '\t';
		cout << endl;
	}
}

void printMatrix(int a[][MAX], int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			cout << a[i][j] << '\t';
		cout << endl;
	}
}

void readMatrix(int a[][MAX], int m, int n) {
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
}

void testMatrixFunctions() {
	int a[MAX][MAX];
	// ЛОШО! readMatrix((int (*)[10])a, 3, 3);
	readMatrix(a, 3, 3);
	printMatrix(a, 3, 3);
}

void readStringArray(char as[][MAX], int n) {
	for(int i = 0; i < n; i++) {
		cout << "as[" << i << "] = ";
		cin.getline(as[i], MAX);
	}
}

bool findWord(char as[][MAX], int n, char const* word) {
	int i = 0;
//	while (i < n && strcmp(as[i], word) != 0)
	while (i < n && strcmp(as[i], word))
		i++;
	// да - strcmp(as[i], word) == 0
	// не - i == n
	return i < n;
}

void testFindWord() {
	char as[MAX][MAX] = {0};
	char word[MAX] = {0};
	int n;
	cout << "n = "; cin >> n;
	cin.ignore();
	readStringArray(as, n);
	cout << "word = ";
	cin.getline(word, MAX);
	if (findWord(as, n, word))
		cout << "Среща се!\n";
	else
		cout << "Не се среща!\n";
}

// !!!double c[MAX][MAX] = { 0 };

// !!!! void multiplyMatrices(double a[m][n], double b[n][k], double c[m][k])
void multiplyMatrices(double a[][MAX],
					  double b[][MAX],
					  double c[][MAX],
					  int m, int n, int k) {
	// !!! int c[MAX][MAX];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < k; j++) {
			c[i][j] = 0;
			// Да сметнем c[i][j]
			for(int l = 0; l < n; l++)
				c[i][j] += a[i][l]*b[l][j];
		}
}

int main() {
	// testMatrices();
	// diagonals();
	// testMatrixFunctions();
	testFindWord();
	return 0;
}


