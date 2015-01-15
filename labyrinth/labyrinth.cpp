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

void findStart(int& x, int& y) {
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if (labyrinth[i][j] == 'o') {
				x = i;
				y = j;
				return;
			}
}

// findTreasure(x, y) == true <->
//          можем от (x, y) да достигнем до съкровището
bool findTreasure(int x, int y) {
	if (labyrinth[x][y] == '$') {
		// лесен хубав случай
		cout << "Намерихме съкровището на (" << x <<
				"," << y << ")!\n";
		return true;
	}
	if (labyrinth[x][y] == '*')
		// лесен лош случай
		return false;
	// стъпка надолу
	if (findTreasure(x + 1, y))
		return true;
	// стъпка нагоре
	if (findTreasure(x - 1, y))
		return true;
	// стъпка наляво
	if (findTreasure(x, y - 1))
		return true;
	// стъпка надясно
	if (findTreasure(x, y + 1))
		return true;
	return false;
}

int main() {
	readLabyrinth();
	printLabyrinth();
	int startx, starty;
	findStart(startx, starty);
	cout << "Започваме от " << "("
			<< startx << "," << starty << ")\n";
	cout << findTreasure(startx, starty) << endl;
	printLabyrinth();
	return 0;
}


