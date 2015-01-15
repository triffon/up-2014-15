/*
 * labyrinth.cpp
 *
 *  Created on: 15.01.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

const int MAX = 100;

char labyrinth[MAX][MAX];
int m, n;

void readLabyrinth() {
	cin >> m >> n;
	cin.ignore();
	for(int i = 0; i < m; i++)
		cin.getline(labyrinth[i], n + 2);
}

void printLabyrinth() {
	for(int i = 0; i < m; i++)
		cout << labyrinth[i] << endl;
}

int main() {
	readLabyrinth();
	printLabyrinth();
	return 0;
}


