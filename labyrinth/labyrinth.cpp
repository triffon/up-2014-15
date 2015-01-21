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
// задача за съществуване
bool findTreasure(int x, int y, int move) {
	cout << "Пробваме да стъпим на (" << x << "," << y << ")" << endl;
	if (x < 0 || y < 0 || x >= m || y >= n ||
			labyrinth[x][y] == '*' ||
			labyrinth[x][y] >= '0' && labyrinth[x][y] <= '9')
		// лесен лош случай
		return false;
	if (labyrinth[x][y] == '$') {
		// лесен хубав случай
		cout << "Намерихме съкровището на (" << x <<
				"," << y << ")!\n";
		cout << "Направихме " << move << " стъпки!\n";
		return true;
	}
	//labyrinth[x][y] = '"';
	labyrinth[x][y] = '0' + (move % 10);
	// стъпка надолу
	if (findTreasure(x + 1, y, move + 1))
		return true;
	// стъпка наляво
	if (findTreasure(x, y - 1, move + 1))
		return true;
	// стъпка надясно
	if (findTreasure(x, y + 1, move + 1))
		return true;
	// стъпка нагоре
	if (findTreasure(x - 1, y, move + 1))
		return true;
	labyrinth[x][y] = 'X';
	return false;
}

int countPaths = 0;

// findAllPathsToTreasure(x, y, move) == true <->
//          от (x, y) да намерим всички съкровища
void findAllPathsToTreasure(int x, int y, int move) {
	cout << "Пробваме да стъпим на (" << x << "," << y << ")" << endl;
	if (x < 0 || y < 0 || x >= m || y >= n ||
			labyrinth[x][y] == '*' ||
			labyrinth[x][y] >= '0' && labyrinth[x][y] <= '9')
		// лесен лош случай
		return;
	if (labyrinth[x][y] == '$') {
		// лесен хубав случай
		cout << "Намерихме съкровището на (" << x <<
				"," << y << ")!\n";
		cout << "Направихме " << move << " стъпки!\n";
		printLabyrinth();
		cout << "Натиснете <ENTER> за още..." << endl;
		cin.get();
		countPaths++;
		return;
	}
	//labyrinth[x][y] = '"';
	labyrinth[x][y] = '0' + (move % 10);
	// стъпка надолу
	findAllPathsToTreasure(x + 1, y, move + 1);
	// стъпка наляво
	findAllPathsToTreasure(x, y - 1, move + 1);
	// стъпка надясно
	findAllPathsToTreasure(x, y + 1, move + 1);
	// стъпка нагоре
	findAllPathsToTreasure(x - 1, y, move + 1);
	labyrinth[x][y] = 'X';
}

void findAllPathsToTreasure(int, int);
void multiplyNumbers(int, int);
void printNumbersFromTo(int, int);

void findAllPathsToTreasure(int startx, int starty) {
	findAllPathsToTreasure(startx, starty, 0);
}

int main() {
	readLabyrinth();
	printLabyrinth();
	int startx, starty;
	findStart(startx, starty);
	cout << "Започваме от " << "("
			<< startx << "," << starty << ")\n";
	// cout << findTreasure(startx, starty, 0) << endl;
	// printLabyrinth();
	findAllPathsToTreasure(startx, starty);
	cout << "Намерени " << countPaths << " пътя" << endl;

	void (*pointerToFunction)(int, int);
	pointerToFunction = findAllPathsToTreasure;
	// !!! pointerToFunction = readLabyrinth;
	return 0;
}


