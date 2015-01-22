/*
 * struct.cpp
 *
 *  Created on: 22.01.2015 г.
 *      Author: trifon
 */

#include <iostream>
#include <cstring>
using namespace std;

int const MAX = 100;

struct Student;

Student* p = NULL;

struct Student {
	char name[MAX];
	int fn;
	double grade;
	int year;
};

struct Team {
	Student s1, s2;
	char name[MAX];
};

void printStudent(Student const& s) {
	cout << "Име:    " << s.name << endl;
	cout << "Ф№:     " << s.fn << endl;
	cout << "Оценка: " << s.grade << endl;
	// !!! s.grade += 1;
	cout << endl;
}

void printTeam(Team const& t) {
	cout << "Екип " << t.name << endl;
	cout << "---------------------------\n";
	cout << "Студент №1\n";
	printStudent(t.s1);
	cout << "Студент №2\n";
	printStudent(t.s2);
}

void testStruct() {
	cout << sizeof(char) << ' ' << sizeof(int) <<
			' ' << sizeof(double) << endl;
	cout << sizeof(Student) << endl;

	Student s1 = { "Иван Колев", 44444, 4.5 };
	cout << s1.name << endl;

	Student s2;
	s2 = s1;
	cout << s2.name << endl;

	Student s[10] = { s1, { "Петър Петров", 80000, 6 }};
	strcpy(s[1].name, "Георги Георгиев");
	for(int i = 0; i < 10; i++)
		cout << s[i].name << "->" << s[i].fn << endl;

	Team t = { s[1], { "Мария Иванова", 40000, 5.5 }, "GM" };
	cout << t.s1.name << endl;
	cout << t.name << endl;
	t.s2.grade += 0.5;

	printStudent(s1);
	printStudent(s[1]);
	// printStudent(s[1]);
	printStudent(t.s1);

	printTeam(t);
}

void readStudent(Student& s) {
	cout << "Име: ";
	cin.getline(s.name, MAX);
	cout << "Ф№: ";cin >> s.fn;
	cout << "Успех: ";cin >> s.grade;
}

int readStudents(Student s[]) {
	int n = 0;
	char more;
	do {
		cout << "Моля, въведете студент:\n";
		readStudent(s[n]);
		cout << "Още студенти?"; cin >> more;cin.get();
		n++;
	} while(more == 'y');
	return n;
}

void printStudentLine(Student const& s) {
	cout << s.fn << '\t' << s.grade << '\t' << s.name << '\n';
}

void printStudentTable(Student s[], int n) {
	cout << "\nФ№\tОценка\tИме\n";
	cout << "----------------------------------\n";
	for(int i = 0; i < n; i++)
		printStudentLine(s[i]);
}

double averageGrade(Student s[], int n) {
	double sum = 0;
	for(int i = 0; i < n; i++)
		sum += s[i].grade;
	return sum / n;
}

void sortStudents(Student s[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int mini = i;
		for(int j = i + 1; j < n; j++)
			if (s[j].fn < s[mini].fn)
				mini = j;
		Student tmp = s[i];
		s[i] = s[mini];
		s[mini] = tmp;
	}
}

void initializeView(Student s[], Student* ps[], int n) {
	for(int i = 0; i < n; i++)
		ps[i] = &s[i];
}

bool lessThanByFN(Student const& s1, Student const& s2) {
	return s1.fn < s2.fn;
}

bool lessThanByGrade(Student const& s1, Student const& s2) {
	return s1.grade < s2.grade;
}

bool lessThanByName(Student const& s1, Student const& s2) {
	return strcmp(s1.name, s2.name) < 0;
}

typedef bool (*CompareFunction)(Student const&, Student const&);

void sortStudentsView(Student* ps[], int n,
					  CompareFunction lessThan) {
	for(int i = 0; i < n - 1; i++) {
		int mini = i;
		for(int j = i + 1; j < n; j++)
			if (lessThan(*ps[j], *ps[mini]))
				mini = j;
		Student* tmp = ps[i];
		ps[i] = ps[mini];
		ps[mini] = tmp;
	}
}

void printStudentsView(Student* ps[], int n) {
	cout << "\nФ№\tОценка\tИме\n";
	cout << "----------------------------------\n";
	for(int i = 0; i < n; i++)
		printStudentLine(*ps[i]);
}

void testSusi() {
	Student susi[MAX];

	int nStudents = readStudents(susi);
	printStudentTable(susi, nStudents);
	cout << "Среден успех: " << averageGrade(susi, nStudents) << endl;
	// sortStudents(susi, nStudents);
	// printStudentTable(susi, nStudents);

	Student* susiSortedView[MAX];
	initializeView(susi, susiSortedView, nStudents);
	sortStudentsView(susiSortedView, nStudents, lessThanByFN);
	printStudentsView(susiSortedView, nStudents);
	sortStudentsView(susiSortedView, nStudents, lessThanByGrade);
	printStudentsView(susiSortedView, nStudents);
	sortStudentsView(susiSortedView, nStudents, lessThanByName);
	printStudentsView(susiSortedView, nStudents);
}

/*
struct Employee {
	char name[100];
	Employee boss;
};
*/

int main() {
	// testStruct();
	testSusi();
	return 0;
}
